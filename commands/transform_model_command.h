#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H

#include "basecommand.h"
#include "math/vector3d.h"
#include "../intermediary/intermediary.h"

namespace commands {

using intermediary::Intermediary;
using math::Vector3d;

class TransformModelCommand: public BaseCommand {
public:
    TransformModelCommand(std::string object_name, Vector3d move, Vector3d scale, Vector3d rotate);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    std::string _object_name;
    Vector3d _move;
    Vector3d _scale;
    Vector3d _rotate;
};

} // namespace commands

#endif // MOVE_COMMAND_H
