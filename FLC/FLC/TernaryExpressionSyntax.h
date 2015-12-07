#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class TernaryExpressionSyntax : public ExpressionSyntax
        {
        public:
            TernaryExpressionSyntax(ExpressionSyntax* condition, ExpressionSyntax* iftrue, ExpressionSyntax* iffalse);
            ~TernaryExpressionSyntax();

            ExpressionSyntax* getCondition();
            ExpressionSyntax* getTrueExpression();
            ExpressionSyntax* getFalseExpression();

            virtual string toString();

        private:
            ExpressionSyntax *_cond, *_iftrue, *_iffalse;
        };
    }
}
