#include "Ray.h"

namespace objects {

Ray::Ray(Vector3d &origin, Vector3d &direction)
    : _origin(origin), _direction(direction) {}

Ray Ray::reflect(Vector3d &normal) {
    auto new_direction = normal.multScalar(2 * _direction.product(normal)).subtract(_direction);
    return {_origin, new_direction};
}

} // namespace objects