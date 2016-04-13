#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestAdditiveExpressionSyntax)
    {
    public:
        TEST_METHOD(Test_additive_exprType_addInt32)
        {
            testExpressionType("1 + 2", RuntimeType::int32);
        }

        TEST_METHOD(Test_additive_exprType_subtractInt32)
        {
            testExpressionType("1 - 2", RuntimeType::int32);
        }
    };
}
