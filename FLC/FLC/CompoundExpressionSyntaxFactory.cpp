#include "stdafx.h"
#include "CompoundExpressionSyntax.h"
#include "CompoundExpressionSyntaxFactory.h"
#include "ExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            CompoundExpressionSyntaxFactory::CompoundExpressionSyntaxFactory()
            {
            }
            CompoundExpressionSyntaxFactory::~CompoundExpressionSyntaxFactory()
            {
            }

            bool CompoundExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                auto tok = toks->at(pos);
                if (!tok->isSymbol("{")) return false;
                int p = pos + 1;

                vector<ExpressionSyntax*> exprs;
                ExpressionSyntax* expr;
                ExpressionSyntaxFactory exprFactory;
                while (exprFactory.tryParseSyntax(toks, p, expr))
                    exprs.push_back(expr);

                if (!toks->at(p++)->isSymbol("}"))
                {
                    //Have to clean up the expressions that we collected
                    for (size_t q = 0; q < exprs.size(); q++)
                    {
                        expr = exprs[q];
                        delete expr;
                    }
                    exprs.clear();
                    return false;
                }

                result = new CompoundExpressionSyntax(&exprs);
                pos = p;
                return true;
            }
        }
    }
}
