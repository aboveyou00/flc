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
