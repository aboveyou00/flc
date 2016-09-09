#include "stdafx.h"
#include "ConditionalOrExpressionSyntax.h"
#include "BrtrueInstr.h"

namespace flc
{
    namespace syntax
    {
        ConditionalOrExpressionSyntax::ConditionalOrExpressionSyntax(ExpressionSyntax *left, ExpressionSyntax *right)
            : ConditionalExpressionSyntax(left, right)
        {
        }
        ConditionalOrExpressionSyntax::~ConditionalOrExpressionSyntax()
        {
        }

        int ConditionalOrExpressionSyntax::getPrecedence()
        {
            return 1100;
        }

        std::string ConditionalOrExpressionSyntax::getOperatorSymbol()
        {
            return "||"s;
        }

        emit::BranchInstr *ConditionalOrExpressionSyntax::createBranchInstr()
        {
            return new emit::BrtrueInstr();
        }
    }
}
