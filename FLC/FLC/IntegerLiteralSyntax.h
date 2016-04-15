#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class IntegerLiteralSyntax : public ExpressionSyntax
        {
        public:
            IntegerLiteralSyntax(uint32_t value);
            ~IntegerLiteralSyntax();

            uint32_t getValue();

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            uint32_t val;
        };
    }
}
