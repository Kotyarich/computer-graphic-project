#include <cmath>
#include "Sphere.h"

namespace objects {

Sphere::Sphere(Point position, int radius)
    : _position(position), _radius(radius) {}

void Sphere::intersectRay(Point &origin, Point &direction, double &int1, double &int2, bool &isInt) {
    auto oc = origin.subtract(_position);

    double k1 = direction.product(direction);
    double k2 = 2 * oc.product(direction);
    double k3 = oc.product(oc) - _radius * _radius;

    double discriminant = k2 * k2 - 4 * k1 * k3;
    if (discriminant < 0) {
        int1 = 0;
        int2 = 0;
        isInt = false;
    } else {
        discriminant = std::sqrt(discriminant);
        int1 = (-k2 + discriminant) / (2 * k1);
        int2 = (-k2 - discriminant) / (2 * k1);
        isInt = true;
    }
}

void Sphere::transform(std::shared_ptr<math::Matrix> matrix) {
    _position.transform(matrix);
}

Point Sphere::getNormal(Point &point) const {
    auto normal = point.subtract(_position);
    normal = normal.multScalar(1 / normal.length());
    return normal;
}

} // namespace objects