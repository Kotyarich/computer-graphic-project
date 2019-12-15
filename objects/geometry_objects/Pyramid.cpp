#include <math.h>
#include "Pyramid.h"

namespace objects {

Pyramid::Pyramid(math::Vector3d point, double base_side, double height, double angle) {
    auto phi = M_PI / 2 - angle;
    Vector3d left_cl_bot = point;
    Vector3d right_cl_bot = {
        point.x() + base_side * std::cos(angle),
        point.y(),
        point.z() + std::sin(angle)
    };
    Vector3d left_far_bot = {
        point.x() - base_side * std::cos(phi),
        point.y(),
        point.z() + base_side * std::sin(phi)
    };
    Vector3d right_far_bot = {
        left_far_bot.x() + base_side * std::cos(angle),
        left_far_bot.y(),
        left_far_bot.z() + std::sin(angle)
    };
    Vector3d top = {
        (point.x() + right_far_bot.x()) / 2,
        point.y() + height,
        (point.z() + right_far_bot.z()) / 2,
    };

    _polygons.push_back(new Triangle(left_cl_bot, right_cl_bot, top)); // close
    _polygons.push_back(new Triangle(left_cl_bot, left_far_bot, top)); // left
    _polygons.push_back(new Triangle(left_far_bot, right_far_bot, top)); // far
    _polygons.push_back(new Triangle(right_far_bot, top, right_cl_bot)); // right
    _polygons.push_back(new Triangle(left_cl_bot, left_far_bot, right_cl_bot)); // bottom
    _polygons.push_back(new Triangle(right_cl_bot, right_far_bot, left_far_bot));
}
const std::vector<Triangle*> Pyramid::get_polygons() const {
    return _polygons;
}
void Pyramid::intersectRay(Ray &ray, double &int1, double &int2, bool &isInt) {
    auto t_int1 = 0., t_int2 = 0.;
    auto is_intersected = false;

    for (const auto &polygon: _polygons) {
        polygon->intersectRay(ray, t_int1, t_int2, isInt);
        if (isInt) {
            is_intersected = true;
            if (t_int1 < int1) {
                int1 = t_int1;
                _last_intersected = polygon;
            }
            if (t_int2 > int1 && t_int2 < int2) {
                int2 = t_int2;
            }
        }
    }

    isInt = is_intersected;
}

Vector3d Pyramid::getNormal(Vector3d &point, const Vector3d &direction) const {
    return _last_intersected->getNormal(point, direction);
}

} // namespace objects
