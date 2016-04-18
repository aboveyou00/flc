#include "stdafx.h"
#include "ShiftExpressionSyntax.h"
#include "ShiftExpressionSyntaxFactory.h"
#include "AdditiveExpressionSyntaxFactory.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            ShiftExpressionSyntaxFactory::ShiftExpressionSyntaxFactory()
            {
            }
            ShiftExpressionSyntaxFactory::~ShiftExpressionSyntaxFactory()
            {
            }

            bool ShiftExpressionSyntaxFactory::tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                AdditiveExpressionSyntaxFactory additiveFactory;
                if (!additiveFactory.tryParseSyntax(toks, pos, result)) return false;
                if (toks->at(pos)->isSymbol("<<") ||
                    (toks->at(pos)->isSymbol(">") && toks->at(pos + 1)->isSymbol(">") &&
                      toks->at(pos + 1)->getStartPosition() == toks->at(pos)->getStartPosition() + 1))
                {
                    int p2 = toks->at(pos)->isSymbol("<<") ? pos + 1 : pos + 2;
                    ExpressionSyntax *shift = nullptr;
                    if (!tryParseSyntax(toks, p2, shift))
                    {
                        //TODO: provide more context
                        reportError("Unexpected unary operator: " + result->toString() + toks->at(pos)->toString());
                        delete result; //Clean up partial expression
                        return false;
                    }
                    result = new ShiftExpressionSyntax(result, toks->at(pos)->isSymbol("<<") ? "<<" : ">>", shift);
                    pos = p2;
                }
                return true;
            }
        }
    }
}
