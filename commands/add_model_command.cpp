#include "add_model_command.h"

namespace commands {

AddModelCommand::AddModelCommand(std::string model_name, std::shared_ptr<objects::GeometryObject> object, Material mat):
    _model_name(model_name), _object(object), _material(mat) {}

void AddModelCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    intermediary->addModel(_model_name, _object, _material);
}

} // namespace commands
