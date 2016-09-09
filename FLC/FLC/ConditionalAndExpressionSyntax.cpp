#include "stdafx.h"
#include "ConditionalAndExpressionSyntax.h"
#include "BrfalseInstr.h"

namespace flc
{
    namespace syntax
    {
        ConditionalAndExpressionSyntax::ConditionalAndExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right)
            : ConditionalExpressionSyntax(left, right)
        {
        }
        ConditionalAndExpressionSyntax::~ConditionalAndExpressionSyntax()
        {
        }
        
        int ConditionalAndExpressionSyntax::getPrecedence()
        {
            return 1000;
        }

        std::string ConditionalAndExpressionSyntax::getOperatorSymbol()
        {
            return "&&"s;
        }

        emit::BranchInstr *ConditionalAndExpressionSyntax::createBranchInstr()
        {
            return new emit::BrfalseInstr();
        }
    }
}
