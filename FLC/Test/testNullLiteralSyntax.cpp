#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestNullLiteralSyntax)
    {
    public:
        TEST_METHOD(Test_nullLiteral_exprType)
        {
            testExpressionType("null", RuntimeType::nullLiteral());
        }

        TEST_METHOD(Test_nullLiteral_expectedExprType)
        {
            testExpressionType("null", RuntimeType::string(), RuntimeType::string());
        }

        TEST_METHOD(Test_nullLiteral_expectedValueExprType)
        {
            testExpressionType("null", RuntimeType::nullLiteral(), RuntimeType::int32());
        }
    };
}
