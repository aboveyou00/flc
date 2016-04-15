#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestDoubleLiteralSyntax)
    {
    public:
        TEST_METHOD(Test_doubleLiteral_exprType)
        {
            testExpressionType("1.2d", RuntimeType::float64());
        }
    };
}
