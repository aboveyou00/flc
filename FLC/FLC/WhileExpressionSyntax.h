#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class WhileExpressionSyntax : public ExpressionSyntax
        {
        public:
            WhileExpressionSyntax(ExpressionSyntax* cond, ExpressionSyntax* expr);
            ~WhileExpressionSyntax();

            ExpressionSyntax* getCondition();
            ExpressionSyntax* getExpression();

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            ExpressionSyntax *_cond, *_expr;
        };
    }
}
