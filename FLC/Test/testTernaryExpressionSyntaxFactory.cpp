#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include <sstream>
#include "../FLC/Tokenizer.h"
#include "../FLC/TernaryExpressionSyntax.h"
#include "../FLC/TernaryExpressionSyntaxFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
    TEST_CLASS(TestTernaryExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseTernaryExpression)
        {
            string original = "true ? false : true";
            string expected = "true ? false : true";

            auto toks = tokenizeString(original);
            auto factory = flc::syntax::factory::TernaryExpressionSyntaxFactory();

            int pos = 0;
            flc::syntax::ExpressionSyntax* result;
            Assert::IsTrue(factory.tryParseSyntax(toks, pos, result));
            Assert::IsTrue(pos == toks->size() - 1);

            string resultStr = result->toString();
            Assert::IsTrue(resultStr.compare(expected) == 0);
        }

    private:
        vector<flc::tokens::Token*>* tokenizeString(string str)
        {
            auto tokenizer = flc::tokens::Tokenizer();
            istringstream stream(str);
            return tokenizer.tokenize(&stream, "test_str");
        }

    };
}
