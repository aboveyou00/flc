#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/IfExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestIfExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseIfExpression_if)
        {
            testFactory<IfExpressionSyntaxFactory>("if (true) false");
        }

        TEST_METHOD(Test_parseIfExpression_ifElse)
        {
            testFactory<IfExpressionSyntaxFactory>("if (true) false\r\nelse true");
        }
    };
}
