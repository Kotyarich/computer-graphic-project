#include "intermediary.h"

namespace intermediary {

Intermediary::Intermediary():
    _renderer(new render::Renderer),
    _loader(new uploading::FileLoader) {}

void Intermediary::addModel(std::string file_name, std::string name) {    
    std::shared_ptr<Model> model = _loader.loadModel(file_name, name);
    _scene.addModel(std::shared_ptr<objects::Model>(model));
}

void Intermediary::removeModel(std::string model_name) {
    _scene.removeModel(model_name);
}

void Intermediary::transformCamera(math::Vector3d &move, math::Vector3d &rotate) {
    auto camera = _scene.getCamera();
    _transformer.moveObject(camera, move.x(), move.y(), move.z());
    _cam_manager.roll(camera, rotate.x());
    _cam_manager.pitch(camera, rotate.y());
    _cam_manager.yaw(camera, rotate.z());
}

void Intermediary::transformModel(std::string model_name, math::Vector3d &move, math::Vector3d &scale, math::Vector3d &rotate) {
    auto obj = _scene.getObject(model_name);
    _transformer.moveObject(obj, move.x(), move.y(), move.z());
    _transformer.scaleObject(obj, scale.x(), scale.y(), scale.z());
    _transformer.rotateObjectX(obj, rotate.x());
    _transformer.rotateObjectY(obj, rotate.y());
    _transformer.rotateObjectZ(obj, rotate.z());
}

void Intermediary::draw(std::shared_ptr<BaseDrawer> drawer) {
    _renderer->setDrawer(drawer);
    _renderer->render(_scene);
}

} // namespace intermediary
