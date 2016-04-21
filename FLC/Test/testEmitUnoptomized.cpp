#include "stdafx.h"
#include <sstream>
#include "testEmitUnoptimized.h"
#include "../FLC/Tokenizer.h"
#include "../FLC/ExpressionSyntax.h"
#include "../FLC/ExpressionSyntaxFactory.h"
#include "../FLC/EndOfFileToken.h"
#include "../FLC/MethodBody.h"

using namespace std;

static flc::emit::MethodBody *method;
static const vector<flc::emit::Instr*> *instructions;
static size_t instrPos;

void UseString(std::string str)
{
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    flc::tokens::Tokenizer tokenizer;
    istringstream stream(str);
    auto toks = tokenizer.tokenize(&stream, "testStr");

    int pos = 0;
    vector<flc::syntax::ExpressionSyntax*> program;
    flc::syntax::factory::ExpressionSyntaxFactory exprFactory;
    while (pos < (int)toks->size() && dynamic_cast<flc::tokens::EndOfFileToken*>(toks->at(pos)) == nullptr)
    {
        flc::syntax::ExpressionSyntax *expr;
        Assert::IsTrue(exprFactory.tryParseSyntax(toks, pos, expr));
        program.push_back(expr);
    }

    flc::types::NameResolutionContextStack ctx;
    for (auto expr : program)
        expr->registerNames(&ctx);
    for (auto expr : program)
        expr->resolveNames(&ctx);
    for (auto expr : program)
        expr->resolveTypes(&ctx);

    method = new flc::emit::MethodBody();
    for (auto expr : program)
    {
        expr->emit(&ctx, method);
        auto exprType = expr->getExpressionType();
        Assert::IsNotNull(exprType);
        if (!exprType->isVoid()) method->emit(new flc::emit::PopInstr());
    }

    for (auto expr : program)
        delete expr;
    program.clear();

    instrPos = 0;
    instructions = method->getInstructions();
}

flc::emit::Instr *__expectInstr()
{
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    Assert::IsTrue(instrPos < instructions->size());
    auto instr = instructions->at(instrPos++);
    Assert::IsNotNull(instr);
    return instr;
}

void ExpectNoMore()
{
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    Assert::AreEqual(instrPos, instructions->size());
    method->deleteInstructions();
    delete method;
}
