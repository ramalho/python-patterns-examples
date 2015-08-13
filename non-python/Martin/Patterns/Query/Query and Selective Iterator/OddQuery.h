#ifndef ODDQUERY_H
#define ODDQUERY_H
#include "Query.h"

class OddQuery : public Query<int>
{
 public:
  virtual bool match(const int& i) const
  {
    return (i&1 == 1);
  }
};
#endif
