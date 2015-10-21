#include "stdafx.h"
#include "Tokenizer.h"
#include "CharacterLiteralToken.h"
#include "ErrorToken.h"

namespace flc
{
    namespace tokens
    {
        Tokenizer::Tokenizer()
        {
            
        }
		Tokenizer::~Tokenizer()
		{

		}

        vector<Token> Tokenizer::tokenize(istream *sourceFile, string path)
        {
			int pos = 0;
			char strBuffer[256];
			bool reading = true;
			while (reading) {
				(*sourceFile).get(strBuffer,256);
				Token next = parseNextToken(strBuffer, pos, path);
			}
        }
		
		bool Tokenizer::isWhiteSpace(char c) {
			return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
		}
		char escapeSequenceToChar(char* sequence) {
			// Not implemented
			return sequence[0];
		}

		Token Tokenizer::parseNextToken(char *buffer, int startPos, string path) {
			int index = 0;
			for (; index < 256; index++) {
				if (!isWhiteSpace(buffer[index])) {
					break;
				}
			}
			int length;
			if (buffer[index] == '\'') {
				char c;
				if (parseCharacterToken(buffer, &length, &c)) {
					return CharacterLiteralToken(path, startPos, length, c);
				}
			}


			
			return ErrorToken(path, startPos, length, "Invalid character literal");
		}
		bool Tokenizer::parseCharacterToken(char *buffer, int *length, char *c) {
			if (buffer[1] == '\\') {
				int index = 1;
				char escapeSequence[256]; escapeSequence[0] = buffer[1];	// get at least one character
				while (buffer[index] != '\'') {
					escapeSequence[index] = buffer[index + 2];
					index++;
				}
				char c = escapeSequenceToChar(escapeSequence);
				*length = index + 3;
				return true;
			}
			else {
				if (buffer[2] != '\'') {
					flc::reportError("Invalid char literal");
					*length = 2;
					return false;
				}
				else {
					*length = 3;
					*c = buffer[1];
					return true;
				}
			}
		}
		bool Tokenizer::parseFloatLiteralToken(char *buffer, int* length) {}

		bool Tokenizer::parseIntegerLiteralToken(char *buffer, int* length) {}

		bool Tokenizer::parseStringLiteralToken(char *buffer, int* length) {}

		bool Tokenizer::parseSymbolLiteralToken(char *buffer, int* length) {}

		bool Tokenizer::parseIdentifierToken(char *buffer, int* length) {}

    }
}
