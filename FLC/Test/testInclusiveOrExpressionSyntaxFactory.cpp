#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/InclusiveOrExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestInclusiveOrExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseInclusiveOrExpression)
        {
            testFactory<InclusiveOrExpressionSyntaxFactory>("true | false");
        }
    };
}
