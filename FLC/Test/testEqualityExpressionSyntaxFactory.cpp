#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/EqualityExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestEqualityExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseEqualityExpression_equals)
        {
            testFactory<EqualityExpressionSyntaxFactory>("true == false");
        }

        TEST_METHOD(Test_parseEqualityExpression_notEquals)
        {
            testFactory<EqualityExpressionSyntaxFactory>("true != false");
        }
    };
}
