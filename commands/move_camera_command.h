#ifndef MOVE_CAMERA_COMMAND_H
#define MOVE_CAMERA_COMMAND_H

#include "basecommand.h"
#include "math/vector3d.h"
#include "../intermediary/intermediary.h"

namespace commands {

using intermediary::Intermediary;
using math::Vector3d;

class MoveCameraCommand: public BaseCommand {
public:
    MoveCameraCommand(std::string object_name, Vector3d move);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string _object_name;
    Vector3d _move;
};

} // namespace commands

#endif // MOVE_CAMERA_COMMAND_H
