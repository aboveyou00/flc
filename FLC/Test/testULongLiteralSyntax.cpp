#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestULongLiteralSyntax)
    {
    public:
        TEST_METHOD(Test_ulongLiteral_exprType)
        {
            testExpressionType("25ul", RuntimeType::uint64());
        }
    };
}
