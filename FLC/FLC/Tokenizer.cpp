#include <sstream>
#include "stdafx.h"
#include "Tokenizer.h"
#include "CharacterLiteralToken.h"
#include "FloatLiteralToken.h"
#include "IntegerLiteralToken.h"
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
                //if (sourceFile->eof()) return result;
                if (next->isEndOfFile()) return result;
			}
		}
		
		bool Tokenizer::isWhiteSpace(char16_t c) {
			return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
		}
		bool Tokenizer::isOctal(char16_t c) {
			return (c >= '0' && c <= '7');
		}
		bool Tokenizer::isDecimal(char16_t c) {
			return (c >= '0' && c <= '9');
		}
		bool Tokenizer::isHexadecimal(char16_t c) {
			return (c >= '0' && c <= '9' || c >= 'A' && c <= 'F' || c >= 'a' && c <= 'f');
		}
		bool Tokenizer::isAlphanumeric(char16_t c) {
			return (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == '_');
		}

        char16_t Tokenizer::escapeSequenceToChar(istream *source, int *length) {
            char16_t result;
            char16_t nextChar = source->get();
			if (source->eof()) {
				return EOF;
			}

			stringstream subNum;
			switch (nextChar) {
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
                subNum << nextChar;
                for (int i = 0; i < 5; i++) {
                    if (!isOctal(source->peek())) {
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
				for (q = 0; q < 4; q++) {
					if (!isHexadecimal(source->peek())) {
						break;
					}
					subNum << (char16_t)source->get();
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
				result = EOF;
				break;
			default:
				result = nextChar;
				(*length)++;
				break;
			}
			return result;
		}

		Token* Tokenizer::parseNextToken(istream *source, int& index, string path) {
			while (isWhiteSpace(source->peek())) {
				index++;
                source->ignore();
			}
			if (source->eof()) {
				return new EndOfFileToken(path, index);
			}

            char16_t nextChar = source->peek();
			if (nextChar == '\'') {
				return parseCharacterToken(source, index, path);
			}
			else if (nextChar == '"') {
				return parseStringToken(source, index, path);
			}
			else if (isDecimal(nextChar)) {
				return parseNumericToken(source, index, path);
			}
			else if (isAlphanumeric(nextChar) && !isDecimal(nextChar)) {
				return parseIdentifierToken(source, index, path);
			}
			else {
				return parseSymbolToken(source, index, path);
			}
		}

		Token* Tokenizer::parseCharacterToken(istream *source, int& index, string path) {
			source->ignore();
			if (source->eof())
				return new ErrorToken(path, index, 1, "EOF while parsing char literal");

            char16_t nextChar = source->get();
			int length = 2;
            char16_t c;
			if (nextChar == '\\') {
				c = escapeSequenceToChar(source, &length);
			}
            else if (nextChar == '\r' || nextChar == '\n') {
                return new ErrorToken(path, index, length, "Line cannot end in character literal");
            }
			else {
				c = nextChar;
			}

			if (source->eof()) {
				return new ErrorToken(path, index, length, "EOF while parsing char literal");
			}
			else if (source->peek() != '\'') {
				return new ErrorToken(path, index, length, "Invalid char literal");
			}
			else {
				source->ignore();
				return new CharacterLiteralToken(path, index, length+1, c);
			}
		}
		Token* Tokenizer::parseNumericToken(istream *source, int& index, string path) {
			stringstream numberString;
			int length = 0;
			bool foundDecimal = false;
            char16_t nextChar;
			while ( !source->eof() && (nextChar = source->get()) && (isDecimal(nextChar) || (nextChar == '.' && !foundDecimal)) ) {
				if (nextChar == '.')
					foundDecimal = true;
				numberString << (char)nextChar;
				length++;
			}
			if (foundDecimal) {
				return new FloatLiteralToken(path, index, length, stof(numberString.str()));
			}
			else {
				return new IntegerLiteralToken(path, index, length, stoi(numberString.str()));
			}
		}
		Token* Tokenizer::parseStringToken(istream *source, int& index, string path) {
			source->ignore();
			stringstream result;
			int length = 1;
            char16_t nextChar, c;
			while (!source->eof()) { 
				nextChar = source->get();
				if (nextChar == '"') {
					length++;
					break;
				}
				else if (nextChar == '\\') {
					c = escapeSequenceToChar(source, &length);
				}
                else if (nextChar == '\r' || nextChar == '\n') {
                    return new ErrorToken(path, index, length, "Line cannot end in string literal");
                }
				else {
					c = nextChar;
					length++;
				}
				result << (char)c;
			}
			if (source->eof()) {
				return new ErrorToken(path, index, length, "EOF while parsing string literal");
			}
			else {
				return new StringLiteralToken(path, index, length, result.str());
			}
		}
		Token* Tokenizer::parseIdentifierToken(istream *source, int& index, string path) {
			stringstream identString;
			int length = 0;
            char16_t nextChar;
			while (!source->eof() && (nextChar = source->peek()) && isAlphanumeric(nextChar)) {
				identString << (char)nextChar;
                source->get();
				length++;
			}
			return IdentifierToken::getToken(path, index, length, identString.str());
		}
		Token* Tokenizer::parseSymbolToken(istream *source, int& index, string path) {
            // Very basic symbols only until syntax is better defined
            char16_t nextChar = source->get();
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
    }
}
