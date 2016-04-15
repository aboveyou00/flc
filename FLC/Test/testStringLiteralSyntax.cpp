#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestStringLiteralSyntax)
    {
    public:
        TEST_METHOD(Test_stringLiteral_exprType)
        {
            testExpressionType("\"Hello, World!\"", RuntimeType::string());
        }
    };
}
