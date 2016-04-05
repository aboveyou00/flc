#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/TernaryExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestTernaryExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseTernaryExpression)
        {
            testFactory<TernaryExpressionSyntaxFactory>("true ? false : true");
        }
    };
}
