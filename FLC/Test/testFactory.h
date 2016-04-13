#pragma once
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include <sstream>
#include "../FLC/Token.h"
#include "../FLC/Tokenizer.h"
#include "../FLC/ExpressionSyntax.h"

template <typename TFactory>
flc::syntax::ExpressionSyntax* testFactory(const string& original)
{
    return testFactory<TFactory>(original, original);
}
template <typename TFactory>
flc::syntax::ExpressionSyntax* testFactory(const string& original, const string& expected)
{
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    auto tokenizer = flc::tokens::Tokenizer();
    istringstream stream(original);
    auto toks = tokenizer.tokenize(&stream, "test_str");

    auto factory = TFactory();

    int pos = 0;
    flc::syntax::ExpressionSyntax* result;
    Assert::IsTrue(factory.tryParseSyntax(toks, pos, result));
    Assert::IsTrue(pos == (int)toks->size() - 1);

    string resultStr = result->toString();
    Assert::IsTrue(resultStr.compare(expected) == 0);

    return result;
}
