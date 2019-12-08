#include <lights/PointLight.h>
#include <math.h>
#include "scene.h"

namespace scene {

Scene::Scene(): _camera(new Camera) {
    Vector3d pos = {0, -1, 3};
    std::shared_ptr<GeometryObject> obj(new Sphere(pos, 1));
    Material m = {{255, 0, 0}, 300, 0.5, 0};
    std::shared_ptr<Model> mod(new Model("a"));
    mod->set_material(m);
    mod->set_object(obj);
//    addModel(mod);

    pos = {-2, 0, 4};
    obj.reset(new Sphere(pos, 1));
    m = {{0, 255, 0}, 500, 0.1, 0};
    mod.reset(new Model("c"));
    mod->set_material(m);
    mod->set_object(obj);
    addModel(mod);

    // mirror
    auto distance = 8.;
    Vector3d v0 = {-10, -10, distance};
    Vector3d v1 = {-10, 10, distance};
    Vector3d v2 = {10, 10, distance};
    obj.reset(new Triangle(v0, v1, v2));
    m = {{255, 255, 255}, 200, 0.95, 4e-3};
    mod.reset(new Model("mirror"));
    mod->set_material(m);
    mod->set_object(obj);
    addModel(mod);
    _mirrow[0] = mod;
    v0 = {10, 10, distance};
    v1 = {10, -10, distance};
    v2 = {-10, -10, distance};
    obj.reset(new Triangle(v0, v1, v2));
    mod.reset(new Model("mirror"));
    mod->set_material(m);
    mod->set_object(obj);
    addModel(mod);
    _mirrow[1] = mod;

    double r = 5000;
    pos = {0, -r - 1, 0};
    obj.reset(new Sphere(pos, r));
    m = {{255, 255, 0}, 500, 0.35, 0};
    mod.reset(new Model("b"));
    mod->set_material(m);
    mod->set_object(obj);
    addModel(mod);

    Vector3d posl = {2, 1 ,0};
    std::shared_ptr<lights::BaseLight> l(new lights::PointLight(posl, 0.6));
    addLight(l);

    Vector3d posc = {0, 0, -3};
    _camera->setPosition(posc);
}

void Scene::removeModel(std::string name) {
    for (size_t i = 0; i < _objects.size(); i++) {
        while (i < _objects.size() && _objects[i]->getName() == name) {
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

void Scene::changeLight(Vector3d &pos, double intensity) {
    _lights[0]->change(pos, intensity);
}

void Scene::changeMirror(double rough) {
    auto m = _mirrow[0]->get_material();
    m.roughness = rough;
    _mirrow[0]->set_material(m);
    _mirrow[1]->set_material(m);
}

} // namespace scene
