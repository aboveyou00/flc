#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class WhileExpressionSyntax : public ExpressionSyntax
        {
        public:
            WhileExpressionSyntax(ExpressionSyntax* cond, ExpressionSyntax* expr, bool positiveCondition = true);
            ~WhileExpressionSyntax();

            ExpressionSyntax* getCondition();
            ExpressionSyntax* getExpression();

            bool isWhileExpression();
            bool isUntilExpression();

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_cond, *_expr;
            bool _isWhile;
        };
    }
}
