#pragma once
#include "LiteralSyntax.h"

namespace flc
{
    namespace syntax
    {
        class LongLiteralSyntax : public LiteralSyntax<uint64_t>
        {
        public:
            LongLiteralSyntax(uint64_t value);
            ~LongLiteralSyntax();

            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;
        };
    }
}
