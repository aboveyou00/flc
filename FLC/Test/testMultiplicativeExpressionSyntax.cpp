#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestAdditiveExpressionSyntax)
    {
    public:
        TEST_METHOD(Test_multiplicative_exprType_multiplyInt32)
        {
            testExpressionType("1 * 2", RuntimeType::int32);
        }

        TEST_METHOD(Test_multiplicative_exprType_divideInt32)
        {
            testExpressionType("1 / 2", RuntimeType::int32);
        }

        TEST_METHOD(Test_multiplicative_exprType_modulusInt32)
        {
            testExpressionType("1 % 2", RuntimeType::int32);
        }
    };
}
