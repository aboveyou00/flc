#include "stdafx.h"
#include "ComplexNameSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        ComplexNameSyntax::ComplexNameSyntax(ExpressionSyntax* baseExpr, string ident)
            : _lhs(baseExpr), _name(ident)
        {
        }
        ComplexNameSyntax::~ComplexNameSyntax()
        {
            if (_lhs != nullptr) delete _lhs;
            _lhs = nullptr;
        }

        string ComplexNameSyntax::getName()
        {
            return _name;
        }
        ExpressionSyntax* ComplexNameSyntax::getBaseExpression()
        {
            return _lhs;
        }

        bool ComplexNameSyntax::isQualifiedName()
        {
            return true;
        }

        void ComplexNameSyntax::resolveTypes(types::NameResolutionContextStack *)
        {
            //TODO: Implement
        }
        types::RuntimeType* ComplexNameSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
        }

        void ComplexNameSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *)
        {
            //TODO: Implement
        }

        void ComplexNameSyntax::stringify(stringstream* stream, int tabulation)
        {
            _lhs->stringify(stream, tabulation);
            *stream << "::";
            *stream << _name;
        }
    }
}
