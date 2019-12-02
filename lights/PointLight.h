#ifndef VIEWER_POINTLIGHT_H
#define VIEWER_POINTLIGHT_H

#include "BaseLight.h"

namespace lights {

using math::Vector3d;

class PointLight: public BaseLight {
public:
    PointLight(Vector3d &position, double intensity);

    Vector3d getDirection(math::Vector3d &target) override;
    double getDistance(math::Vector3d &target) override;
    double getIntensity() const override;
private:
    Vector3d _position;
    double _intensity;
};

} // namespace lights

#endif //VIEWER_POINTLIGHT_H
