#include <sstream>
#include "stdafx.h"
#include "Tokenizer.h"
#include "CharacterLiteralToken.h"
#include "FloatLiteralToken.h"
#include "DoubleLiteralToken.h"
#include "IntegerLiteralToken.h"
#include "UIntegerLiteralToken.h"
#include "LongLiteralToken.h"
#include "ULongLiteralToken.h"
#include "IdentifierToken.h"
#include "StringLiteralToken.h"
#include "SymbolToken.h"
#include "ErrorToken.h"
#include "EndOfFileToken.h"

namespace flc
{
    namespace tokens
    {
        Tokenizer::Tokenizer()
        {
        }
        Tokenizer::~Tokenizer()
        {
        }

        vector<Token*>* Tokenizer::tokenize(istream *sourceFile, string path)
        {
            vector<Token*> *result = new vector<Token*>();
            int pos = 0;
            while (true)
            {
                Token *next = parseNextToken(sourceFile, pos, path);
                result->push_back(next);
                pos += next->getLength();
                if (next->isEndOfFile()) return result;
            }
        }

        inline bool Tokenizer::isWhiteSpace(char16_t c)
        {
            return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
        }
        inline bool Tokenizer::isOctal(char16_t c)
        {
            return (c >= '0' && c <= '7');
        }
        inline bool Tokenizer::isDecimal(char16_t c)
        {
            return (c >= '0' && c <= '9');
        }
        inline bool Tokenizer::isHexadecimal(char16_t c)
        {
            return (c >= '0' && c <= '9' || c >= 'A' && c <= 'F' || c >= 'a' && c <= 'f');
        }
        inline bool Tokenizer::isAlphanumeric(char16_t c)
        {
            return (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == '_');
        }

        char16_t Tokenizer::escapeSequenceToChar(istream *source, int *length)
        {
            char16_t result;
            char16_t nextChar = (char16_t)source->get();
            if (source->eof())
            {
                return (char16_t)EOF;
            }

            stringstream subNum;
            switch (nextChar)
            {
            case 'a':
                result = '\x07';
                (*length)++;
                break;
            case 'b':
                result = '\x08';
                (*length)++;
                break;
            case 'f':
                result = '\x0C';
                (*length)++;
                break;
            case 'n':
                result = '\x0A';
                (*length)++;
                break;
            case 'r':
                result = '\x0D';
                (*length)++;
                break;
            case 't':
                result = '\x09';
                (*length)++;
                break;
            case 'v':
                result = '\x0b';
                (*length)++;
                break;
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
                subNum << (char)nextChar;
                for (int i = 0; i < 5; i++)
                {
                    if (!isOctal((char16_t)source->peek()))
                    {
                        break;
                    }
                    subNum << (char)source->get();
                    (*length)++;
                }
                //TODO: return error token if invalid character value
                result = (char16_t)stoi(subNum.str(), nullptr, 8);
                break;
            case 'x':
                int q;
                for (q = 0; q < 4; q++)
                {
                    if (!isHexadecimal((char16_t)source->peek()))
                    {
                        break;
                    }
                    subNum << (char)source->get();
                    (*length)++;
                }
                if (q == 0)
                {
                    //TODO: return error token
                }
                result = (char16_t)stoi(subNum.str(), nullptr, 16);
                break;
            case 'u':
            case 'U':
                // non-ascii encodings not implemented yet
                result = (char16_t)EOF;
                break;
            default:
                result = nextChar;
                (*length)++;
                break;
            }
            return result;
        }

        Token* Tokenizer::parseNextToken(istream *source, int& index, string path)
        {
            while (isWhiteSpace((char16_t)source->peek()) || parseComment(source))
            {
                index++;
                source->ignore();
            }
            if (source->eof())
            {
                return new EndOfFileToken(path, index);
            }

            auto nextChar = (char16_t)source->peek();
            if (nextChar == '\'') return parseCharacterToken(source, index, path);
            else if (nextChar == '"') return parseStringToken(source, index, path);
            else if (isDecimal(nextChar)) return parseNumericToken(source, index, path);
            else if (nextChar == '.')
            {
                source->get();
                nextChar = (char16_t)source->peek();
                source->seekg(-1, ios_base::cur);
                if (isDecimal(nextChar)) return parseNumericToken(source, index, path);
            }
            else if (isAlphanumeric(nextChar) && !isDecimal(nextChar)) return parseIdentifierToken(source, index, path);
            return parseSymbolToken(source, index, path);
        }

