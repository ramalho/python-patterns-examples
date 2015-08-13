#ifndef PARSER_IDENTIFIER_H
#define PARSER_IDENTIFIER_H

#include "Parser/scope.h"

//-------------------------------------------------------------
// Name
//  Identifier
//
// Description
//  This class represents an identifier in a C++ program.  It
//  contains its name and the scope that it belongs to.
//

namespace Parser
{
    class Identifier
    {
      public:
        Identifier(Scope& theScope, const string& theName);

      private:
        Scope& itsScope;
        string itsName;
    };
}; // namespace Parser
#endif 