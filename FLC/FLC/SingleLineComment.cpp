#include "stdafx.h"
#include "SingleLineComment.h"

namespace flc
{
    namespace tokens
    {
        SingleLineComment::SingleLineComment(int pos, int length, string content)
            : Comment(pos, length, content)
        {
        }
        SingleLineComment::~SingleLineComment()
        {
        }

        string SingleLineComment::toString()
        {
            return "//" + getContent();
        }
    }
}