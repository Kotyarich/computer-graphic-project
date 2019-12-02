#include "move_camera_command.h"

namespace commands {

MoveCameraCommand::MoveCameraCommand(std::string object_name, math::Vector3d move):
    _object_name(object_name), _move(move) {}

void MoveCameraCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    math::Vector3d rotation(0, 0, 0);
    intermediary->transformCamera(_move, rotation);
}

} // namespace commands
