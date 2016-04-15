#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"

using namespace flc::types;

namespace Test
{
    TEST_CLASS(TestCharacterLiteralSyntax)
    {
    public:
        TEST_METHOD(Test_characterLiteral_exprType)
        {
            testExpressionType("'a'", RuntimeType::char16());
        }
    };
}
