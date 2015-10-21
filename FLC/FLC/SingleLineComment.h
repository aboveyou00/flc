#pragma once
#include <string>
#include "Comment.h"

namespace flc
{
    namespace tokens
    {
        class SingleLineComment : public Comment
        {
        public:
            SingleLineComment(int pos, int length, string content);
            ~SingleLineComment();

            virtual string toString();
        };
    }
}
