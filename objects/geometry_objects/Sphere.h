#ifndef VIEWER_SPHERE_H
#define VIEWER_SPHERE_H

#include <math/matrix.h>
#include "GeometryObject.h"

namespace objects {

class Sphere: public GeometryObject {
public:
    Sphere(Vector3d position, double radius);

    void intersectRay(Ray &ray, double &int1, double &int2, bool &isInt) override;
    void transform(std::shared_ptr<math::Matrix> matrix) override;
    Vector3d getNormal(Vector3d &point, const Vector3d &direction) const override;
private:
    Vector3d _position;
    double _radius;
};

} // namespace objects

#endif //VIEWER_SPHERE_H
