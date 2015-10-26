#include "stdafx.h"
#include "TermSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            TermSyntaxFactory::TermSyntaxFactory()
            {

            }
            TermSyntaxFactory::~TermSyntaxFactory()
            {

            }

            bool TermSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                reportNotImplemented("TermSyntaxFactory::tryParseSyntax");
                return false;
            }
        }
    }
}
