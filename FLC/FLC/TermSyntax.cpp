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
        TermSyntax::TermSyntax(string str)
        {
            strval = str;
            _type = TermType::StringLiteral;
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
                return boolval ? "true" : "false";
            case TermType::CharacterLiteral:
                stream << "'" << (char)chrval << "'";
                return stream.str();
            case TermType::FloatLiteral:
                stream << floatval;
                return stream.str();
            case TermType::IntegerLiteral:
                stream << intval;
                return stream.str();
            case TermType::NullLiteral:
                return "null";
            case TermType::StringLiteral:
                return "\"" + strval + "\"";
            default:
                reportNotImplemented("TermSyntax::toString, unknown TermType");
                return false;
            }
        }
    }
}
