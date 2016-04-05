#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/ConditionalOrExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestConditionalOrExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseConditionalOrExpression)
        {
            testFactory<ConditionalOrExpressionSyntaxFactory>("true || false");
        }
    };
}
