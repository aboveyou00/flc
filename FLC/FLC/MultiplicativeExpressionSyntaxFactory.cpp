#include "stdafx.h"
#include "MultiplicativeExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            MultiplicativeExpressionSyntaxFactory::MultiplicativeExpressionSyntaxFactory()
            {

            }
            MultiplicativeExpressionSyntaxFactory::~MultiplicativeExpressionSyntaxFactory()
            {

            }

            bool MultiplicativeExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                reportNotImplemented("MultiplicativeExpressionSyntaxFactory::tryParseSyntax");
                return false;
            }
        }
    }
}
