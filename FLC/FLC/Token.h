#pragma once
#include <string>
#include <vector>
#include <ostream>

namespace flc
{
    namespace tokens
    {
        class Comment;

        class Token
        {
        public:
            Token(std::string sourceFile, int startPos, int length);
            ~Token();

            std::string getSourceFile();
            int getStartPosition();
            int getLength();
            int getEndPosition();

            virtual bool isSymbol() { return false; }
            virtual bool isSymbol(std::string) { return false; }
            virtual bool isKeyword() { return false; }
            virtual bool isKeyword(std::string) { return false; }
            virtual bool isIdentifier() { return false; }
            virtual bool isIdentifier(std::string) { return false; }
            virtual bool isStringLiteral() { return false; }
            virtual bool isStringLiteral(std::string) { return false; }
            virtual bool isIntegerLiteral() { return false; }
            virtual bool isIntegerLiteral(uint32_t) { return false; }
            virtual bool isUIntegerLiteral() { return false; }
            virtual bool isUIntegerLiteral(uint32_t) { return false; }
            virtual bool isLongLiteral() { return false; }
            virtual bool isLongLiteral(uint64_t) { return false; }
            virtual bool isULongLiteral() { return false; }
            virtual bool isULongLiteral(uint64_t) { return false; }
            virtual bool isFloatLiteral() { return false; }
            virtual bool isFloatLiteral(float) { return false; }
            virtual bool isDoubleLiteral() { return false; }
            virtual bool isDoubleLiteral(double) { return false; }
            virtual bool isBooleanLiteral() { return false; }
            virtual bool isBooleanLiteral(bool) { return false; }
            virtual bool isCharacterLiteral() { return false; }
            virtual bool isCharacterLiteral(char16_t) { return false; }
            virtual bool isNullLiteral() { return false; }
            virtual bool isEndOfFile() { return false; }

            void prependComment(Comment *cmt);
            const std::vector<const Comment*> *getComments();

            virtual std::string toString() = 0;

        private:
            std::string _path;
            int _start, _length;
            std::vector<const Comment*> *_comments;
        };

        std::ostream& operator<<(std::ostream &o, Token &tok);
    }
}
