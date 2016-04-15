#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestLongLiteralSyntax)
    {
    public:
        TEST_METHOD(Test_longLiteral_exprType)
        {
            testExpressionType("25l", RuntimeType::int64());
        }
    };
}
