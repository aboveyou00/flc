#pragma once
#include "LiteralSyntax.h"

namespace flc
{
    namespace syntax
    {
        class StringLiteralSyntax : public LiteralSyntax<string>
        {
        public:
            StringLiteralSyntax(string strval);
            ~StringLiteralSyntax();

            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;
        };
    }
}
