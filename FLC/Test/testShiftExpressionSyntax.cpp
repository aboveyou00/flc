#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(ShiftExpressionSyntax)
    {
    public:
        TEST_METHOD(Test_unaryExpression_exprType_int32ShiftLeft)
        {
            testExpressionType("1 << 2", RuntimeType::int32());
        }
        TEST_METHOD(Test_unaryExpression_exprType_uint32ShiftLeft)
        {
            testExpressionType("1u << 2", RuntimeType::uint32());
        }
        TEST_METHOD(Test_unaryExpression_exprType_int64ShiftLeft)
        {
            testExpressionType("1l << 2", RuntimeType::int64());
        }
        TEST_METHOD(Test_unaryExpression_exprType_uint64ShiftLeft)
        {
            testExpressionType("1ul << 2", RuntimeType::uint64());
        }

        TEST_METHOD(Test_unaryExpression_exprType_int32ShiftRight)
        {
            testExpressionType("4 >> 2", RuntimeType::int32());
        }
        TEST_METHOD(Test_unaryExpression_exprType_uint32ShiftRight)
        {
            testExpressionType("4u >> 2", RuntimeType::uint32());
        }
        TEST_METHOD(Test_unaryExpression_exprType_int64ShiftRight)
        {
            testExpressionType("4l >> 2", RuntimeType::int64());
        }
        TEST_METHOD(Test_unaryExpression_exprType_uint64ShiftRight)
        {
            testExpressionType("4ul >> 2", RuntimeType::uint64());
        }
    };
}
