#include "pitch_camera_command.h"

namespace commands {

PitchCameraCommand::PitchCameraCommand(std::string object_name, double angle):
    _object_name(object_name), _rotation(0, angle, 0) {}

void PitchCameraCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    math::Vector3d moving(0, 0, 0);
    intermediary->transformCamera(moving, _rotation);
}

} // namespace commands
