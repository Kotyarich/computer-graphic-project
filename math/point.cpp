#include <cmath>
#include "point.h"
#include "matrix.h"


namespace math {

Point::Point(): _x(0), _y(0), _z(0) {}

Point::Point(double x, double y, double z): _x(x), _y(y), _z(z) {}

double Point::x() const {
    return _x;
}

double Point::y() const {
    return _y;
}

double Point::z() const {
    return _z;
}

void Point::setX(double x) {
    _x = x;
}

void Point::setY(double y) {
    _y = y;
}

void Point::setZ(double z) {
    _z = z;
}

void Point::transform(const std::shared_ptr<Matrix> matrix) {
    std::vector<double> result(4);
    std::vector<double> data = {_x, _y, _z, 1.};
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            result[i] += data[j] * matrix->get(i, j);
        }
    }

    *this = {result[0], result[1], result[2]};
}

double Point::product(Point &point) {
    return _x * point.x() + _y * point.y() + _z * point.z();
}

double Point::length() {
    return std::sqrt(product(*this));
}

Point Point::multScalar(double k) {
    return {_x * k, _y * k, _z * k};
}

Point Point::add(Point &point) {
    return {_x + point.x(), _y + point.y(), _z + point.z()};
}

Point Point::subtract(const Point &point) {
    return {_x - point.x(), _y - point.y(), _z - point.z()};
}
Point Point::clamp() {
    return Point(std::min(255, std::max(0, int(_x))),
            std::min(255, std::max(0, int(_y))),
            std::min(255, std::max(0, int(_z))));
}

Point Point::cross(Point &point) {
    return {_y * point.z() - _z * point.y(), _z * point.x() - _x *point.z(), _x * point.y() - _y * point.x()};
}

} // namespace math
