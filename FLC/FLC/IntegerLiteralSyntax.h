#pragma once
#include "LiteralSyntax.h"

namespace flc
{
    namespace syntax
    {
        class IntegerLiteralSyntax : public LiteralSyntax<uint32_t>
        {
        public:
            IntegerLiteralSyntax(uint32_t value);
            ~IntegerLiteralSyntax();

            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;
        };
    }
}
