#include "stdafx.h"
#include "Comment.h"

namespace flc
{
    namespace tokens
    {
        Comment::Comment(int pos, int length, string content)
        {
            _content = content;
            _pos = pos;
            _length = length;
        }
        Comment::~Comment()
        {
        }

        string Comment::getContent()
        {
            return _content;
        }

        string Comment::toString()
        {
            return getContent();
        }
    }
}