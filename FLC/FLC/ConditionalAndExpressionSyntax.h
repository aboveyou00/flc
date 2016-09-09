#pragma once
#include "ConditionalExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class ConditionalAndExpressionSyntax : public ConditionalExpressionSyntax
        {
        public:
            ConditionalAndExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right);
            ~ConditionalAndExpressionSyntax();

            int getPrecedence() override;

            std::string getOperatorSymbol() override;

        protected:
            emit::BranchInstr *createBranchInstr() override;
        };
    }
}
