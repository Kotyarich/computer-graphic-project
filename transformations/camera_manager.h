#ifndef CAMERAROTATOR_H
#define CAMERAROTATOR_H

#include "objects/camera.h"

namespace transformations {

using objects::Camera;

class CameraManager {
public:
    void move(std::shared_ptr<Camera> camera, math::Vector3d &move);
    void yaw(std::shared_ptr<Camera> camera, double angle);
    void roll(std::shared_ptr<Camera> camera, double angle);
    void pitch(std::shared_ptr<Camera> camera, double angle);
};

} // namespace transformations

#endif // CAMERAROTATOR_H
