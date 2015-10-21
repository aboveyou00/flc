#include "stdafx.h"
#include "Compiler.h"
#include "Tokenizer.h"
#include <fstream>
#include <sstream>

namespace flc
{
    Compiler::Compiler()
    {

    }
    Compiler::~Compiler()
    {

    }

    bool Compiler::tryAddSource(string source, string path)
    {
        istringstream stream(source);
        return tryAddSource(&stream);
    }
    bool Compiler::tryAddSource(istream *source, string path)
    {
        auto tokenizer = new tokens::Tokenizer();
        vector<tokens::Token> toks = tokenizer->tokenize(source);

        reportNotImplemented();
        throw 20;
    }
    bool Compiler::tryAddSourceFile(string path)
    {
        ifstream stream(path); //ifstream::in
        if (!stream.is_open()) return false;
        return Compiler::tryAddSource((istream*)&stream);

        auto tokenizer = new tokens::Tokenizer();
        vector<tokens::Token> toks = tokenizer->tokenize(&stream);

        reportNotImplemented();
        throw 20;
    }

    bool Compiler::tryCompile()
    {
        reportNotImplemented();
        throw 20;
    }
}
