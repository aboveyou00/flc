#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(InclusiveOrExpressionSyntax)
    {
    public:
        TEST_METHOD(Test_inclOrExpression_exprType_int32)
        {
            testExpressionType("1 | 3", RuntimeType::int32());
        }
        TEST_METHOD(Test_inclOrExpression_exprType_uint32)
        {
            testExpressionType("1u | 3u", RuntimeType::uint32());
        }
        TEST_METHOD(Test_inclOrExpression_exprType_int64)
        {
            testExpressionType("1l | 3l", RuntimeType::int64());
        }
        TEST_METHOD(Test_inclOrExpression_exprType_uint64)
        {
            testExpressionType("1ul | 3ul", RuntimeType::uint64());
        }

        TEST_METHOD(Test_inclOrExpression_exprType_boolean)
        {
            testExpressionType("true | false", RuntimeType::bool8());
        }
    };
}
