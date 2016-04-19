#include "stdafx.h"
#include "DoubleLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        DoubleLiteralSyntax::DoubleLiteralSyntax(double value)
            : LiteralSyntax<double>(value)
        {
        }
        DoubleLiteralSyntax::~DoubleLiteralSyntax()
        {
        }

        types::RuntimeType* DoubleLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::float64();
        }

        void DoubleLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *)
        {
            //TODO: emit double literal
        }

        void DoubleLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << getValue() << "d";
        }
    }
}
