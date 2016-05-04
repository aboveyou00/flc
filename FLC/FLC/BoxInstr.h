#pragma once
#include "Instr.h"

namespace flc
{
    namespace types
    {
        class RuntimeType;
    }

    namespace emit
    {
        class BoxInstr : public Instr
        {
        public:
            BoxInstr(types::RuntimeType *type);
            ~BoxInstr();

            types::RuntimeType *getBoxType();

            void stringify(std::stringstream *stream) override;

        private:
            types::RuntimeType *boxType;
        };
    }
}

//8C <type>   box <type>
