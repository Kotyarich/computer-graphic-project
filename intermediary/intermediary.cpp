#include "intermediary.h"

namespace intermediary {

Intermediary::Intermediary():
    _renderer(new render::Renderer) {}

void Intermediary::addModel(const std::string &model_name, std::shared_ptr<objects::GeometryObject> &obj, const Material &mat) {
    auto model = std::make_shared<Model>(model_name);
    model->set_object(obj);
    model->set_material(mat);
    _scene.addModel(std::shared_ptr<objects::Model>(model));
}

void Intermediary::removeModel(const std::string &model_name) {
    _scene.removeModel(model_name);
}

void Intermediary::changeLight(math::Vector3d &pos, double intensity) {
    _scene.changeLight(pos, intensity);
}

void Intermediary::changeMirror(double rough) {
    _scene.changeMirror(rough);
}

void Intermediary::transformCamera(math::Vector3d &move, math::Vector3d &rotate) {
    auto camera = _scene.getCamera();
    _cam_manager.move(camera, move);
    _cam_manager.roll(camera, rotate.x());
    _cam_manager.pitch(camera, rotate.y());
    _cam_manager.yaw(camera, rotate.z());
}

void Intermediary::draw(std::shared_ptr<BaseDrawer> drawer, int sample_n) {
    _renderer->setDrawer(drawer);
    _renderer->render(_scene, sample_n);
}

} // namespace intermediary
