#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class IntegerLiteralSyntax : public ExpressionSyntax
        {
        public:
            IntegerLiteralSyntax(int value);
            ~IntegerLiteralSyntax();

            int getValue();

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            int val;
        };
    }
}
