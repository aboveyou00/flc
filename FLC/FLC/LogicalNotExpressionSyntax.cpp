#include "stdafx.h"
#include "LogicalNotExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        LogicalNotExpressionSyntax::LogicalNotExpressionSyntax(ExpressionSyntax* expr)
            : UnaryOperatorExpressionSyntax(expr)
        {
        }
        LogicalNotExpressionSyntax::~LogicalNotExpressionSyntax()
        {
        }

        op::UnaryOperator *LogicalNotExpressionSyntax::getUnaryOperator()
        {
            return op::Operator::logicalNot();
        }
        std::string LogicalNotExpressionSyntax::getOperatorSymbol()
        {
            return  "!";
        }
    }
}
