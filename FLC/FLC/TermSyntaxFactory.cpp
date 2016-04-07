#include "stdafx.h"
#include "TermSyntaxFactory.h"

#include "ExpressionSyntaxFactory.h"
#include "CompoundExpressionSyntaxFactory.h"

#include "StringLiteralSyntax.h"
#include "CharacterLiteralSyntax.h"
#include "IntegerLiteralSyntax.h"
#include "FloatLiteralSyntax.h"
#include "BooleanLiteralSyntax.h"
#include "NullLiteralSyntax.h"
#include "SimpleNameSyntax.h"
#include "ComplexNameSyntax.h"
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
                else if (tok->isSymbol(":::") && toks->at(pos + 1)->isIdentifier())
                {
                    tok = toks->at(++pos);
                    result = new SimpleNameSyntax(((tokens::IdentifierToken*)tok)->getValue(), true);
                }
                else if (tok->isIdentifier())
                {
                    result = new SimpleNameSyntax(((tokens::IdentifierToken*)tok)->getValue(), false);
                }
                else if (tok->isIntegerLiteral())
                {
                    result = new IntegerLiteralSyntax(((tokens::IntegerLiteralToken*)tok)->getValue());
                }
                else if (tok->isFloatLiteral())
                {
                    result = new FloatLiteralSyntax(((tokens::FloatLiteralToken*)tok)->getValue());
                }
                else if (tok->isBooleanLiteral())
                {
                    result = new BooleanLiteralSyntax(((tokens::BooleanLiteralToken*)tok)->getValue());
                }
                else if (tok->isCharacterLiteral())
                {
                    result = new CharacterLiteralSyntax(((tokens::CharacterLiteralToken*)tok)->getValue());
                }
                else if (tok->isStringLiteral())
                {
                    result = new StringLiteralSyntax(((tokens::StringLiteralToken*)tok)->getValue());
                }
                else if (tok->isNullLiteral())
                {
                    result = new NullLiteralSyntax();
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
                else if (tok->isSymbol("::") && toks->at(pos + 1)->isIdentifier() && term->isQualifiedName())
                {
                    tok = toks->at(pos + 1);
                    result = new ComplexNameSyntax(term, ((tokens::IdentifierToken*)tok)->getValue());
                    pos += 2;
                    return true;
                }
                //else if (tok->isSymbol("["))
                //{

                //}
                return false;
            }
        }
    }
}
