#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(EqualityExpressionSyntax)
    {
    public:
        TEST_METHOD(Test_equality_exprType_eqlInt32)
        {
            testExpressionType("1 == 2", RuntimeType::bool8());
        }
        TEST_METHOD(Test_equality_exprType_eqlInt64)
        {
            testExpressionType("1l == 2l", RuntimeType::bool8());
        }
        TEST_METHOD(Test_equality_exprType_eqlUInt32)
        {
            testExpressionType("1u == 2u", RuntimeType::bool8());
        }
        TEST_METHOD(Test_equality_exprType_eqlUInt64)
        {
            testExpressionType("1ul == 2ul", RuntimeType::bool8());
        }

        TEST_METHOD(Test_equality_exprType_eqlFloat)
        {
            testExpressionType("1f == 2f", RuntimeType::bool8());
        }
        TEST_METHOD(Test_equality_exprType_eqlDouble)
        {
            testExpressionType("1d == 2d", RuntimeType::bool8());
        }

        TEST_METHOD(Test_equality_exprType_eqlBoolean)
        {
            testExpressionType("true == false", RuntimeType::bool8());
        }

        TEST_METHOD(Test_equality_exprType_eqlObject)
        {
            testExpressionType("null == null", RuntimeType::bool8());
        }

        TEST_METHOD(Test_equality_exprType_eqlString)
        {
            testExpressionType("\"Hello\" == \"World\"", RuntimeType::bool8());
        }

        TEST_METHOD(Test_equality_exprType_ineqlInt32)
        {
            testExpressionType("1 != 2", RuntimeType::bool8());
        }
        TEST_METHOD(Test_equality_exprType_ineqlInt64)
        {
            testExpressionType("1l != 2l", RuntimeType::bool8());
        }
        TEST_METHOD(Test_equality_exprType_ineqlUInt32)
        {
            testExpressionType("1u != 2u", RuntimeType::bool8());
        }
        TEST_METHOD(Test_equality_exprType_ineqlUInt64)
        {
            testExpressionType("1ul != 2ul", RuntimeType::bool8());
        }

        TEST_METHOD(Test_equality_exprType_ineqlFloat)
        {
            testExpressionType("1f != 2f", RuntimeType::bool8());
        }
        TEST_METHOD(Test_equality_exprType_ineqlDouble)
        {
            testExpressionType("1d != 2d", RuntimeType::bool8());
        }

        TEST_METHOD(Test_equality_exprType_ineqlBoolean)
        {
            testExpressionType("true != false", RuntimeType::bool8());
        }

        TEST_METHOD(Test_equality_exprType_ineqlObject)
        {
            testExpressionType("null != null", RuntimeType::bool8());
        }

        TEST_METHOD(Test_equality_exprType_ineqlString)
        {
            testExpressionType("\"Hello\" != \"World\"", RuntimeType::bool8());
        }
    };
}
