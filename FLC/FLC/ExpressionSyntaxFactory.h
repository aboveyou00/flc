#pragma once
#include <vector>
#include "Token.h"
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        namespace factory
        {
            class ExpressionSyntaxFactory
            {
            public:
                ExpressionSyntaxFactory();
                ~ExpressionSyntaxFactory();

                virtual bool tryParseSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result);

            private:
                virtual bool tryParseFirstSyntax(vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result);
                virtual bool tryParseNextSyntax(ExpressionSyntax* term, vector<flc::tokens::Token*>* toks, int& pos, ExpressionSyntax*& result);
            };
        }
    }
}