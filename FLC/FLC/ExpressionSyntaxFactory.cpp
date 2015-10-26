#include "stdafx.h"
#include "ExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            ExpressionSyntaxFactory::ExpressionSyntaxFactory()
            {

            }
            ExpressionSyntaxFactory::~ExpressionSyntaxFactory()
            {

            }

            bool ExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                reportNotImplemented("ExpressionSyntaxFactory::tryParseSyntax");
                return false;
            }
        }
    }
}
