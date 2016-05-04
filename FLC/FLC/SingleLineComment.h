#pragma once
#include "Comment.h"

namespace flc
{
    namespace tokens
    {
        class SingleLineComment : public Comment
        {
        public:
            SingleLineComment(int pos, int length, std::string content);
            ~SingleLineComment();

            std::string toString() override;
        };
    }
}
