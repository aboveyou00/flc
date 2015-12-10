#include "stdafx.h"
#include "CppUnitTest.h"
#include "../FLC/Tokenizer.h"
#include "../FLC/KeywordToken.h"
#include "../FLC/BooleanLiteralToken.h"
#include "../FLC/NullLiteralToken.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
    TEST_CLASS(TestCompiler)
    {
    public:

        TEST_METHOD(Test_tokenize_arithmetic)
        {
            using namespace flc::tokens;

            Tokenizer tokenizer;
            istringstream stream("  1 +      2 \r\n+  3 */- ");

            auto toks = tokenizer.tokenize(&stream);
            Assert::IsTrue(toks->size() == 9);
            Assert::AreEqual(toks->at(0)->toString(), (std::string)"1");
            Assert::AreEqual(toks->at(1)->toString(), (std::string)"+");
            Assert::AreEqual(toks->at(2)->toString(), (std::string)"2");
            Assert::AreEqual(toks->at(3)->toString(), (std::string)"+");
            Assert::AreEqual(toks->at(4)->toString(), (std::string)"3");
            Assert::AreEqual(toks->at(5)->toString(), (std::string)"*");
            Assert::AreEqual(toks->at(6)->toString(), (std::string)"/");
            Assert::AreEqual(toks->at(7)->toString(), (std::string)"-");
            Assert::AreEqual(toks->at(8)->toString(), (std::string)"EOF");
        }
        TEST_METHOD(Test_tokenize_strings)
        {
            using namespace flc::tokens;

            Tokenizer tokenizer;
            istringstream stream(" \"Hello, World!\" \"Hello,\\r\\nWorld!\" (\"blah blah blah blah blah\") ");

            auto toks = tokenizer.tokenize(&stream);
            Assert::IsTrue(toks->size() == 6);
            Assert::AreEqual(toks->at(0)->toString(), (std::string)"\"Hello, World!\"");
            Assert::AreEqual(toks->at(1)->toString(), (std::string)"\"Hello,\r\nWorld!\"");
            Assert::AreEqual(toks->at(2)->toString(), (std::string)"(");
            Assert::AreEqual(toks->at(3)->toString(), (std::string)"\"blah blah blah blah blah\"");
            Assert::AreEqual(toks->at(4)->toString(), (std::string)")");
            Assert::AreEqual(toks->at(5)->toString(), (std::string)"EOF");
        }
        TEST_METHOD(Test_tokenize_identifiers)
        {
            using namespace flc::tokens;

            Tokenizer tokenizer;
            istringstream stream(" one two three _blah true false null __abc012 default int do while ");

            auto toks = tokenizer.tokenize(&stream);
            Assert::IsTrue(toks->size() == 13);
            Assert::AreEqual(toks->at(0)->toString(), (std::string)"one");
                Assert::IsNull(dynamic_cast<KeywordToken*>(toks->at(0)));
            Assert::AreEqual(toks->at(1)->toString(), (std::string)"two");
            Assert::AreEqual(toks->at(2)->toString(), (std::string)"three");
            Assert::AreEqual(toks->at(3)->toString(), (std::string)"_blah");

            Assert::AreEqual(toks->at(4)->toString(), (std::string)"true");
                Assert::IsNotNull(dynamic_cast<BooleanLiteralToken*>(toks->at(4)));
            Assert::AreEqual(toks->at(5)->toString(), (std::string)"false");
                Assert::IsNotNull(dynamic_cast<BooleanLiteralToken*>(toks->at(5)));
            Assert::AreEqual(toks->at(6)->toString(), (std::string)"null");
                Assert::IsNotNull(dynamic_cast<NullLiteralToken*>(toks->at(6)));

            Assert::AreEqual(toks->at(7)->toString(), (std::string)"__abc012");

            Assert::AreEqual(toks->at(8)->toString(), (std::string)"default");
                Assert::IsNotNull(dynamic_cast<KeywordToken*>(toks->at(8)));
            Assert::AreEqual(toks->at(9)->toString(), (std::string)"int");
                Assert::IsNotNull(dynamic_cast<KeywordToken*>(toks->at(9)));
            Assert::AreEqual(toks->at(10)->toString(), (std::string)"do");
                Assert::IsNotNull(dynamic_cast<KeywordToken*>(toks->at(10)));
            Assert::AreEqual(toks->at(11)->toString(), (std::string)"while");
                Assert::IsNotNull(dynamic_cast<KeywordToken*>(toks->at(11)));
            
            Assert::AreEqual(toks->at(12)->toString(), (std::string)"EOF");
        }
        TEST_METHOD(Test_tokenize_characters)
        {
            using namespace flc::tokens;

            Tokenizer tokenizer;
            istringstream stream(" '1' '2' '3' '\\t' '\\127' '\\x3F' ");

            auto toks = tokenizer.tokenize(&stream);
            Assert::IsTrue(toks->size() == 7);
            Assert::AreEqual(toks->at(0)->toString(), (std::string)"'1'");
            Assert::AreEqual(toks->at(1)->toString(), (std::string)"'2'");
            Assert::AreEqual(toks->at(2)->toString(), (std::string)"'3'");
            Assert::AreEqual(toks->at(3)->toString(), (std::string)"'\t'");
            Assert::AreEqual(toks->at(4)->toString(), (std::string)"'\127'");
            Assert::AreEqual(toks->at(5)->toString(), (std::string)"'\x3F'");
            Assert::AreEqual(toks->at(6)->toString(), (std::string)"EOF");
        }

        //TODO: test tokenizer error messages

    };
}
