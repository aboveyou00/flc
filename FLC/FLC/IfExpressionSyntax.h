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

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            ExpressionSyntax *_cond, *_expr, *_elseExpr;
        };
    }
}
