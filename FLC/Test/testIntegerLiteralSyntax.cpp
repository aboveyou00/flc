#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestIntegerLiteralSyntax)
    {
    public:
        TEST_METHOD(Test_integerLiteral_exprType)
        {
            testExpressionType("42", RuntimeType::int32);
        }
    };
}
