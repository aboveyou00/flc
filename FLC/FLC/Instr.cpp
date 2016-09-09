#include "stdafx.h"
#include "Instr.h"
#include "InstrDecorator.h"

namespace flc
{
    namespace emit
    {
        Instr::Instr()
        {
        }
        Instr::~Instr()
        {
        }

        void Instr::addDecorator(InstrDecorator *decorator)
        {
            decorators.push_back(decorator);
        }
        const std::vector<InstrDecorator*> &Instr::getDecorators() const
        {
            return decorators;
        }

        void Instr::stringify(std::stringstream *stream)
        {
            for (size_t q = 0; q < decorators.size(); q++)
            {
                auto decorator = decorators[q];
                decorator->stringify(stream);
                *stream << ": ";
            }
            *stream << opcode();
        }
        std::string Instr::toString()
        {
            stringstream stream;
            stringify(&stream);
            return stream.str();
        }
    }
}
