#pragma once
#include <string>
#include "Comment.h"

namespace flc
{
    namespace tokens
    {
        using namespace std;

        class SingleLineComment : public Comment
        {
        public:
            SingleLineComment(int pos, int length, string content);
            ~SingleLineComment();

            virtual string toString();
        };
    }
}
