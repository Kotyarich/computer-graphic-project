#ifndef VIEWER_PARALLELEPIPED_H
#define VIEWER_PARALLELEPIPED_H

#include "Triangle.h"

namespace objects {

class Parallelepiped: public GeometryObject {
public:
    Parallelepiped(Vector3d point, double width, double length, double height, double angle);

    void intersectRay(Ray &ray, double &int1, double &int2, bool &isInt) override;
    void transform(std::shared_ptr<math::Matrix> matrix) override;
    Vector3d getNormal(Vector3d &point, const Vector3d &direction) const override;
private:
    std::vector<std::shared_ptr<Triangle>> _polygons;
public:
    const std::vector<std::shared_ptr<Triangle>> &get_polygons() const;
private:
    Triangle *_last_intersected;
};

} // namespace objects

#endif //VIEWER_PARALLELEPIPED_H
