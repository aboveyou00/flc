#include "stdafx.h"
#include "MemberAccessExpressionSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        MemberAccessExpressionSyntax::MemberAccessExpressionSyntax(ExpressionSyntax* term, string identifier)
        {
            _lhs = term;
            ident = identifier;
        }
        MemberAccessExpressionSyntax::~MemberAccessExpressionSyntax()
        {
            if (_lhs != nullptr) delete _lhs;
            _lhs = nullptr;
        }

        int MemberAccessExpressionSyntax::getPrecedence()
        {
            return 0;
        }

        bool MemberAccessExpressionSyntax::isQualifiedName()
        {
            return _lhs->isQualifiedName();
        }

        void MemberAccessExpressionSyntax::resolveTypes(types::NameResolutionContextStack *)
        {
            //TODO: Implement
        }
        types::RuntimeType* MemberAccessExpressionSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
        }

        void MemberAccessExpressionSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *)
        {
            //TODO: Implement
        }

        void MemberAccessExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _lhs->stringify(stream, tabulation);
            *stream << ".";
            *stream << ident;
        }
    }
}
