#pragma once
#include <string>

namespace flc
{
    namespace tokens
    {
        class Comment
        {
        public:
            Comment(int pos, int length, std::string content);
            ~Comment();

            std::string getContent();

            virtual std::string toString();

        private:
            std::string _content;
            int _pos, _length;
        };
    }
}
