#include "PointLight.h"

namespace lights {

PointLight::PointLight(Point &position, double intensity): _position(position), _intensity(intensity) {}

Point PointLight::getDirection(math::Point &target) {
    return _position.subtract(target);
}

double PointLight::getDistance(math::Point &target) {
    return 1.;
}
double PointLight::getIntensity() const {
    return _intensity;
}

} // namespace lights