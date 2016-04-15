#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class LongLiteralSyntax : public ExpressionSyntax
        {
        public:
            LongLiteralSyntax(uint64_t value);
            ~LongLiteralSyntax();

            uint64_t getValue();

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            uint64_t val;
        };
    }
}
