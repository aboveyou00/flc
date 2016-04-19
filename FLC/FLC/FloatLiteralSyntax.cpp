#include "stdafx.h"
#include "FloatLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        FloatLiteralSyntax::FloatLiteralSyntax(float value)
            : LiteralSyntax<float>(value)
        {
        }
        FloatLiteralSyntax::~FloatLiteralSyntax()
        {
        }

        types::RuntimeType* FloatLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::float32();
        }

        void FloatLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *)
        {
            //TODO: emit float literal
        }

        void FloatLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << getValue() << "f";
        }
    }
}
