#pragma once
#include "LiteralSyntax.h"

namespace flc
{
    namespace syntax
    {
        class UIntegerLiteralSyntax : public LiteralSyntax<uint32_t>
        {
        public:
            UIntegerLiteralSyntax(uint32_t value);
            ~UIntegerLiteralSyntax();

            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;
        };
    }
}
