#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(ConditonalOrExpressionSyntax)
    {
    public:
        TEST_METHOD(Test_orExpression_exprType_bool8)
        {
            testExpressionType("true || false", RuntimeType::bool8());
        }
    };
}
