#include "light_edit_command.h"

commands::LightEditCommand::LightEditCommand(math::Vector3d &pos, double intensity):
    _position(pos), _intensity(intensity) {}

void commands::LightEditCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    intermediary->changeLight(_position, _intensity);
}
