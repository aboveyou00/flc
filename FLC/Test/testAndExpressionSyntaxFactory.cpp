#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/AndExpressionSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestAndExpressionSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseAndExpression)
        {
            testFactory<AndExpressionSyntaxFactory>("true & false");
        }
    };
}
