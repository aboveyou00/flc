#include "stdafx.h"
#include "CppUnitTest.h"
#include "testFactory.h"
#include "../FLC/TermSyntaxFactory.h"

using namespace flc::syntax::factory;

namespace Test
{
    TEST_CLASS(TestTermSyntaxFactory)
    {
    public:
        TEST_METHOD(Test_parseTerm_compoundExpression)
        {
            testFactory<TermSyntaxFactory>("{\r\n    true\r\n    false\r\n    1 + 2\r\n}");
        }

        TEST_METHOD(Test_parseTerm_memberAccess)
        {
            testFactory<TermSyntaxFactory>("one.two.three");
        }

        TEST_METHOD(Test_parseTerm_parenthesizedExpression)
        {
            testFactory<TermSyntaxFactory>("(true)", "true");
        }

        TEST_METHOD(Test_parseTerm_identifier)
        {
            testFactory<TermSyntaxFactory>("test");
        }

        TEST_METHOD(Test_parseTerm_int)
        {
            testFactory<TermSyntaxFactory>("32");
        }

        TEST_METHOD(Test_parseTerm_float)
        {
            testFactory<TermSyntaxFactory>("42.1");
        }

        TEST_METHOD(Test_parseTerm_bool)
        {
            testFactory<TermSyntaxFactory>("true");
        }

        TEST_METHOD(Test_parseTerm_char)
        {
            testFactory<TermSyntaxFactory>("'a'");
        }

        TEST_METHOD(Test_parseTerm_string)
        {
            testFactory<TermSyntaxFactory>("\"My String\"");
        }

        TEST_METHOD(Test_parseTerm_null)
        {
            testFactory<TermSyntaxFactory>("null");
        }
    };
}
