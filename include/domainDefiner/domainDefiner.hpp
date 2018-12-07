#ifndef DOMAINDEFINER_H
#define DOMAINDEFINER_H

#include "commons.hpp"

namespace domain
{
  class DomainDefiner
  {
  public:
    virtual commons::coords_t getUpperLeftCorner(const commons::coords_t& point) const = 0;
    virtual commons::coords_t getBottomRightCorner(const commons::coords_t& point) const = 0;
  };
};

#endif /* DOMAINDEFINER_H */
