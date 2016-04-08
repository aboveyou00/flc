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
                ShiftExpressionSyntaxFactory shiftFactory;
                if (!shiftFactory.tryParseSyntax(toks, pos, result)) return false;
                if (toks->at(pos)->isSymbol("<") || toks->at(pos)->isSymbol(">") ||
                    toks->at(pos)->isSymbol("<=") || toks->at(pos)->isSymbol(">="))
                {
                    int p2 = pos + 1;
                    ExpressionSyntax *relational = nullptr;
                    if (tryParseSyntax(toks, p2, relational))
                    {
                        result = new RelationalExpressionSyntax(result, toks->at(pos)->toString(), relational);
                        pos = p2;
                        return true;
                    }
                }
                return true;
            }
        }
    }
}
