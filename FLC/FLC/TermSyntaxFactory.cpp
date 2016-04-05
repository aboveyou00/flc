#include "stdafx.h"
#include "TermSyntax.h"
#include "TermSyntaxFactory.h"
#include "ExpressionSyntaxFactory.h"

#include "IntegerLiteralToken.h"
#include "IdentifierToken.h"
#include "CharacterLiteralToken.h"
#include "BooleanLiteralToken.h"
#include "FloatLiteralToken.h"
#include "KeywordToken.h"
#include "StringLiteralToken.h"

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
                auto tok = toks->at(pos);
                if (tok->isSymbol("("))
                {
                    int p = pos + 1;
                    ExpressionSyntaxFactory exprFactory;
                    if (!exprFactory.tryParseSyntax(toks, p, result)) return false;
                    if (!toks->at(p)->isSymbol(")")) return false;
                    pos = p + 1;
                    return true;
                }
                else if (tok->isIdentifier())
                {
                    result = new TermSyntax(((tokens::IdentifierToken*)tok)->getValue(), true);
                }
                else if (tok->isIntegerLiteral())
                {
                    result = new TermSyntax(((tokens::IntegerLiteralToken*)tok)->getValue());
                }
                else if (tok->isFloatLiteral())
                {
                    result = new TermSyntax(((tokens::FloatLiteralToken*)tok)->getValue());
                }
                else if (tok->isBooleanLiteral())
                {
                    result = new TermSyntax(((tokens::BooleanLiteralToken*)tok)->getValue());
                }
                else if (tok->isCharacterLiteral())
                {
                    result = new TermSyntax(((tokens::CharacterLiteralToken*)tok)->getValue());
                }
                else if (tok->isStringLiteral())
                {
                    result = new TermSyntax(((tokens::StringLiteralToken*)tok)->getValue(), false);
                }
                else if (tok->isNullLiteral())
                {
                    result = new TermSyntax();
                }
                else return false;
                pos++;
                return true;
            }
        }
    }
}
