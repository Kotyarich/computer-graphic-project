#ifndef VIEWER_RAYTRACER_H
#define VIEWER_RAYTRACER_H

#include "math/vector3d.h"
#include "objects/geometry_objects/Ray.h"
#include "objects/geometry_objects/GeometryObject.h"
#include "objects/Material.h"
#include "scene/scene.h"
#include <random>

namespace raytracer {

using math::Vector3d;
using objects::Ray;

struct Intersection {
    std::shared_ptr<objects::Model> model;
    double t1;
    bool ok;
};

class Raytracer {
public:
    void setScene(scene::Scene *scene);
    Vector3d traceRay(Ray ray, double min_t, double max_t, int depth);
private:
    static constexpr double eps = 1e-7;

    Vector3d reflectRay(Vector3d &v1, Vector3d &v2);
    Intersection closestIntersection(Ray &ray, double min_t, double max_t);
    double computeLighting(Vector3d &point, Vector3d &normal, Vector3d &view, double specular);

    scene::Scene *_scene;
    std::default_random_engine generator;
};

} // namespace raytracer

#endif //VIEWER_RAYTRACER_H
