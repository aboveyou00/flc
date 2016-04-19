#include "stdafx.h"
#include "MultiplicativeExpressionSyntax.h"
#include "MultiplicativeExpressionSyntaxFactory.h"
#include "UnaryExpressionSyntaxFactory.h"

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
                UnaryExpressionSyntaxFactory unaryFactory;
                if (!unaryFactory.tryParseSyntax(toks, pos, result)) return false;
                while (tryParseRhs(toks, pos, result)) { }
                return true;
            }
            bool MultiplicativeExpressionSyntaxFactory::tryParseRhs(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                if (toks->at(pos)->isSymbol("*") || toks->at(pos)->isSymbol("/") ||
                    toks->at(pos)->isSymbol("%"))
                {
                    UnaryExpressionSyntaxFactory unaryFactory;
                    ExpressionSyntax *rhs = nullptr;
                    int p = pos + 1;
                    if (!unaryFactory.tryParseSyntax(toks, p, rhs)) return false;
                    result = new MultiplicativeExpressionSyntax(result, toks->at(pos)->toString(), rhs);
                    pos = p;
                    return true;
                }
                return false;
            }
        }
    }
}
