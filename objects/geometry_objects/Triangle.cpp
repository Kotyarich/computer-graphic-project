#include "Triangle.h"

namespace objects {

Triangle::Triangle(Vector3d &v0, Vector3d &v1, Vector3d &v2):
    _points{v0, v1, v2} {
    _side1 = v1.subtract(v0);
    _side2 = v2.subtract(v0);
    _normal = computeNormal();
}

void Triangle::intersectRay(Ray &ray, double &int1, double &int2, bool &isInt) {
    auto pvec = ray.direction().cross(_side2);
    auto det = _side1.product(pvec);

    auto eps = 1e-6;
    if (det < eps && det > -eps) {
        isInt = false;
        return;
    }

    double inv_det = 1. / det;
    Vector3d tvec = ray.origin().subtract(_points[0]);
    auto u = tvec.product(pvec) * inv_det;
    if (u < 0 || u > 1) {
        isInt = false;
        return;
    }

    Vector3d qvec = tvec.cross(_side1);
    auto v = ray.direction().product(qvec) * inv_det;
    if (v < 0 || u + v > 1) {
        isInt = false;
        return;
    }

    isInt = true;
    int1 = _side2.product(qvec) * inv_det;
    int2 = int1;
}

Vector3d Triangle::computeNormal() {
    auto n = _side1.cross(_side2);
    return n.multScalar(1. / n.length());
}

Vector3d Triangle::getNormal(Vector3d &, const Vector3d &direction) const {
    if (direction.product(_normal) >= 1e-7) {
        return _normal.multScalar(-1);
    } else {
        return _normal;
    }
}

} // namespace objects
