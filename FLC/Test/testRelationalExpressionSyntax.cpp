#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestRelationalExpressionSyntax)
    {
    public:
        TEST_METHOD(Test_relational_exprType_ltInt32)
        {
            testExpressionType("1 < 2", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_ltInt64)
        {
            testExpressionType("1l < 2l", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_ltUInt32)
        {
            testExpressionType("1u < 2u", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_ltUInt64)
        {
            testExpressionType("1ul < 2ul", RuntimeType::bool8());
        }

        TEST_METHOD(Test_relational_exprType_ltFloat)
        {
            testExpressionType("1f < 2f", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_ltDouble)
        {
            testExpressionType("1d < 2d", RuntimeType::bool8());
        }

        TEST_METHOD(Test_relational_exprType_gtInt32)
        {
            testExpressionType("1 > 2", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_gtInt64)
        {
            testExpressionType("1l > 2l", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_gtUInt32)
        {
            testExpressionType("1u > 2u", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_gtUInt64)
        {
            testExpressionType("1ul > 2ul", RuntimeType::bool8());
        }

        TEST_METHOD(Test_relational_exprType_gtFloat)
        {
            testExpressionType("1f > 2f", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_gtDouble)
        {
            testExpressionType("1d > 2d", RuntimeType::bool8());
        }

        TEST_METHOD(Test_relational_exprType_lteInt32)
        {
            testExpressionType("1 <= 2", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_lteInt64)
        {
            testExpressionType("1l <= 2l", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_lteUInt32)
        {
            testExpressionType("1u <= 2u", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_lteUInt64)
        {
            testExpressionType("1ul <= 2ul", RuntimeType::bool8());
        }

        TEST_METHOD(Test_relational_exprType_lteFloat)
        {
            testExpressionType("1f <= 2f", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_lteDouble)
        {
            testExpressionType("1d <= 2d", RuntimeType::bool8());
        }

        TEST_METHOD(Test_relational_exprType_gteInt32)
        {
            testExpressionType("1 >= 2", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_gteInt64)
        {
            testExpressionType("1l >= 2l", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_gteUInt32)
        {
            testExpressionType("1u >= 2u", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_gteUInt64)
        {
            testExpressionType("1ul >= 2ul", RuntimeType::bool8());
        }

        TEST_METHOD(Test_relational_exprType_gteFloat)
        {
            testExpressionType("1f >= 2f", RuntimeType::bool8());
        }
        TEST_METHOD(Test_relational_exprType_gteDouble)
        {
            testExpressionType("1d >= 2d", RuntimeType::bool8());
        }
    };
}
