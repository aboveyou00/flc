#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class AndExpressionSyntax : public ExpressionSyntax
        {
        public:
            AndExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right);
            ~AndExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();

            virtual string toString();

        private:
            ExpressionSyntax *_left, *_right;
        };
    }
}
