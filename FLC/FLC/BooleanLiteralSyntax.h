#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class BooleanLiteralSyntax : public ExpressionSyntax
        {
        public:
            BooleanLiteralSyntax(bool value);
            ~BooleanLiteralSyntax();

            bool getValue();

            virtual void stringify(stringstream* stream, int tabulation = 0);
            virtual string toString();

        private:
            bool val;
        };
    }
}
