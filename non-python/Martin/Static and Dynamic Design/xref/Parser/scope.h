#ifndef PARSER_SCOPE_H
#define PARSER_SCOPE_H

//-------------------------------------------------------------
// Name
//  Scope
//
// Description
//  This class is the abstract base for all the different kinds
//  of scopes.  You can query any scope for its parent scope.
//

namespace Parser
{
    class Scope;
};

class Parser::Scope
{
  public:
      virtual Parser::Scope* GetParentScope() = 0;
      // returns 0 if no parent (i.e. ‘this’ is global)
};
#endif