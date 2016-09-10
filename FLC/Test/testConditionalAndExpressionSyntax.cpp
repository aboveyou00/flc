#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(ConditonalAndExpressionSyntax)
    {
    public:
        TEST_METHOD(Test_andExpression_exprType_bool8)
        {
            testExpressionType("true && false", RuntimeType::bool8());
        }
    };
}
