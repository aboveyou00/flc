#include "stdafx.h"
#include <vector>
#include "Token.h"

#include "UnaryExpressionSyntaxFactory.h"

#include "LogicalNotExpressionSyntax.h"
#include "NegateExpressionSyntax.h"
#include "OnesComplementExpressionSyntax.h"
#include "PreDecrementExpressionSyntax.h"
#include "PreIncrementExpressionSyntax.h"
#include "UnaryPlusExpressionSyntax.h"

#include "TermSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            UnaryExpressionSyntaxFactory::UnaryExpressionSyntaxFactory()
            {
            }
            UnaryExpressionSyntaxFactory::~UnaryExpressionSyntaxFactory()
            {
            }

            bool UnaryExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                if (toks->at(pos)->isSymbol("+") || toks->at(pos)->isSymbol("-") ||
                    toks->at(pos)->isSymbol("!") || toks->at(pos)->isSymbol("~") ||
                    toks->at(pos)->isSymbol("++") || toks->at(pos)->isSymbol("--"))
                {
                    int p = pos + 1;
                    if (!tryParseSyntax(toks, p, result)) return false;
                    if (toks->at(pos)->isSymbol("!")) result = new LogicalNotExpressionSyntax(result);
                    else if (toks->at(pos)->isSymbol("-")) result = new NegateExpressionSyntax(result);
                    else if (toks->at(pos)->isSymbol("~")) result = new OnesComplementExpressionSyntax(result);
                    else if (toks->at(pos)->isSymbol("--")) result = new PreDecrementExpressionSyntax(result);
                    else if (toks->at(pos)->isSymbol("++")) result = new PreIncrementExpressionSyntax(result);
                    else if (toks->at(pos)->isSymbol("+")) result = new UnaryPlusExpressionSyntax(result);
                    else throw "What happened here? That's not even possible?";
                    pos = p;
                    return true;
                }
                TermSyntaxFactory termFactory;
                return termFactory.tryParseSyntax(toks, pos, result);
            }
        }
    }
}
