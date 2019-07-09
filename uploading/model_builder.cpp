#include "model_builder.h"

namespace uploading {

void ModelBuilder::reset(std::string name) {
    _model.reset();
    _model = std::shared_ptr<Model>(new Model(name));
}

void ModelBuilder::addPoint(math::Point &point) {
}

void ModelBuilder::addEdge(size_t first, size_t second) {
}

std::shared_ptr<objects::Model> ModelBuilder::getResult() {
    return _model;
}

} // namespace uploading
