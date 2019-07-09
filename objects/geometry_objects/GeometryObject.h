#ifndef VIEWER_GEOMETRYOBJECT_H
#define VIEWER_GEOMETRYOBJECT_H

#include "math/point.h"

namespace objects {

using math::Point;

class GeometryObject {
public:
    virtual void intersectRay(Point &origin, Point &direction, double &int1, double &int2, bool &isInt) = 0;
    virtual void transform(std::shared_ptr<math::Matrix> matrix) = 0;
    virtual Point getNormal(Point &point) const = 0;
};

} // namespace objects

#endif //VIEWER_GEOMETRYOBJECT_H
