#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"
#include "math/vector3d.h"

namespace objects {

class Camera: public Object {
public:
    Camera();
    Camera(std::string name);

    const math::Vector3d &getPosition() const;
    void setPosition(const math::Vector3d &_position);
    double getXAngle() const;
    void setXAngle(double _x_angle);
    double getYAngle() const;
    void setYAngle(double _y_angle);
    double getZAngle() const;
    void setZAngle(double _z_angle);

    void transform(const std::shared_ptr<Matrix> matrix) override;
private:
    math::Vector3d _position;
    double _x_angle;
    double _y_angle;
    double _z_angle;
};

} // namespace objects

#endif // CAMERA_H
