#include "stdafx.h"
#include "UnaryExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            UnaryExpressionSyntaxFactory::UnaryExpressionSyntaxFactory()
            {

            }
            UnaryExpressionSyntaxFactory::~UnaryExpressionSyntaxFactory()
            {

            }

            bool UnaryExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                reportNotImplemented("UnaryExpressionSyntaxFactory::tryParseSyntax");
                return false;
            }
        }
    }
}
