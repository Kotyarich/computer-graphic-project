#ifndef VIEWER_RAYTRACER_H
#define VIEWER_RAYTRACER_H

#include "math/point.h"
#include "objects/geometry_objects/GeometryObject.h"
#include "objects/Material.h"
#include "scene/scene.h"
#include <random>

namespace raytracer {

using math::Point;

struct Intersection {
    std::shared_ptr<objects::Model> model;
    double t1;
    bool ok;
};

class Raytracer {
public:
    void setScene(scene::Scene *scene);
    Point traceRay(Point &origin, Point &direction, double min_t, double max_t, int depth);
private:
    static constexpr double eps = 1e-7;

    Point reflectRay(Point &v1, Point &v2);
    Intersection closestIntersection(Point &origin, Point &direction, double min_t, double max_t);
    double computeLighting(Point &point, Point &normal, Point &view, double specular);
    scene::Scene *_scene;
    std::default_random_engine generator;
};

} // namespace raytracer

#endif //VIEWER_RAYTRACER_H
