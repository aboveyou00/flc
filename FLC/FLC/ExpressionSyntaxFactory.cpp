#include "stdafx.h"
#include "Token.h"
#include "ExpressionSyntax.h"
#include "ExpressionSyntaxFactory.h"
#include "AdditiveExpressionSyntaxFactory.h"

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
                AdditiveExpressionSyntaxFactory additiveFactory;
                if (!additiveFactory.tryParseSyntax(toks, pos, result)) return false;
                return true;
            }
        }
    }
}
