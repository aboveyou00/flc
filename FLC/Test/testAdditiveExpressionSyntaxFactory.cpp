#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/AdditiveExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestAdditiveExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseAdditiveExpression_add)
        {
            testFactory<AdditiveExpressionSyntaxFactory>("2 + 3");
        }

        TEST_METHOD(Test_parseAdditiveExpression_subtract)
        {
            testFactory<AdditiveExpressionSyntaxFactory>("2 - 3");
        }
    };
}
