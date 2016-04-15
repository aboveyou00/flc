#pragma once
#include "Token.h"

namespace flc
{
    namespace tokens
    {
        class DoubleLiteralToken : public Token
        {
        public:
            DoubleLiteralToken(string sourceFile, int startPos, int length, double value);
            ~DoubleLiteralToken();

            double getValue();

            bool isDoubleLiteral() override;
            bool isDoubleLiteral(double val) override;

            string toString() override;

        private:
            double _val;
        };
    }
}
