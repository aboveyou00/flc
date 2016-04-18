#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class BooleanLiteralSyntax : public ExpressionSyntax
        {
        public:
            BooleanLiteralSyntax(bool value);
            ~BooleanLiteralSyntax();

            bool getValue();

            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;
            string toString() override;

        private:
            bool val;
        };
    }
}
