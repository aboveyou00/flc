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
        TEST_METHOD(Test_parseWhileExpression_while)
        {
            testFactory<WhileExpressionSyntaxFactory>("while (true) false");
        }

        TEST_METHOD(Test_parseWhileExpression_until)
        {
            testFactory<WhileExpressionSyntaxFactory>("until (false) true");
        }
    };
}
