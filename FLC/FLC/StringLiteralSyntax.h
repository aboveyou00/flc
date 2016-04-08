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

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            string str;
        };
    }
}
