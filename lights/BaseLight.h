#ifndef VIEWER_BASELIGHT_H
#define VIEWER_BASELIGHT_H

#include "math/vector3d.h"

namespace lights {

class BaseLight {
public:
    virtual math::Vector3d getDirection(math::Vector3d &target) = 0;
    virtual double getDistance(math::Vector3d &target) = 0;
    virtual double getIntensity() const = 0;
};

} // namespace lights

#endif //VIEWER_BASELIGHT_H

