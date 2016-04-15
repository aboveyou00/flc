#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestUIntegerLiteralSyntax)
    {
    public:
        TEST_METHOD(Test_uintLiteral_exprType)
        {
            testExpressionType("25u", RuntimeType::uint32());
        }
    };
}
