#ifndef WINDOWSUNIONDOMAINDEFINER_H
#define WINDOWSUNIONDOMAINDEFINER_H

#include "domainDefiner.hpp"

namespace domain
{
  class WindowsUnionDomainDefiner: public DomainDefiner
  {
  private:
    const size_t imageWidth, imageHeight;
    const uint gridRows, gridCols;
    const int maskRadius;
    const int windowWidth, windowHeight;

  public:
    WindowsUnionDomainDefiner(const size_t imageWidth, const size_t imageHeight,
			      const uint gridRows, const uint gridCols,
			      const int maskRadius):
      imageWidth(imageWidth), imageHeight(imageHeight), gridRows(gridRows), gridCols(gridCols),
      maskRadius(maskRadius), windowWidth(imageWidth/gridCols), windowHeight(imageHeight/gridRows)
    { }

    inline commons::coords_t getUpperLeftCorner(const commons::coords_t& point) const override
    {
      using commons::coords_t;

      const coords_t maskUpperLeftCorner(point.first - maskRadius, point.second - maskRadius);
      const auto windowUpperLeftCorner(windowIdToPixelCoords(pixelCoordToWindowId(maskUpperLeftCorner)));

      return windowUpperLeftCorner;
    }
    inline commons::coords_t getBottomRightCorner(const commons::coords_t& point) const override
    {
      using commons::coords_t;

      const coords_t maskBottomRightCorner(point.first + maskRadius, point.second + maskRadius);
      auto windowBottomRightCorner(windowIdToPixelCoords(pixelCoordToWindowId(maskBottomRightCorner)));
      windowBottomRightCorner.first += windowHeight - 1;
      windowBottomRightCorner.second += windowWidth - 1;

      return windowBottomRightCorner;
    }
  private:
    inline commons::coords_t pixelCoordToWindowId(const commons::coords_t& coords) const
    {
      return {coords.first / windowHeight, coords.second / windowWidth};
    }
    inline commons::coords_t windowIdToPixelCoords(const commons::coords_t& coords) const
    {
      return {coords.first*gridRows, coords.second*gridCols};
    }
  };
};

#endif /* WINDOWSUNIONDOMAINDEFINER_H */
