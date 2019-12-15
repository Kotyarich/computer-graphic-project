#ifndef VIEWER_GEOMETRYOBJECT_H
#define VIEWER_GEOMETRYOBJECT_H

#include "math/vector3d.h"
#include "Ray.h"

namespace objects {

using math::Vector3d;

class GeometryObject {
public:
    virtual void intersectRay(Ray &ray, double &int1, double &int2, bool &isInt) = 0;
    virtual Vector3d getNormal(Vector3d &point, const Vector3d &direction) const = 0;
};

} // namespace objects

#endif //VIEWER_GEOMETRYOBJECT_H
