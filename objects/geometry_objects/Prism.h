#ifndef VIEWER_PRISM_H
#define VIEWER_PRISM_H

#include <cmath>
#include "Triangle.h"

namespace objects {

class Prism: public GeometryObject {
public:
    Prism(Vector3d point, double base_width, double height, double angle);

    void intersectRay(Ray &ray, double &int1, double &int2, bool &isInt) override;
    void transform(std::shared_ptr<math::Matrix> matrix) override;
    Vector3d getNormal(Vector3d &point, const Vector3d &direction) const override;
    const std::vector<std::shared_ptr<Triangle>> &get_polygons() const;
private:
    std::vector<std::shared_ptr<Triangle>> _polygons;
    Triangle *_last_intersected;
};

} // namespace objects


#endif //VIEWER_PRISM_H
