#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestBooleanLiteralSyntax)
    {
    public:
        TEST_METHOD(Test_booleanLiteral_exprType)
        {
            testExpressionType("true", RuntimeType::bool8());
        }
    };
}
