#ifndef INTERMEDIARY_H
#define INTERMEDIARY_H

#include <memory>
#include "../exceptions/object_type_exception.h"
#include "math/vector3d.h"
#include "../render/renderer.h"
#include "../transformations/camera_manager.h"
#include "../objects/model.h"

namespace intermediary {

using objects::Object;
using objects::Model;
using objects::Camera;
using render::BaseDrawer;
using math::Vector3d;

class Intermediary {
public:
    Intermediary();

    void addModel(const std::string &model_name, std::shared_ptr<objects::GeometryObject> &obj, const Material &mat);
    void removeModel(const std::string &model_name);

    void changeLight(Vector3d &pos, double intensity);
    void changeMirror(double rough);

    void transformCamera(math::Vector3d &move, math::Vector3d &rotate);
    void transformModel(std::string model_name, Vector3d &move, Vector3d &scale, Vector3d &rotate);

    void draw(std::shared_ptr<BaseDrawer> drawer, int sample_n);
private:
    std::shared_ptr<render::Renderer> _renderer;
    transformations::CameraManager _cam_manager;
    scene::Scene _scene;
};

}

#endif // INTERMEDIARY_H
