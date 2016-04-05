#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/ExclusiveOrExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestExclusiveOrExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseExclusiveOrExpression)
        {
            testFactory<ExclusiveOrExpressionSyntaxFactory>("true ^ false");
        }
    };
}
