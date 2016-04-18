#include "stdafx.h"
#include "CppUnitTest.h"
#include "testExpressionType.h"
#include <sstream>
#include "../FLC/Tokenizer.h"
#include "../FLC/ExpressionSyntax.h"
#include "../FLC/ExpressionSyntaxFactory.h"

void testExpressionType(const string& expression, flc::types::RuntimeType* expectedType)
{
    return testExpressionType(expression, expectedType, nullptr);
}
void testExpressionType(const string& expression, flc::types::RuntimeType* expectedType, flc::types::RuntimeType* suggestedType)
{
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    flc::tokens::Tokenizer tokenizer;
    istringstream stream(expression);
    auto toks = tokenizer.tokenize(&stream, "test_str");

    int pos = 0;
    flc::syntax::factory::ExpressionSyntaxFactory factory;
    flc::syntax::ExpressionSyntax* result;
    Assert::IsTrue(factory.tryParseSyntax(toks, pos, result));
    Assert::IsTrue(pos == (int)toks->size() - 1); //Sanity check

    if (suggestedType != nullptr) result->suggestExpressionType(suggestedType);
    flc::types::NameResolutionContextStack ctx;
    result->resolveTypes(&ctx);
    auto resultType = result->getExpressionType();

    if (expectedType == nullptr) Assert::IsNull(resultType);
    else Assert::IsTrue(expectedType->isSameAs(resultType));

    //for (size_t q = 0; q < toks->size(); q++)
    //    delete toks->at(q);
    //toks->clear();
    //delete toks;
}
