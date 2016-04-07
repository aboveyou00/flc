#include "stdafx.h"
#include "TermSyntaxFactory.h"

#include "ExpressionSyntaxFactory.h"
#include "CompoundExpressionSyntaxFactory.h"

#include "TermSyntax.h"
#include "MemberAccessExpressionSyntax.h"

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
                if (!tryParseFirstSyntax(toks, pos, result)) return false;
                while (tryParseNextSyntax(result, toks, pos, result)) { }
                return true;
            }

            bool TermSyntaxFactory::tryParseFirstSyntax(vector<flc::tokens::Token*>* toks, int & pos, ExpressionSyntax*& result)
            {
                auto tok = toks->at(pos);
                if (tok->isSymbol("{"))
                {
                    CompoundExpressionSyntaxFactory compoundFactory;
                    return compoundFactory.tryParseSyntax(toks, pos, result);
                }
                else if (tok->isSymbol("("))
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

            bool TermSyntaxFactory::tryParseNextSyntax(ExpressionSyntax* term, vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result)
            {
                auto tok = toks->at(pos);
                if (tok->isSymbol("."))
                {
                    tok = toks->at(pos + 1);
                    if (!tok->isIdentifier()) return false;
                    pos += 2;
                    result = new MemberAccessExpressionSyntax(term, ((tokens::IdentifierToken*)tok)->getValue());
                    return true;
                }
                //else if (tok->isSymbol("++"))
                //{

                //}
                //else if (tok->isSymbol("--"))
                //{

                //}
                //else if (tok->isSymbol("::"))
                //{
                //    //TODO: Check if term is a qualified name; otherwise this is invalid
                //}
                //else if (tok->isSymbol("["))
                //{

                //}
                return false;
            }
        }
    }
}
