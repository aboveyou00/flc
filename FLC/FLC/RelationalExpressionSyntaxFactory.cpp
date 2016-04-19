#include "stdafx.h"
#include "RelationalExpressionSyntax.h"
#include "RelationalExpressionSyntaxFactory.h"
#include "ShiftExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            RelationalExpressionSyntaxFactory::RelationalExpressionSyntaxFactory()
            {
            }
            RelationalExpressionSyntaxFactory::~RelationalExpressionSyntaxFactory()
            {
            }

            bool RelationalExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                ShiftExpressionSyntaxFactory factory;
                if (!factory.tryParseSyntax(toks, pos, result)) return false;
                while (tryParseRhs(toks, pos, result)) { }
                return true;
            }
            bool RelationalExpressionSyntaxFactory::tryParseRhs(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                if (toks->at(pos)->isSymbol("<") || toks->at(pos)->isSymbol(">") ||
                    toks->at(pos)->isSymbol("<=") || toks->at(pos)->isSymbol(">="))
                {
                    ShiftExpressionSyntaxFactory factory;
                    ExpressionSyntax *rhs = nullptr;
                    int p = pos + 1;
                    if (!factory.tryParseSyntax(toks, p, rhs)) return false;
                    result = new RelationalExpressionSyntax(result, toks->at(pos)->toString(), rhs);
                    pos = p;
                    return true;
                }
                return false;
            }
        }
    }
}
