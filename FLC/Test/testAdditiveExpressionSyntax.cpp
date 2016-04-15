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
            testExpressionType("1 + 2", RuntimeType::int32());
        }
        TEST_METHOD(Test_additive_exprType_addInt64)
        {
            testExpressionType("1l + 2l", RuntimeType::int64());
        }
        TEST_METHOD(Test_additive_exprType_addUInt32)
        {
            testExpressionType("1u + 2u", RuntimeType::uint32());
        }
        TEST_METHOD(Test_additive_exprType_addUInt64)
        {
            testExpressionType("1ul + 2ul", RuntimeType::uint64());
        }

        TEST_METHOD(Test_additive_exprType_subtractInt32)
        {
            testExpressionType("1 - 2", RuntimeType::int32());
        }
        TEST_METHOD(Test_additive_exprType_subtractInt64)
        {
            testExpressionType("1l - 2l", RuntimeType::int64());
        }
        TEST_METHOD(Test_additive_exprType_subtractUInt32)
        {
            testExpressionType("1u - 2u", RuntimeType::uint32());
        }
        TEST_METHOD(Test_additive_exprType_subtractUInt64)
        {
            testExpressionType("1ul - 2ul", RuntimeType::uint64());
        }

        TEST_METHOD(Test_additive_exprType_addFloat)
        {
            testExpressionType("1f + 2f", RuntimeType::float32());
        }
        TEST_METHOD(Test_additive_exprType_addDouble)
        {
            testExpressionType("1d + 2d", RuntimeType::float64());
        }

        TEST_METHOD(Test_additive_exprType_subtractFloat)
        {
            testExpressionType("1f - 2f", RuntimeType::float32());
        }
        TEST_METHOD(Test_additive_exprType_subtractDouble)
        {
            testExpressionType("1d - 2d", RuntimeType::float64());
        }

        TEST_METHOD(Test_additive_exprType_addStringString)
        {
            testExpressionType("\"One \" + \"Two\"", RuntimeType::string());
        }
        TEST_METHOD(Test_additive_exprType_addStringObject)
        {
            testExpressionType("\"One \" + null", RuntimeType::string());
        }
        TEST_METHOD(Test_additive_exprType_addObjectString)
        {
            testExpressionType("null + \"Two\"", RuntimeType::string());
        }
    };
}
