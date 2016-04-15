#pragma once
#include <string>
#include "Comment.h"

namespace flc
{
    namespace tokens
    {
        class MultiLineComment : public Comment
        {
        public:
            MultiLineComment(int pos, int length, string content);
            ~MultiLineComment();

            string toString() override;
        };
    }
}
