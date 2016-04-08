#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class NullLiteralSyntax : public ExpressionSyntax
        {
        public:
            NullLiteralSyntax();
            ~NullLiteralSyntax();

            virtual void stringify(stringstream* stream, int tabulation = 0);
            virtual string toString();
        };
    }
}
