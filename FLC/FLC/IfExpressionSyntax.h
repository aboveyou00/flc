#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class IfExpressionSyntax : public ExpressionSyntax
        {
        public:
            IfExpressionSyntax(ExpressionSyntax* cond, ExpressionSyntax* expr);
            IfExpressionSyntax(ExpressionSyntax* cond, ExpressionSyntax* expr, ExpressionSyntax* elseExpr);
            ~IfExpressionSyntax();

            ExpressionSyntax* getCondition();
            ExpressionSyntax* getExpression();
            ExpressionSyntax* getElseExpression();

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_cond = nullptr,
                             *_expr = nullptr,
                             *_elseExpr = nullptr;
        };
    }
}
