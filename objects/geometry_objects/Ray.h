#ifndef RAY_H
#define RAY_H

#include "math/vector3d.h"

namespace objects {

using math::Vector3d;

class Ray {
public:
    Ray(Vector3d &origin, Vector3d &direction);

    Vector3d origin() const { return _origin; }
    Vector3d direction() const { return _direction; }

    Ray reflect(Vector3d &normal);
private:
    Vector3d _origin;
    Vector3d _direction;
};

} // namespace objects

#endif //RAY_H
