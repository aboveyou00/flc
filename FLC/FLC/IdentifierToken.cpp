#include "stdafx.h"
#include "IdentifierToken.h"
#include "BooleanLiteralToken.h"
#include "NullLiteralToken.h"

namespace flc
{
    namespace tokens
    {
        IdentifierToken::IdentifierToken(string sourceFile, int startPos, int length, string value)
            : Token(sourceFile, startPos, length)
        {
            _val = value;
        }
        IdentifierToken::~IdentifierToken()
        {
        }

        string IdentifierToken::getValue()
        {
            return _val;
        }

        bool IdentifierToken::isIdentifier()
        {
            return true;
        }
        bool IdentifierToken::isIdentifier(string val)
        {
            return _val == val;
        }

        string IdentifierToken::toString()
        {
            return _val;
        }

        vector<string>* getKeyWords()
        {
            static vector<string>* _keyWords = nullptr;
            if (_keyWords == nullptr)
            {
                _keyWords = new vector<string>();
                _keyWords->push_back("do");
                _keyWords->push_back("if");
                _keyWords->push_back("else");
                _keyWords->push_back("for");
                _keyWords->push_back("while");

                _keyWords->push_back("int");
                _keyWords->push_back("uint");
                _keyWords->push_back("short");
                _keyWords->push_back("ushort");
                _keyWords->push_back("byte");
                _keyWords->push_back("sbyte");
                _keyWords->push_back("long");
                _keyWords->push_back("ulong");
                _keyWords->push_back("char");
                _keyWords->push_back("string");
                _keyWords->push_back("bool");
                _keyWords->push_back("float");
                _keyWords->push_back("double");
                _keyWords->push_back("decimal");

                _keyWords->push_back("dynamic");
                _keyWords->push_back("object");

                _keyWords->push_back("new");
                _keyWords->push_back("validate");
                _keyWords->push_back("default");

                _keyWords->push_back("typeof");
                _keyWords->push_back("as");
                _keyWords->push_back("is");
                _keyWords->push_back("cast");
                _keyWords->push_back("assert");

                _keyWords->push_back("checked");
                _keyWords->push_back("unchecked");
                _keyWords->push_back("lazy");
                _keyWords->push_back("await");
                _keyWords->push_back("until");
            }
            return _keyWords;
        }

        Token* IdentifierToken::getToken(string sourceFile, int startPos, int length, string value)
        {
            auto kw = getKeyWords();

            if (value == "true") return new BooleanLiteralToken(sourceFile, startPos, true);
            else if (value == "false") return new BooleanLiteralToken(sourceFile, startPos, false);
            else if (value == "null") return new NullLiteralToken(sourceFile, startPos);
            
            else if (std::find(kw->begin(), kw->end(), value) != kw->end())
                return new KeywordToken(sourceFile, startPos, value);
            
            else return new IdentifierToken(sourceFile, startPos, length, value);
        }
    }
}
