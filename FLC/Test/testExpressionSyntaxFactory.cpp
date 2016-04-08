#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/ExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseAssignmentExpression)
        {
            testFactory<ExpressionSyntaxFactory>("test = 42");
        }

        TEST_METHOD(Test_parseAssignmentExpression_add)
        {
            testFactory<ExpressionSyntaxFactory>("test += 42");
        }

        TEST_METHOD(Test_parseAssignmentExpression_subtract)
        {
            testFactory<ExpressionSyntaxFactory>("test -= 42");
        }

        TEST_METHOD(Test_parseAssignmentExpression_multiply)
        {
            testFactory<ExpressionSyntaxFactory>("test *= 42");
        }

        TEST_METHOD(Test_parseAssignmentExpression_divide)
        {
            testFactory<ExpressionSyntaxFactory>("test /= 42");
        }

        TEST_METHOD(Test_parseAssignmentExpression_remainder)
        {
            testFactory<ExpressionSyntaxFactory>("test %= 42");
        }

        TEST_METHOD(Test_parseAssignmentExpression_or)
        {
            testFactory<ExpressionSyntaxFactory>("test |= 42");
        }

        TEST_METHOD(Test_parseAssignmentExpression_and)
        {
            testFactory<ExpressionSyntaxFactory>("test &= 42");
        }

        TEST_METHOD(Test_parseAssignmentExpression_not)
        {
            testFactory<ExpressionSyntaxFactory>("test ^= 42");
        }

        TEST_METHOD(Test_parseAssignmentExpression_shiftLeft)
        {
            testFactory<ExpressionSyntaxFactory>("test <<= 42");
        }

        TEST_METHOD(Test_parseAssignmentExpression_shiftRight)
        {
            testFactory<ExpressionSyntaxFactory>("test >>= 42");
        }

        TEST_METHOD(Test_multiple_assignment)
        {
            testFactory<ExpressionSyntaxFactory>("one = two += three -= four");
        }
    };
}
