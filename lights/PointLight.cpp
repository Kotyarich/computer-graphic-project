#include "PointLight.h"

namespace lights {

PointLight::PointLight(Vector3d &position, double intensity): _position(position), _intensity(intensity) {}

Vector3d PointLight::getDirection(math::Vector3d &target) {
    return _position.subtract(target);
}

double PointLight::getDistance(math::Vector3d &target) {
    return _position.subtract(target).length();
}
double PointLight::getIntensity() const {
    return _intensity;
}

void PointLight::change(math::Vector3d p, double i) {
    _position = p;
    _intensity = i;
}

} // namespace lights
