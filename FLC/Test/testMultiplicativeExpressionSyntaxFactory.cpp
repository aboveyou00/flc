#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/MultiplicativeExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestMultiplicativeExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseMultiplicativeExpression_multiply)
        {
            testFactory<MultiplicativeExpressionSyntaxFactory>("2 * 3");
        }

        TEST_METHOD(Test_parseMultiplicativeExpression_divide)
        {
            testFactory<MultiplicativeExpressionSyntaxFactory>("2 / 3");
        }

        TEST_METHOD(Test_parseMultiplicativeExpression_remainder)
        {
            testFactory<MultiplicativeExpressionSyntaxFactory>("2 % 3");
        }
    };
}
