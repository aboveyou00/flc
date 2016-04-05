#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/ConditionalAndExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestConditionalAndExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseConditionalAndExpression)
        {
            testFactory<ConditionalAndExpressionSyntaxFactory>("true && false");
        }
    };
}
