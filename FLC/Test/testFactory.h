#pragma once
#include "CppUnitTest.h"
#include <string>
#include <sstream>
#include "../FLC/Tokenizer.h"
#include "../FLC/ExpressionSyntax.h"

template <typename TFactory>
flc::syntax::ExpressionSyntax* testFactory(const string& original, const string& expected)
{
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    flc::tokens::Tokenizer tokenizer;
    istringstream stream(original);
    auto toks = tokenizer.tokenize(&stream, "test_str");

    int pos = 0;
    TFactory factory;
    flc::syntax::ExpressionSyntax* result;
    Assert::IsTrue(factory.tryParseSyntax(toks, pos, result));
    Assert::IsTrue(pos == (int)toks->size() - 1);

    string resultStr = result->toString();
    Assert::IsTrue(resultStr.compare(expected) == 0);

    //for (size_t q = 0; q < toks->size(); q++)
    //    delete toks->at(q);
    //toks->clear();
    //delete toks;

    return result;
}
template <typename TFactory>
flc::syntax::ExpressionSyntax* testFactory(const string& original)
{
    return testFactory<TFactory>(original, original);
}
