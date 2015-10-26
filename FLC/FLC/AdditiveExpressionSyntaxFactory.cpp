#include "stdafx.h"
#include "AdditiveExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            AdditiveExpressionSyntaxFactory::AdditiveExpressionSyntaxFactory()
            {

            }
            AdditiveExpressionSyntaxFactory::~AdditiveExpressionSyntaxFactory()
            {

            }

            bool AdditiveExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                reportNotImplemented("AdditiveExpressionSyntaxFactory::tryParseSyntax");
                return false;
            }
        }
    }
}