        Token* Tokenizer::parseCharacterToken(istream *source, int& index, string path)
        {
            source->ignore();
            if (source->eof())
                return new ErrorToken(path, index, 1, "EOF while parsing char literal");

            auto nextChar = (char16_t)source->get();
            int length = 2;
            char16_t c;
            if (nextChar == '\\')
            {
                c = escapeSequenceToChar(source, &length);
            }
            else if (nextChar == '\r' || nextChar == '\n')
            {
                return new ErrorToken(path, index, length, "Line cannot end in character literal");
            }
            else
            {
                c = nextChar;
            }

            if (source->eof())
            {
                return new ErrorToken(path, index, length, "EOF while parsing char literal");
            }
            else if (source->peek() != '\'')
            {
                return new ErrorToken(path, index, length, "Invalid char literal");
            }
            else
            {
                source->ignore();
                return new CharacterLiteralToken(path, index, length + 1, c);
            }
        }
        Token* Tokenizer::parseNumericToken(istream *source, int& index, string path)
        {
            stringstream numberString;
            int length = 0, base = 10;
            bool isFloatingPoint = false, forceInt = false, isSigned = true, isLong = false;
            char16_t nextChar;
            nextChar = (char16_t)source->peek();
            if (nextChar == '0')
            {
                numberString << (char)nextChar;
                source->get();
                nextChar = (char16_t)source->peek();
                if (nextChar == 'b' || nextChar == 'B')
                {
                    source->get();
                    if (!parseBinaryIntegerLiteral(source, &numberString))
                    {
                        //TODO: Error token
                        source->seekg(-2, ios_base::cur);
                        return nullptr;
                    }
                    forceInt = true;
                    base = 2;
                }
                else if (nextChar == 'o' || nextChar == 'O')
                {
                    source->get();
                    if (!parseOctalIntegerLiteral(source, &numberString))
                    {
                        //TODO: Error token
                        source->seekg(-2, ios_base::cur);
                        return nullptr;
                    }
                    forceInt = true;
                    base = 8;
                }
                else if (nextChar == 'x' || nextChar == 'X')
                {
                    source->get();
                    if (!parseHexIntegerLiteral(source, &numberString))
                    {
                        //TODO: Error token
                        source->seekg(-2, ios_base::cur);
                        return nullptr;
                    }
                    forceInt = true;
                    base = 16;
                }
                else if (isDecimal(nextChar))
                {
                    //TODO: Error token
                    source->seekg(-1, ios_base::cur);
                    return nullptr;
                }
            }
            else while (!source->eof())
            {
                nextChar = (char16_t)source->peek();
                if (!nextChar) break;
                else if ((nextChar != '.' || isFloatingPoint) && !isDecimal(nextChar)) break;
                else if (nextChar == '.' && !isFloatingPoint) isFloatingPoint = true;
                source->get(); //Consume character, since we are using it
                numberString << (char)nextChar;
                length++;
            }
            nextChar = (char16_t)source->peek();
            if (!forceInt && (nextChar == 'f' || nextChar == 'F' || nextChar == 'd' || nextChar == 'D'))
            {
                isLong = (nextChar == 'f' || nextChar == 'F');
                isFloatingPoint = true;
                source->get();
                nextChar = (char16_t)source->peek();
            }
            else if (!isFloatingPoint)
            {
                if (nextChar == 'u' || nextChar == 'U')
                {
                    forceInt = true;
                    isSigned = false;
                    source->get();
                    nextChar = (char16_t)source->peek();
                }
                if (nextChar == 'l' || nextChar == 'L')
                {
                    forceInt = true;
                    isLong = true;
                    source->get();
                    nextChar = (char16_t)source->peek();
                }
            }
            if (isFloatingPoint)
            {
                isLong = !isLong;
                if (isLong) return new DoubleLiteralToken(path, index, length, stod(numberString.str()));
                return new FloatLiteralToken(path, index, length, stof(numberString.str()));
            }
            else
            {
                if (isSigned && !isLong) return new IntegerLiteralToken(path, index, length, (int32_t)stoi(numberString.str(), nullptr, base));
                else if (isSigned && isLong) return new LongLiteralToken(path, index, length, (int64_t)stoll(numberString.str(), nullptr, base));
                else if (!isSigned && !isLong) return new UIntegerLiteralToken(path, index, length, (uint32_t)std::stoull(numberString.str(), nullptr, base));
                else return new ULongLiteralToken(path, index, length, (uint64_t)stoull(numberString.str(), nullptr, base));
            }
        }
        Token* Tokenizer::parseStringToken(istream *source, int& index, string path)
        {
            source->ignore();
            stringstream result;
            int length = 1;
            char16_t nextChar, c;
            while (!source->eof())
            {
                nextChar = (char16_t)source->get();
                if (nextChar == '"')
                {
                    length++;
                    break;
                }
                else if (nextChar == '\\')
                {
                    c = escapeSequenceToChar(source, &length);
                }
                else if (nextChar == '\r' || nextChar == '\n')
                {
                    return new ErrorToken(path, index, length, "Line cannot end in string literal");
                }
                else
                {
                    c = nextChar;
                    length++;
                }
                result << (char)c;
            }
            if (source->eof())
            {
                return new ErrorToken(path, index, length, "EOF while parsing string literal");
            }
            else
            {
                return new StringLiteralToken(path, index, length, result.str());
            }
        }
        Token* Tokenizer::parseIdentifierToken(istream *source, int& index, string path)
        {
            stringstream identString;
            int length = 0;
            char16_t nextChar;
            while (!source->eof())
            {
                nextChar = (char16_t)source->peek();
                if (!nextChar || !isAlphanumeric(nextChar)) break;
                identString << (char)nextChar;
                source->get();
                length++;
            }
            return IdentifierToken::getToken(path, index, length, identString.str());
        }
        Token* Tokenizer::parseSymbolToken(istream *source, int& index, string path)
        {
            // Very basic symbols only until syntax is better defined
            char16_t nextChar = (char16_t)source->get();
            stringstream stream;

            if (nextChar == ',' || nextChar == '{' || nextChar == '}' || nextChar == ')' || nextChar == '~' || nextChar == '[' || nextChar == ']')
            {
                // ,  {  }  )  ~  [  ]
                stream << (char)nextChar;
            }
            else if (nextChar == ':')
            {
                // :  ::  :::
                stream << (char)nextChar;
                if (source->peek() == ':') { stream << (char)source->get(); }
                if (source->peek() == ':') { stream << (char)source->get(); }
            }
            else if (nextChar == '(')
            {
                // (  (?
                stream << (char)nextChar;
                if (source->peek() == '?') { stream << (char)source->get(); }
            }
            else if (nextChar == '|' || nextChar == '&' || nextChar == '+' || nextChar == '-')
            {
                // |  ||  |=  &  &&  &=  +  ++  +=  -  --  -=
                stream << (char)nextChar;
                if (source->peek() == nextChar) { stream << (char)source->get(); }
                else if (source->peek() == '=') { stream << (char)source->get(); }
            }
            else if (nextChar == '.' || nextChar == '?')
            {
                // ?  ??  .  ..
                stream << (char)nextChar;
                if (source->peek() == nextChar) { stream << (char)source->get(); }
            }
            else if (nextChar == '<')
            {
                // <  <<  <=  <<=
                stream << (char)nextChar;
                if (source->peek() == nextChar) { stream << (char)source->get(); }
                if (source->peek() == '=') { stream << (char)source->get(); }
            }
            else if (nextChar == '*' || nextChar == '/' || nextChar == '%' || nextChar == '^' || nextChar == '>' || nextChar == '!')
            {
                // *  *=  /  /=  %  %=  ^  ^=  >  >=  !  !=
                stream << (char)nextChar;
                if (source->peek() == '=') { stream << (char)source->get(); }
            }
            else if (nextChar == '=')
            {
                // =  ==  =>
                stream << (char)nextChar;
                if (source->peek() == nextChar) { stream << (char)source->get(); }
                else if (source->peek() == '>') { stream << (char)source->get(); }
            }
            else return new ErrorToken(path, index, 1, "Unknown symbol");

            return new SymbolToken(path, index, stream.str());
        }

