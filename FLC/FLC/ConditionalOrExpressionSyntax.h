#pragma once
#include "ConditionalExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class ConditionalOrExpressionSyntax : public ConditionalExpressionSyntax
        {
        public:
            ConditionalOrExpressionSyntax(ExpressionSyntax *left, ExpressionSyntax *right);
            ~ConditionalOrExpressionSyntax();

            int getPrecedence() override;

            std::string getOperatorSymbol() override;

        protected:
            emit::BranchInstr *createBranchInstr() override;
        };
    }
}
