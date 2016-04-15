#include "stdafx.h"
#include "CppUnitTest.h"
#include "../FLC/Tokenizer.h"
#include <sstream>

#include "../FLC/SymbolToken.h"
#include "../FLC/IdentifierToken.h"
#include "../FLC/KeywordToken.h"
#include "../FLC/BooleanLiteralToken.h"
#include "../FLC/IntegerLiteralToken.h"
#include "../FLC/FloatLiteralToken.h"
#include "../FLC/CharacterLiteralToken.h"
#include "../FLC/StringLiteralToken.h"
#include "../FLC/NullLiteralToken.h"

#include "../FLC/ErrorToken.h"
#include "../FLC/EndOfFileToken.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace flc::tokens;

namespace Test
{
    TEST_CLASS(Compiler)
    {
    public:

        TEST_METHOD(Test_tokenize_empty)
        {
            UseString("     ");

            ExpectNoMore();
        }

        TEST_METHOD(Test_tokenize_comments)
        {
            UseString("  //A comment!  \r\n  /*   A \r\n multi-line \r\n comment! */   ");

            ExpectNoMore();
        }

        TEST_METHOD(Test_tokenize_arithmetic)
        {
            UseString("  1 +      2 \r\n+  10 8 */-   ");

            ExpectToken<IntegerLiteralToken>("1");
            ExpectToken<SymbolToken>("+");
            ExpectToken<IntegerLiteralToken>("2");
            ExpectToken<SymbolToken>("+");
            ExpectToken<IntegerLiteralToken>("10");
            ExpectToken<IntegerLiteralToken>("8");
            ExpectToken<SymbolToken>("*");
            ExpectToken<SymbolToken>("/");
            ExpectToken<SymbolToken>("-");

            ExpectNoMore();
        }

        TEST_METHOD(Test_tokenize_integerLiterals)
        {
            UseString("  1 0b10 0xA 0o10  ");

            ExpectToken<IntegerLiteralToken>("1");
            ExpectToken<IntegerLiteralToken>("2");
            ExpectToken<IntegerLiteralToken>("10");
            ExpectToken<IntegerLiteralToken>("8");

            ExpectNoMore();
        }

        TEST_METHOD(Test_tokenize_floatingPointLiterals)
        {
            UseString("  1.0 2f .3  ");

            ExpectToken<FloatLiteralToken>("1f");
            ExpectToken<FloatLiteralToken>("2f");
            ExpectToken<FloatLiteralToken>("0.3f");

            ExpectNoMore();
        }

        TEST_METHOD(Test_tokenize_strings)
        {
            UseString(" \"Hello, World!\" \"Hello,\\r\\nWorld!\" (\"blah blah blah blah blah\") ");

            ExpectToken<StringLiteralToken>("\"Hello, World!\"");
            ExpectToken<StringLiteralToken>("\"Hello,\r\nWorld!\"");
            ExpectToken<SymbolToken>("(");
            ExpectToken<StringLiteralToken>("\"blah blah blah blah blah\"");
            ExpectToken<SymbolToken>(")");

            ExpectNoMore();
        }
        TEST_METHOD(Test_tokenize_identifiers)
        {
            UseString(" one two three _blah true false null __abc012 default int do while ");

            ExpectToken<IdentifierToken>("one");
            ExpectToken<IdentifierToken>("two");
            ExpectToken<IdentifierToken>("three");
            ExpectToken<IdentifierToken>("_blah");

            ExpectToken<BooleanLiteralToken>("true");
            ExpectToken<BooleanLiteralToken>("false");
            ExpectToken<NullLiteralToken>("null");

            ExpectToken<IdentifierToken>("__abc012");

            ExpectToken<KeywordToken>("default");
            ExpectToken<KeywordToken>("int");
            ExpectToken<KeywordToken>("do");
            ExpectToken<KeywordToken>("while");

            ExpectNoMore();
        }
        TEST_METHOD(Test_tokenize_characters)
        {
            UseString(" '1' '2' '3' '\\t' '\\127' '\\x3F' ");

            ExpectToken<CharacterLiteralToken>("'1'");
            ExpectToken<CharacterLiteralToken>("'2'");
            ExpectToken<CharacterLiteralToken>("'3'");
            ExpectToken<CharacterLiteralToken>("'\t'");
            ExpectToken<CharacterLiteralToken>("'\127'");
            ExpectToken<CharacterLiteralToken>("'\x3f'");

            ExpectNoMore();
        }

        TEST_METHOD(Test_tokenize_eof)
        {
            UseString("true");

            ExpectToken<BooleanLiteralToken>("true");
            
            ExpectNoMore();
        }

        //TODO: test tokenizer error messages



    private:
        std::vector<flc::tokens::Token*>* toks;
        int idx = 0;
        void UseString(std::string str)
        {
            Tokenizer tokenizer;
            istringstream stream(str);
            toks = tokenizer.tokenize(&stream);
            idx = 0;
        }
        template <typename T>
        T* ExpectToken(std::string expected)
        {
            auto tok = this->toks->at(this->idx++);
            if (expected.compare("") != 0) Assert::AreEqual(tok->toString(), expected);
            T* ttok = dynamic_cast<T*>(tok);
            Assert::IsNotNull(ttok);
            return ttok;
        }
        template <typename T>
        T* ExpectToken()
        {
            return ExpectToken<T>("");
        }
        void ExpectNoMore()
        {
            this->ExpectToken<flc::tokens::EndOfFileToken>();
            Assert::IsTrue(this->idx == (int)this->toks->size());
            delete toks;
        }
    };
}
