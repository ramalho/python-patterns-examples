#ifndef PARSER_NAMED_SCOPE
#define PARSER_NAMED_SCOPE

#include "Parser/scope.h"
class Parser::Identifier;

//----------------------------------------------------------
// Name
//  NamedScope
//
// Description
//  This class represents a named scope.  A named scope is a scope
//  which is created within a class or a function.  The scope carries
//  the name of the class or function.  Thus a named scope has an
//  identifier which specifies its name.
//
//  The parent Scope of a NamedScope is the Scope of itsName;
//

namespace Parser
{
    class NamedScope;
};

class Parser::NamedScope : public Parser::Scope
{
  public:
    NamedScope(Identifier& theName);
    virtual Scope* GetParentScope();

  private:
    Identifier& itsName;
};
#endif