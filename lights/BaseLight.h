#ifndef VIEWER_BASELIGHT_H
#define VIEWER_BASELIGHT_H

#include "math/point.h"

namespace lights {

class BaseLight {
public:
    virtual math::Point getDirection(math::Point &target) = 0;
    virtual double getDistance(math::Point &target) = 0;
    virtual double getIntensity() const = 0;
};

} // namespace lights

#endif //VIEWER_BASELIGHT_H

