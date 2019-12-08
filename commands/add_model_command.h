#ifndef ADD_MODEL_COMMAND_H
#define ADD_MODEL_COMMAND_H

#include <string>
#include "basecommand.h"
#include "../intermediary/intermediary.h"

namespace commands {

using intermediary::Intermediary;

class AddModelCommand: public BaseCommand {
public:
    explicit AddModelCommand(std::string model_name, std::shared_ptr<objects::GeometryObject> object, Material mat);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:    
    std::string _model_name;
    std::shared_ptr<objects::GeometryObject> _object;
    Material _material;
};

} // namespace commands

#endif // ADD_MODEL_COMMAND_H
