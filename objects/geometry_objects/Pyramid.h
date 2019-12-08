#ifndef VIEWER_PYRAMID_H
#define VIEWER_PYRAMID_H

#include "GeometryObject.h"
#include "Triangle.h"

namespace objects {

class Pyramid: public GeometryObject {
public:
    Pyramid(Vector3d point, double base_side, double height, double angle);

    void intersectRay(Ray &ray, double &int1, double &int2, bool &isInt) override;
    void transform(std::shared_ptr<math::Matrix> matrix) override;
    Vector3d getNormal(Vector3d &point, const Vector3d &direction) const override;
    const std::vector<Triangle*> get_polygons() const;
private:
    std::vector<Triangle*> _polygons;
    Triangle *_last_intersected;
};

} // namespace objects

#endif //VIEWER_PYRAMID_H
