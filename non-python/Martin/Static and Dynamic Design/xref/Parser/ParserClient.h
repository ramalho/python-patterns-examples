#ifndef PARSER_PARSER_CLIENT_H
#define PARSER_PARSER_CLIENT_H

//-----------------------------------------------
// Name
//  ParserClient
//
// Description
//  This class provides an interface for the clients of
//  the Parser. Whenever the Parser encounters an identifier,
//  it calls one of the two virtual functions.  It calls 
//  AddDefinition if the identifier is being defined.  It calls 
//  AddReference if the identifier is simply being used.
//
namespace Parser
{
	class ParserClient;
	class Identifier;
};


#include <string>
using namespace std;

class Parser::ParserClient
{
  public:
    virtual void 
    AddReference(Identifier* theIdentifier, 
                 string      theFileName, 
                 int         theLineNumber
                ) = 0;

    virtual void 
    AddDefinition(Identifier* theIdentifier, 
                  string      theFileName, 
                  int         theLineNumber
                 ) = 0;
};
#endif