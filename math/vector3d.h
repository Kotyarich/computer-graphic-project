#ifndef POINT_H
#define POINT_H

#include <memory>
#include "matrix.h"

namespace math {

class Vector3d {
public:
    Vector3d();
    Vector3d(double x, double y, double z);

    double x() const;
    double y() const;
    double z() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    double product(Vector3d point) const;
    double length();
    Vector3d multScalar(double k) const ;   
    Vector3d add(Vector3d &point);
    Vector3d subtract(const Vector3d &point);
    Vector3d clamp();
    Vector3d cross(const Vector3d &point);

    void transform(const math::Matrix *matrix);
private:
    double _x;
    double _y;
    double _z;
};

} // namespace math

#endif // POINT_H
