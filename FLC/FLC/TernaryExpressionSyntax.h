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

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            ExpressionSyntax *_cond, *_iftrue, *_iffalse;
        };
    }
}
