#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class StringLiteralSyntax : public ExpressionSyntax
        {
        public:
            StringLiteralSyntax(string strval);
            ~StringLiteralSyntax();

            string getValue();

            virtual string toString();

        private:
            string str;
        };
    }
}
