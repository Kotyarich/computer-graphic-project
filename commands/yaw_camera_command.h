#ifndef YAW_CAMERA_COMMAND_H
#define YAW_CAMERA_COMMAND_H

#include "basecommand.h"
#include "math/vector3d.h"
#include "intermediary/intermediary.h"

namespace commands {

class YawCameraCommand: public BaseCommand {
public:
    YawCameraCommand(std::string object_name, double angle);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string _object_name;
    math::Vector3d _rotation;
};

} // namespace commands

#endif // YAW_CAMERA_COMMAND_H
