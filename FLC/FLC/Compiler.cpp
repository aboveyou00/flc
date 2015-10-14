#include "stdafx.h"
#include "Compiler.h"
#include "Tokenizer.h"
#include <fstream>

namespace flc
{
    Compiler::Compiler()
    {

    }
    Compiler::~Compiler()
    {

    }

    bool Compiler::tryAddSourceFile(string path)
    {
        ifstream stream(path); //ifstream::in
        if (!stream.is_open()) return false;
        
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
