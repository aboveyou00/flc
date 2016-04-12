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

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            int val;
        };
    }
}
