#include "model.h"

namespace objects {

Model::Model(std::string name): Object(name) {}

std::shared_ptr<GeometryObject> Model::get_object() const {
    return _object;
}
const Material &Model::get_material() const {
    return _material;
}
void Model::set_object(std::shared_ptr<GeometryObject> _object) {
    Model::_object = std::move(_object);
}
void Model::set_material(const Material &_material) {
    Model::_material = _material;
}

} // namespace objects
