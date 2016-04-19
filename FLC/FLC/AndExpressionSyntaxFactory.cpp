#include "stdafx.h"
#include "AndExpressionSyntax.h"
#include "AndExpressionSyntaxFactory.h"
#include "EqualityExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            AndExpressionSyntaxFactory::AndExpressionSyntaxFactory()
            {
            }
            AndExpressionSyntaxFactory::~AndExpressionSyntaxFactory()
            {
            }

            bool AndExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                EqualityExpressionSyntaxFactory factory;
                if (!factory.tryParseSyntax(toks, pos, result)) return false;
                while (tryParseRhs(toks, pos, result)) { }
                return true;
            }
            bool AndExpressionSyntaxFactory::tryParseRhs(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                if (toks->at(pos)->isSymbol("&"))
                {
                    EqualityExpressionSyntaxFactory factory;
                    ExpressionSyntax *rhs = nullptr;
                    int p = pos + 1;
                    if (!factory.tryParseSyntax(toks, p, rhs)) return false;
                    result = new AndExpressionSyntax(result, rhs);
                    pos = p;
                    return true;
                }
                return false;
            }
        }
    }
}
