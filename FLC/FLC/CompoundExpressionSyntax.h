#pragma once
#include <vector>
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class CompoundExpressionSyntax : public ExpressionSyntax
        {
        public:
            CompoundExpressionSyntax(vector<ExpressionSyntax*>* expressions);
            ~CompoundExpressionSyntax();

            int getPrecedence() override;

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            vector<ExpressionSyntax*> exprs;
        };
    }
}
