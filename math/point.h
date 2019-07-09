#ifndef POINT_H
#define POINT_H

#include <memory>
#include "matrix.h"

namespace math {

class Point {
public:
    Point();
    Point(double x, double y, double z);

    double x() const;
    double y() const;
    double z() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    double product(Point &point);
    double length();
    Point multScalar(double k);
    // Point multMatrix()
    Point add(Point &point);
    Point subtract(const Point &point);
    Point clamp();
    Point cross(Point &point);

    void transform(const std::shared_ptr<math::Matrix> matrix);
private:
    double _x;
    double _y;
    double _z;
};

} // namespace math

#endif // POINT_H
