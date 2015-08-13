#ifndef XREF_XREF_H
#define XREF_XREF_H

#include <set>
#include "XRef/identifierReferenceList.h"
#include "Parser/parserClient.h"

//----------------------------------------------
// Name
//  XRef
// 
// Description
//  This class implements the ParserClient interface by
//  accumulating the references and definitions into a list of
//  references to identifiers.  This is used to print cross-
//  reference reports.

namespace XRef
{
	class XRef;
};

class XRef::XRef : public Parser::ParserClient
{
  public:
    virtual void 
		AddReference(Parser::Identifier* theIdentifier, 
                     string theFileName, 
                     int theLineNumber);

    virtual void 
		AddDefinition(Parser::Identifier* theIdentifier, 
                      string theFileName, 
                      int theLineNumber);
    
    void PrintReport(std::ostream&);

  private:
    set<IdentifierReferenceList> itsIdentifierSet;
};
#endif
