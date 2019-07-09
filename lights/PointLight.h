#ifndef VIEWER_POINTLIGHT_H
#define VIEWER_POINTLIGHT_H

#include "BaseLight.h"

namespace lights {

using math::Point;

class PointLight: public BaseLight {
public:
    PointLight(Point &position, double intensity);

    Point getDirection(math::Point &target) override;
    double getDistance(math::Point &target) override;
    double getIntensity() const override;
private:
    Point _position;
    double _intensity;
};

} // namespace lights

#endif //VIEWER_POINTLIGHT_H
