#pragma once
#include "LiteralSyntax.h"

namespace flc
{
    namespace syntax
    {
        class BooleanLiteralSyntax : public LiteralSyntax<bool>
        {
        public:
            BooleanLiteralSyntax(bool value);
            ~BooleanLiteralSyntax();

            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;
            string toString() override;
        };
    }
}
