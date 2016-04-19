#pragma once
#include "LiteralSyntax.h"

namespace flc
{
    namespace syntax
    {
        class ULongLiteralSyntax : public LiteralSyntax<uint64_t>
        {
        public:
            ULongLiteralSyntax(uint64_t value);
            ~ULongLiteralSyntax();

            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;
        };
    }
}
