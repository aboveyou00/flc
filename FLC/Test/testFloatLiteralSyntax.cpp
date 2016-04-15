#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestFloatLiteralSyntax)
    {
    public:
        TEST_METHOD(Test_floatLiteral_exprType)
        {
            testExpressionType("1.2", RuntimeType::float32());
        }
    };
}
