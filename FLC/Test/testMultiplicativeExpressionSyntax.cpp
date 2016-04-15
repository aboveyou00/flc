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
            testExpressionType("1 * 2", RuntimeType::int32());
        }
        TEST_METHOD(Test_multiplicative_exprType_multiplyUInt32)
        {
            testExpressionType("1u * 2u", RuntimeType::uint32());
        }
        TEST_METHOD(Test_multiplicative_exprType_multiplyInt64)
        {
            testExpressionType("1l * 2l", RuntimeType::int64());
        }
        TEST_METHOD(Test_multiplicative_exprType_multiplyUInt64)
        {
            testExpressionType("1ul * 2ul", RuntimeType::uint64());
        }

        TEST_METHOD(Test_multiplicative_exprType_multiplyFloat)
        {
            testExpressionType("1f * 2f", RuntimeType::float32());
        }
        TEST_METHOD(Test_multiplicative_exprType_multiplyDouble)
        {
            testExpressionType("1d * 2d", RuntimeType::float64());
        }

        TEST_METHOD(Test_multiplicative_exprType_divideInt32)
        {
            testExpressionType("1 / 2", RuntimeType::int32());
        }
        TEST_METHOD(Test_multiplicative_exprType_divideUInt32)
        {
            testExpressionType("1u / 2u", RuntimeType::uint32());
        }
        TEST_METHOD(Test_multiplicative_exprType_divideInt64)
        {
            testExpressionType("1l / 2l", RuntimeType::int64());
        }
        TEST_METHOD(Test_multiplicative_exprType_divideUInt64)
        {
            testExpressionType("1ul / 2ul", RuntimeType::uint64());
        }

        TEST_METHOD(Test_multiplicative_exprType_divideFloat)
        {
            testExpressionType("1f / 2f", RuntimeType::float32());
        }
        TEST_METHOD(Test_multiplicative_exprType_divideDouble)
        {
            testExpressionType("1d / 2d", RuntimeType::float64());
        }

        TEST_METHOD(Test_multiplicative_exprType_modulusInt32)
        {
            testExpressionType("1 % 2", RuntimeType::int32());
        }
        TEST_METHOD(Test_multiplicative_exprType_modulusUInt32)
        {
            testExpressionType("1u % 2u", RuntimeType::uint32());
        }
        TEST_METHOD(Test_multiplicative_exprType_modulusInt64)
        {
            testExpressionType("1l % 2l", RuntimeType::int64());
        }
        TEST_METHOD(Test_multiplicative_exprType_modulusUInt64)
        {
            testExpressionType("1ul % 2ul", RuntimeType::uint64());
        }

        TEST_METHOD(Test_multiplicative_exprType_modulusFloat)
        {
            testExpressionType("1f % 2f", RuntimeType::float32());
        }
        TEST_METHOD(Test_multiplicative_exprType_modulusDouble)
        {
            testExpressionType("1d % 2d", RuntimeType::float64());
        }
    };
}
