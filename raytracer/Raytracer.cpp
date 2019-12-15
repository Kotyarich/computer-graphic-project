#include <cmath>
#include <iostream>
#include "Raytracer.h"

namespace raytracer {

Vector3d Raytracer::reflectRay(math::Vector3d &v1, math::Vector3d &v2) {
    return v2.multScalar(2 * v1.product(v2)).subtract(v1);
}

void Raytracer::setScene(scene::Scene *scene) {
    _scene = scene;
}

Intersection Raytracer::closestIntersection(Ray &ray, double min_t, double max_t) {
    double closest_t = 1.7e+308;
    std::shared_ptr<objects::Model> closest_model;
    auto models = _scene->getObjects();

    for (auto &obj: models) {
        double t1, t2;
        bool isIntersect = false;
        obj->get_object()->intersectRay(ray, t1, t2, isIntersect);
        if (not isIntersect) {
            continue;
        }

        if (t1 < closest_t and min_t < t1 and t1 < max_t) {
            closest_t = t1;
            closest_model = obj;
        }
        if (t2 < closest_t and min_t < t2 and t2 < max_t) {
            closest_t = t2;
            closest_model = obj;
        }
    }

    bool ok = false;
    if (closest_model) {
        ok = true;
    }

    return {closest_model, closest_t, ok};
}

double Raytracer::computeLighting(Vector3d &point, Vector3d &normal, Vector3d &view, double specular) {
    double intensity = 0.2;
    double length_n = normal.length();
    double length_v = view.length();

    auto lights = _scene->getLights();
    for (auto &light: lights) {
        Vector3d vec_l = light->getDirection(point);
        double t_max = vec_l.length();
        vec_l = vec_l.multScalar(1./vec_l.length());

        Ray ray{point, vec_l};
        auto blocker = closestIntersection(ray, eps, t_max);
        if (blocker.ok) {
            continue;
        }

        double n_dot_l = normal.product(vec_l);
        if (n_dot_l > 0) {
            intensity += light->getIntensity() * n_dot_l / (length_n * vec_l.length());
        }

        if (specular >= 0) {
            Ray reflected_ray = ray.reflect(normal);

            double r_dot_v = reflected_ray.direction().product(view);
            if (r_dot_v > 0) {
                intensity += light->getIntensity()
                    * std::pow(r_dot_v / (reflected_ray.direction().length() * length_v), specular);
            }
        }
    }

    return intensity;
}

Vector3d Raytracer::traceRay(Ray ray, double min_t, double max_t, int depth) {
    auto intersection = closestIntersection(ray, min_t, max_t);
    if (not intersection.ok) {
        return {0, 0, 0}; // TODO add background-color to somewhere
    }

    auto object = intersection.model->get_object();
    auto material = intersection.model->get_material();

    auto intersection_point = ray.direction().multScalar(intersection.t1);
    intersection_point = ray.origin().add(intersection_point);
    auto normal = object->getNormal(intersection_point, ray.direction());

    auto view = ray.direction().multScalar(-1);
    auto lighting = computeLighting(intersection_point, normal, view, material.specular);
    auto local_color = material.color.multScalar(lighting);

    if (material.reflective <= 0 or depth <= 0) {
        return local_color;
    }

    auto reflected_dir = reflectRay(view, normal);

    std::uniform_real_distribution<double> distribution(0., 1.);
    Vector3d reflected_color = {0, 0, 0};
    int n = material.roughness < 1e-10? 1: _samples_num;
    for (int i = 0; i < n; i++) {
        double e1 = distribution(generator);
        double e2 = distribution(generator);

        double a = -20. * material.roughness;
        double x = - a / 2 + e1 * a;
        double y = - a / 2 + e2 * a;

        Vector3d u = reflected_dir.cross(normal);
        Vector3d v = reflected_dir.cross(u).multScalar(y);
        u = u.multScalar(x);
        Vector3d test_ray = reflected_dir;
        test_ray = u.add(v).add(test_ray);

        auto color = traceRay(Ray(intersection_point, test_ray), eps, 20000000, depth - 1);
        reflected_color = reflected_color.add(color);
    }
    reflected_color = reflected_color.multScalar(1. / n);

    auto color = local_color.multScalar(1 - material.reflective);
    reflected_color = reflected_color.multScalar(material.reflective);
    return color.add(reflected_color);
}

} // namespace raytracer
