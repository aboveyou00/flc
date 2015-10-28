#pragma once
#include <string>
#include <vector>
#include <ostream>
#include "Comment.h"

namespace flc
{
    namespace tokens
    {
        class Token
        {
        public:
            Token(string sourceFile, int startPos, int length);
            ~Token();

            //integerLiteralToken, floatLiteralToken, symbolToken, stringLiteralToken, characterLiteralToken
            string getSourceFile();
            int getStartPosition();
            int getLength();
            int getEndPosition();

            virtual bool isSymbol() { return false; }
            virtual bool isSymbol(string sym) { return false; }
            virtual bool isKeyword() { return false; }
            virtual bool isKeyword(string val) { return false; }
            virtual bool isIdentifier() { return false; }
            virtual bool isIdentifier(string val) { return false; }
            virtual bool isStringLiteral() { return false; }
            virtual bool isStringLiteral(string val) { return false; }
            virtual bool isIntegerLiteral() { return false; }
            virtual bool isIntegerLiteral(uint32_t val) { return false; }
            virtual bool isFloatLiteral() { return false; }
            virtual bool isFloatLiteral(float val) { return false; }
            virtual bool isBooleanLiteral() { return false; }
            virtual bool isBooleanLiteral(bool val) { return false; }
            virtual bool isCharacterLiteral() { return false; }
            virtual bool isCharacterLiteral(char16_t val) { return false; }
            virtual bool isNullLiteral() { return false; }
            virtual bool isEndOfFile() { return false; }

            void prependComment(Comment *cmt);
            const vector<const Comment*>* getComments();

            virtual string toString();

        private:
            string _path;
            int _start, _length;
            vector<const Comment*>* _comments;
        };

        std::ostream& operator<<(std::ostream& o, Token& tok);
    }
}