        //TODO: Keep comments, add to tokens
        bool Tokenizer::parseComment(istream *source)
        {
            auto nextChar = source->peek();
            if (nextChar != '/') return false;
            source->get();

            nextChar = source->peek();
            if (nextChar == '/')
            {
                source->get();
                while (true)
                {
                    nextChar = source->get();
                    if (nextChar == -1) break;
                    else if (nextChar == '\r')
                    {
                        if (source->peek() == '\n') source->get();
                        break;
                    }
                    else if (nextChar == '\n') break;
                }
            }
            else if (nextChar == '*')
            {
                source->get();
                while (true)
                {
                    nextChar = source->get();
                    if (nextChar == -1) break; //TODO: error ?
                    else if (nextChar == '*' && source->peek() == '/')
                    {
                        source->get();
                        break;
                    }
                }
            }
            else
            {
                source->seekg(-1, ios_base::cur);
                return false;
            }
            return true;
        }
        bool Tokenizer::parseBinaryIntegerLiteral(istream *source, stringstream *numberString)
        {
            auto nextChar = source->peek();
            if (nextChar != '0' && nextChar != '1') return false;
            while (true)
            {
                nextChar = source->peek();
                if (nextChar != '0' && nextChar != '1') break;
                source->get(); //Consume character
                *numberString << (char)nextChar;
            }
            return true;
        }
        bool Tokenizer::parseOctalIntegerLiteral(istream *source, stringstream *numberString)
        {
            auto nextChar = source->peek();
            if (!isOctal((char16_t)nextChar)) return false;
            while (true)
            {
                nextChar = source->peek();
                if (!isOctal((char16_t)nextChar)) break;
                source->get(); //Consume character
                *numberString << (char)nextChar;
            }
            return true;
        }
        bool Tokenizer::parseHexIntegerLiteral(istream *source, stringstream *numberString)
        {
            auto nextChar = source->peek();
            if (!isHexadecimal((char16_t)nextChar)) return false;
            while (true)
            {
                nextChar = source->peek();
                if (!isHexadecimal((char16_t)nextChar)) break;
                source->get(); //Consume character
                *numberString << (char)nextChar;
            }
            return true;
        }
    }
}
