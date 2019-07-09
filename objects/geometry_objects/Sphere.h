#ifndef VIEWER_SPHERE_H
#define VIEWER_SPHERE_H

#include <math/matrix.h>
#include "GeometryObject.h"

namespace objects {

class Sphere: public GeometryObject {
public:
    Sphere(Point position, int radius);

    void intersectRay(Point &origin, Point &direction, double &int1, double &int2, bool &isInt) override;
    void transform(std::shared_ptr<math::Matrix> matrix) override;
    Point getNormal(Point &point) const override;
private:
    Point _position;
    int _radius;
};

} // namespace objects

#endif //VIEWER_SPHERE_H
