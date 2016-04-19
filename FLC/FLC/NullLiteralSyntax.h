#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class NullLiteralSyntax : public ExpressionSyntax
        {
        public:
            NullLiteralSyntax();
            ~NullLiteralSyntax();

            int getPrecedence() override;

            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;
            string toString() override;
        };
    }
}
