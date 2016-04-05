#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/RelationalExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestRelationalExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseRelationalExpression_lessThan)
        {
            testFactory<RelationalExpressionSyntaxFactory>("true < false");
        }

        TEST_METHOD(Test_parseRelationalExpression_greaterThan)
        {
            testFactory<RelationalExpressionSyntaxFactory>("true > false");
        }

        TEST_METHOD(Test_parseRelationalExpression_lessThanOrEqual)
        {
            testFactory<RelationalExpressionSyntaxFactory>("true <= false");
        }

        TEST_METHOD(Test_parseRelationalExpression_greaterThanOrEqual)
        {
            testFactory<RelationalExpressionSyntaxFactory>("true >= false");
        }
    };
}
