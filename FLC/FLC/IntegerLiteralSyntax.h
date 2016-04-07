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

            virtual string toString();

        private:
            int val;
        };
    }
}
