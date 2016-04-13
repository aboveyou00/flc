#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestCharacterLiteralSyntax)
    {
    public:
        TEST_METHOD(Test_compoundExpressionSyntax_exprType_empty)
        {
            testExpressionType("{}", RuntimeType::void0);
        }

        TEST_METHOD(Test_compoundExpressionSyntax_exprType_oneExpr)
        {
            testExpressionType("{1}", RuntimeType::int32);
        }

        TEST_METHOD(Test_compoundExpressionSyntax_exprType_manyExprs)
        {
            testExpressionType("{'1' 2.0 3}", RuntimeType::int32);
        }
    };
}
