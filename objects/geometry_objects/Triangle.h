#ifndef VIEWER_TRIANGLE_H
#define VIEWER_TRIANGLE_H

#include "math/vector3d.h"
#include "GeometryObject.h"

namespace objects {

using math::Vector3d;

class Triangle: public GeometryObject {
public:
    Triangle(Vector3d &v0, Vector3d &v1, Vector3d &v2);
    void intersectRay(Ray &ray, double &int1, double &int2, bool &isInt) override;
    void transform(std::shared_ptr<math::Matrix> matrix) override;
    Vector3d getNormal(Vector3d &point, const Vector3d &direction) const override;
private:
    Vector3d _points[3];
    Vector3d _side1;
    Vector3d _side2;
    Vector3d _normal;

    Vector3d computeNormal();
};

} // namespace objects

#endif //VIEWER_TRIANGLE_H
