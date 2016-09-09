#include "stdafx.h"
#include "MethodBody.h"
#include "NopInstr.h"
#include <assert.h>

namespace flc
{
    namespace emit
    {
        MethodBody::MethodBody()
            : finalized(false)
        {
        }
        MethodBody::~MethodBody()
        {
        }

        void MethodBody::emit(Instr *instr)
        {
            assert(!finalized);
            for (size_t q = 0; q < decorators.size(); q++)
            {
                auto decorator = decorators[q];
                instr->addDecorator(decorator);
            }
            decorators.clear();
            instructions.push_back(instr);
        }
        void MethodBody::emitDecorator(InstrDecorator *decorator)
        {
            assert(!finalized);
            decorators.push_back(decorator);
        }
        void MethodBody::finalize()
        {
            if (finalized) return;
            if (decorators.size() != 0) emit(new NopInstr());
            finalized = true;
        }

        void MethodBody::deleteInstructions()
        {
            finalize();
            for (size_t q = 0; q < instructions.size(); q++)
            {
                auto instr = instructions[q];
                delete instr;
            }
            instructions.clear();
        }
        const vector<Instr*> *MethodBody::getInstructions()
        {
            finalize();
            return &instructions;
        }

        string MethodBody::toString()
        {
            stringstream stream;
            for (auto instr : instructions)
            {
                instr->stringify(&stream);
                stream << endl;
            }
            return stream.str();
        }
    }
}
