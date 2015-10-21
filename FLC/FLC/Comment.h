#pragma once
#include <string>

namespace flc
{
    namespace tokens
    {
        class Comment
        {
        public:
            Comment(int pos, int length, string content);
            ~Comment();

            string getContent();

            virtual string toString();

        private:
            string _content;
            int _pos, _length;
        };
    }
}