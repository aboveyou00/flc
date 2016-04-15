#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class UIntegerLiteralSyntax : public ExpressionSyntax
        {
        public:
            UIntegerLiteralSyntax(uint32_t value);
            ~UIntegerLiteralSyntax();

            uint32_t getValue();

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            uint32_t val;
        };
    }
}
