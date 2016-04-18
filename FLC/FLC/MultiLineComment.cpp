#include "stdafx.h"
#include "MultiLineComment.h"

namespace flc
{
    namespace tokens
    {
        MultiLineComment::MultiLineComment(int pos, int length, string content)
            : Comment(pos, length, content)
        {
        }
        MultiLineComment::~MultiLineComment()
        {
        }

        string MultiLineComment::toString()
        {
            return "/*" + getContent() + "*/";
        }
    }
}