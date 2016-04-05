#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/UnaryExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestUnaryExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseUnaryExpression_positive)
        {
            testFactory<UnaryExpressionSyntaxFactory>("+32");
        }

        TEST_METHOD(Test_parseUnaryExpression_negative)
        {
            testFactory<UnaryExpressionSyntaxFactory>("-32");
        }

        TEST_METHOD(Test_parseUnaryExpression_not)
        {
            testFactory<UnaryExpressionSyntaxFactory>("!true");
        }

        TEST_METHOD(Test_parseUnaryExpression_bitwiseNot)
        {
            testFactory<UnaryExpressionSyntaxFactory>("~32");
        }

        TEST_METHOD(Test_parseUnaryExpression_preIncrement)
        {
            testFactory<UnaryExpressionSyntaxFactory>("++test");
        }

        TEST_METHOD(Test_parseUnaryExpression_preDecrement)
        {
            testFactory<UnaryExpressionSyntaxFactory>("--test");
        }
    };
}
