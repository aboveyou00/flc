#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class DoubleLiteralSyntax : public ExpressionSyntax
        {
        public:
            DoubleLiteralSyntax(double value);
            ~DoubleLiteralSyntax();

            double getValue();

            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            double val;
        };
    }
}
