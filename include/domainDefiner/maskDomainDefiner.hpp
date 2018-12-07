#ifndef MASKDOMAINDEFINER_H
#define MASKDOMAINDEFINER_H

#include "domainDefiner.hpp"

namespace domain
{
  class MaskDomainDefiner: public DomainDefiner
  {
  private:
    const uint8_t maskRadius;
    
  public:
    MaskDomainDefiner(uint8_t maskRadius):
      maskRadius(maskRadius)
    { }
    commons::coords_t getUpperLeftCorner(const commons::coords_t& point) const override
    {
      return {point.first-(int)maskRadius, point.second-(int)maskRadius};
    }
    commons::coords_t getBottomRightCorner(const commons::coords_t& point) const override
    {
      return {point.first+maskRadius, point.second+maskRadius};
    }
  };
};

#endif /* MASKDOMAINDEFINER_H */
