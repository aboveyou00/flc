#include "stdafx.h"
#include "EqualityExpressionSyntax.h"
#include "EqualityExpressionSyntaxFactory.h"
#include "RelationalExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            EqualityExpressionSyntaxFactory::EqualityExpressionSyntaxFactory()
            {
            }
            EqualityExpressionSyntaxFactory::~EqualityExpressionSyntaxFactory()
            {
            }

            bool EqualityExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                RelationalExpressionSyntaxFactory factory;
                if (!factory.tryParseSyntax(toks, pos, result)) return false;
                while (tryParseRhs(toks, pos, result)) { }
                return true;
            }
            bool EqualityExpressionSyntaxFactory::tryParseRhs(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                if (toks->at(pos)->isSymbol("==") || toks->at(pos)->isSymbol("!="))
                {
                    RelationalExpressionSyntaxFactory factory;
                    ExpressionSyntax *rhs = nullptr;
                    int p = pos + 1;
                    if (!factory.tryParseSyntax(toks, p, rhs)) return false;
                    result = new EqualityExpressionSyntax(result, toks->at(pos)->toString(), rhs);
                    pos = p;
                    return true;
                }
                return false;
            }
        }
    }
}
