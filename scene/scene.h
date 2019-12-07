#ifndef LAB4_SCENE_H
#define LAB4_SCENE_H

#include <unordered_map>
#include <memory>
#include <algorithm>
#include "../exceptions/camera_lack_exception.h"
#include "../exceptions/object_search_exception.h"
#include "../objects/model.h"
#include "../objects/camera.h"
#include "lights/BaseLight.h"
#include "objects/geometry_objects/Triangle.h"
#include "objects/geometry_objects/Parallelepiped.h"
#include "objects/geometry_objects/Pyramid.h"
#include "objects/geometry_objects/Prism.h"

namespace scene {

using namespace objects;

class Scene {
public:
    Scene();

    void addModel(std::shared_ptr<Model> obj);
    void removeModel(std::string name);

    std::shared_ptr<Camera> getCamera();
    std::shared_ptr<Object> getObject(std::string model_name);
    std::vector<std::shared_ptr<Model>> & getObjects();
    std::vector<std::shared_ptr<lights::BaseLight>> & getLights();
    void addLight(std::shared_ptr<lights::BaseLight> light);
private:
    std::vector<std::shared_ptr<objects::Model>> _objects;
    std::vector<std::shared_ptr<lights::BaseLight>> _lights;
    std::shared_ptr<Camera> _camera;
};

} // namespace scene

#endif //LAB4_SCENE_H
