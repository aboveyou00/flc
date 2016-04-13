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
        TEST_METHOD(Test_parseTerm_compoundExpression_empty)
        {
            testFactory<TermSyntaxFactory>("{}", "{\r\n}");
        }

        TEST_METHOD(Test_parseTerm_compoundExpression_one)
        {
            testFactory<TermSyntaxFactory>("{1}", "{\r\n    1\r\n}");
        }

        TEST_METHOD(Test_parseTerm_compoundExpression_many)
        {
            testFactory<TermSyntaxFactory>("{'1' 2.1 3}", "{\r\n    '1'\r\n    2.1f\r\n    3\r\n}");
        }

        TEST_METHOD(Test_parseTerm_compoundExpression_formatted)
        {
            testFactory<TermSyntaxFactory>("{\r\n    true\r\n    false\r\n    1 + 2\r\n}");
        }

        TEST_METHOD(Test_parseTerm_simpleName)
        {
            testFactory<TermSyntaxFactory>("one");
        }

        TEST_METHOD(Test_parseTerm_complexName)
        {
            testFactory<TermSyntaxFactory>("one.two.three");
        }

        TEST_METHOD(Test_parseTerm_qualifiedName)
        {
            testFactory<TermSyntaxFactory>("MyNamespace::MyClass");
        }

        TEST_METHOD(Test_parseTerm_fullyQualifiedMemberAccess)
        {
            testFactory<TermSyntaxFactory>(":::MyNamespace::MyClass.fieldName");
        }

        TEST_METHOD(Test_parseTerm_parenthesizedExpression)
        {
            testFactory<TermSyntaxFactory>("(true)", "true");
        }

        TEST_METHOD(Test_parseTerm_int)
        {
            testFactory<TermSyntaxFactory>("32");
        }

        TEST_METHOD(Test_parseTerm_float)
        {
            testFactory<TermSyntaxFactory>("42.1", "42.1f");
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
