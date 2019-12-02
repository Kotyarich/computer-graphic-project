#include <cmath>
#include "Parallelepiped.h"

namespace objects {

Parallelepiped::Parallelepiped(Vector3d point, double width, double length, double height, double angle) {
    auto phi = M_PI / 2 - angle;
    Vector3d left_cl_bot = point;
    Vector3d right_cl_bot = {
        point.x() + length * std::cos(angle),
        point.y(),
        point.z() + std::sin(angle)
    };
    Vector3d left_far_bot = {
        point.x() - width * std::cos(phi),
        point.y(),
        point.z() + width * std::sin(phi)
    };
    Vector3d right_far_bot = {
        left_far_bot.x() + length * std::cos(angle),
        left_far_bot.y(),
        left_far_bot.z() + std::sin(angle)
    };
    Vector3d left_cl_top = {point.x(), point.y() + height, point.z()};
    Vector3d left_far_top = {left_far_bot.x(), left_far_bot.y() + height, left_far_bot.z()};
    Vector3d right_cl_top = {right_cl_bot.x(), right_cl_bot.y() + height, right_cl_bot.z()};
    Vector3d right_far_top = {right_far_bot.x(), right_far_bot.y() + height, right_far_bot.z()};

    _polygons.push_back(std::make_shared<Triangle>(left_cl_top, right_cl_bot, left_cl_bot)); // close
    _polygons.push_back(std::make_shared<Triangle>(right_cl_top, right_cl_bot, left_cl_top));
    _polygons.push_back(std::make_shared<Triangle>(left_cl_bot, left_far_bot, left_cl_top)); // left
    _polygons.push_back(std::make_shared<Triangle>(left_far_bot, left_far_top, left_cl_top));
    _polygons.push_back(std::make_shared<Triangle>(left_far_bot, right_far_bot, left_far_top)); // far
    _polygons.push_back(std::make_shared<Triangle>(right_far_top, left_far_top, right_far_bot));
    _polygons.push_back(std::make_shared<Triangle>(right_far_bot, right_far_top, right_cl_bot)); // right
    _polygons.push_back(std::make_shared<Triangle>(right_cl_bot, right_cl_top, right_far_top));
    _polygons.push_back(std::make_shared<Triangle>(left_cl_top, left_far_top, right_far_top)); // top
    _polygons.push_back(std::make_shared<Triangle>(left_cl_top, right_far_top, right_cl_top));
    _polygons.push_back(std::make_shared<Triangle>(left_cl_bot, left_far_bot, right_cl_bot)); // bottom
    _polygons.push_back(std::make_shared<Triangle>(right_cl_bot, right_far_bot, left_far_bot));
}

// TODO use more optimal algorithm
void Parallelepiped::intersectRay(objects::Ray &ray, double &int1, double &int2, bool &isInt) {
    auto t_int1 = 0., t_int2 = 0.;
    auto is_intersected = false;

    for (const auto &polygon: _polygons) {
        polygon->intersectRay(ray, t_int1, t_int2, isInt);
        if (isInt) {
            is_intersected = true;
            if (t_int1 < int1) {
                int1 = t_int1;
                _last_intersected = polygon.get();
            }
            if (t_int2 > int1 && t_int2 < int2) {
                int2 = t_int2;
            }
        }
    }

    isInt = is_intersected;
}

void Parallelepiped::transform(std::shared_ptr<math::Matrix> matrix) {
    for (auto &polygon: _polygons) {
        polygon->transform(matrix);
    }
}

Vector3d Parallelepiped::getNormal(Vector3d &point, const Vector3d &direction) const {
    return _last_intersected->getNormal(point, direction);
}
const std::vector<std::shared_ptr<Triangle>> &Parallelepiped::get_polygons() const {
    return _polygons;
}

} // namespace objects