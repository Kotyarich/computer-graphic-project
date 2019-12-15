#include "camera_manager.h"

namespace transformations {

void CameraManager::move(std::shared_ptr<objects::Camera> camera, math::Vector3d &move) {
    auto cam_pos = camera->getPosition();
    cam_pos = cam_pos.add(move);
    camera->setPosition(cam_pos);
}

void CameraManager::yaw(std::shared_ptr<Camera> camera, double angle) {
    double cur_angle = camera->getZAngle();
    camera->setZAngle(angle / 180. * 3.1415926535 + cur_angle);
}

void CameraManager::roll(std::shared_ptr<objects::Camera> camera, double angle) {
    double cur_angle = camera->getXAngle();
    camera->setXAngle(angle / 180. * 3.1415926535 + cur_angle);
}

void CameraManager::pitch(std::shared_ptr<objects::Camera> camera, double angle) {
    double cur_angle = camera->getYAngle();
    camera->setYAngle(angle / 180. * 3.1415926535 + cur_angle);
}

} // namespace transformations
