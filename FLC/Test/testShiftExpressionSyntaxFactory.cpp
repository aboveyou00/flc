#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/ShiftExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestShiftExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseShiftExpression_left)
        {
            testFactory<ShiftExpressionSyntaxFactory>("1 << 4");
        }

        TEST_METHOD(Test_parseShiftExpression_right)
        {
            testFactory<ShiftExpressionSyntaxFactory>("16 >> 4");
        }
    };
}
