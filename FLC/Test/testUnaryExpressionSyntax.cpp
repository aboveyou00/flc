#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(UnaryExpressionSyntax)
    {
    public:
        TEST_METHOD(Test_unaryExpression_exprType_logicalNot)
        {
            testExpressionType("!true", RuntimeType::bool8);
        }

        TEST_METHOD(Test_unaryExpression_exprType_int32Negation)
        {
            testExpressionType("-3", RuntimeType::int32);
        }
        TEST_METHOD(Test_unaryExpression_exprType_int64Negation)
        {
            testExpressionType("-3l", RuntimeType::int64);
        }

        TEST_METHOD(Test_unaryExpression_exprType_floatNegation)
        {
            testExpressionType("-3f", RuntimeType::float32);
        }
        TEST_METHOD(Test_unaryExpression_exprType_doubleNegation)
        {
            testExpressionType("-3d", RuntimeType::float64);
        }

        TEST_METHOD(Test_unaryExpression_exprType_int32Plus)
        {
            testExpressionType("+3", RuntimeType::int32);
        }
        TEST_METHOD(Test_unaryExpression_exprType_uint32Plus)
        {
            testExpressionType("+3u", RuntimeType::uint32);
        }
        TEST_METHOD(Test_unaryExpression_exprType_int64Plus)
        {
            testExpressionType("+3l", RuntimeType::int64);
        }
        TEST_METHOD(Test_unaryExpression_exprType_uint64Plus)
        {
            testExpressionType("+3ul", RuntimeType::uint64);
        }

        TEST_METHOD(Test_unaryExpression_exprType_floatPlus)
        {
            testExpressionType("+3f", RuntimeType::float32);
        }
        TEST_METHOD(Test_unaryExpression_exprType_doublePlus)
        {
            testExpressionType("+3d", RuntimeType::float64);
        }

        TEST_METHOD(Test_unaryExpression_exprType_int32Complement)
        {
            testExpressionType("~3", RuntimeType::int32);
        }
        TEST_METHOD(Test_unaryExpression_exprType_uint32Complement)
        {
            testExpressionType("~3u", RuntimeType::uint32);
        }
        TEST_METHOD(Test_unaryExpression_exprType_int64Complement)
        {
            testExpressionType("~3l", RuntimeType::int64);
        }
        TEST_METHOD(Test_unaryExpression_exprType_uint64Complement)
        {
            testExpressionType("~3ul", RuntimeType::uint64);
        }

        //TODO: test Increment
        //TODO: test Decrement
        //TODO: test Explicit
        //TODO: test Implicit (not really a unary operator)
    };
}
