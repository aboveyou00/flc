#include "stdafx.h"
#include "TermSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        TermSyntax::TermSyntax()
        {
            _type = TermType::NullLiteral;
        }
        TermSyntax::TermSyntax(string str, bool isIdentifier)
        {
            strval = str;
            _type = (isIdentifier ? TermType::Identifier : TermType::StringLiteral);
        }
        TermSyntax::TermSyntax(char16_t val)
        {
            chrval = val;
            _type = TermType::CharacterLiteral;
        }
        TermSyntax::TermSyntax(uint32_t val)
        {
            intval = val;
            _type = TermType::IntegerLiteral;
        }
        TermSyntax::TermSyntax(bool val)
        {
            boolval = val;
            _type = TermType::BooleanLiteral;
        }
        TermSyntax::TermSyntax(float val)
        {
            floatval = val;
            _type = TermType::FloatLiteral;
        }
        TermSyntax::~TermSyntax()
        {
        }



        TermType TermSyntax::getType()
        {
            return _type;
        }

        string TermSyntax::toString()
        {
            stringstream stream;
            switch (_type)
            {
            case TermType::BooleanLiteral:
                stream << (boolval ? "true" : "false");
                break;
            case TermType::CharacterLiteral:
                stream << "'" << (char)chrval << "'";
                break;
            case TermType::FloatLiteral:
                stream << floatval;
                break;
            case TermType::IntegerLiteral:
                stream << intval;
                break;
            case TermType::NullLiteral:
                stream << "null";
                break;
            case TermType::StringLiteral:
                stream << "\"" << strval << "\"";
                break;
            case TermType::Identifier:
                stream << strval;
                break;
            default:
                reportNotImplemented("TermSyntax::toString, unknown TermType");
            }
            return stream.str();
        }
    }
}
