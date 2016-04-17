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

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;
            string toString() override;
        };
    }
}
