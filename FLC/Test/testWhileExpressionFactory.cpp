#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/WhileExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestWhileExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseWhileExpression)
        {
            testFactory<WhileExpressionSyntaxFactory>("while (true) false");
        }
    };
}
