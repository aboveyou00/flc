#pragma once
#include "Comment.h"

namespace flc
{
    namespace tokens
    {
        class MultiLineComment : public Comment
        {
        public:
            MultiLineComment(int pos, int length, std::string content);
            ~MultiLineComment();

            std::string toString() override;
        };
    }
}
