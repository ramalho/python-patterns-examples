#ifndef QUERY_H
#define QUERY_H

template <typename T>
class Query
{
 public:
  virtual bool match(const T&) const = 0;
};
#endif
