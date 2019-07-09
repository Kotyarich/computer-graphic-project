#include <lights/PointLight.h>
#include "scene.h"

namespace scene {

Scene::Scene(): _camera(new Camera) {
    Point pos = {0, -1, 3};
    std::shared_ptr<GeometryObject> obj(new Sphere(pos, 1));
    Material m = {{255, 0, 0}, 1000, 0.3};
    std::shared_ptr<Model> mod(new Model("a"));
    mod->set_material(m);
    mod->set_object(obj);
    addModel(mod);

    pos = {-2, 0, 4};
    obj.reset(new Sphere(pos, 1));
    m = {{0, 255, 0}, 500, 0.5};
    mod.reset(new Model("c"));
    mod->set_material(m);
    mod->set_object(obj);
    addModel(mod);

    pos = {2, 0, 4};
    obj.reset(new Sphere(pos, 1));
    m = {{0, 0, 255}, 10, 0.5};
    mod.reset(new Model("b"));
    mod->set_material(m);
    mod->set_object(obj);
    addModel(mod);

    double r = 5000;
    pos = {0, -r - 1, 0};
    obj.reset(new Sphere(pos, r));
    m = {{255, 255, 0}, 500, 0.35};
    mod.reset(new Model("b"));
    mod->set_material(m);
    mod->set_object(obj);
    addModel(mod);

    r = 5000;
    pos = {0, 0, 5010};
    obj.reset(new Sphere(pos, r));
    m = {{255, 255, 255}, 10, 0.94};
    mod.reset(new Model("b"));
    mod->set_material(m);
    mod->set_object(obj);
    addModel(mod);

    Point posl = {2, 1 ,0};
    std::shared_ptr<lights::BaseLight> l(new lights::PointLight(posl, 0.6));
    addLight(l);

//    posl = {1, 4 ,4};
//    l.reset(new lights::PointLight(posl, 0.2));
//    addLight(l);

    Point posc = {0, 0, -3};
    _camera->setPosition(posc);
}

void Scene::removeModel(std::string name) {
    for (int i = 0; i < _objects.size(); i++) {
        if (_objects[i]->getName() == name) {
            _objects.erase(_objects.begin() + i);
        }
    }
}

std::shared_ptr<Camera> Scene::getCamera() {
    return _camera;
}

std::shared_ptr<Object> Scene::getObject(std::string model_name) {
    for (auto &obj: _objects) {
        if (obj->getName() == model_name) {
            return obj;
        }
    }

    throw exceptions::ObjectSearchException();
}

void Scene::addModel(std::shared_ptr<Model> obj) {
    _objects.push_back(obj);
}

std::vector<std::shared_ptr<Model>> & Scene::getObjects() {
    return _objects;
}

std::vector<std::shared_ptr<lights::BaseLight>> &Scene::getLights() {
    return _lights;
}

void Scene::addLight(std::shared_ptr<lights::BaseLight> light) {
    _lights.push_back(light);
}

} // namespace scene
