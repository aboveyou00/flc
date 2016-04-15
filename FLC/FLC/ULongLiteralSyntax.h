#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class ULongLiteralSyntax : public ExpressionSyntax
        {
        public:
            ULongLiteralSyntax(uint64_t value);
            ~ULongLiteralSyntax();

            uint64_t getValue();

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            uint64_t val;
        };
    }
}
