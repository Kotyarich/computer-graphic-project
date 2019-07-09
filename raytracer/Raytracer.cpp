#include <cmath>
#include <iostream>
#include "Raytracer.h"

namespace raytracer {

Point Raytracer::reflectRay(math::Point &v1, math::Point &v2) {
    return v2.multScalar(2 * v1.product(v2)).subtract(v1);
}

void Raytracer::setScene(scene::Scene *scene) {
    _scene = scene;
}

Intersection Raytracer::closestIntersection(Point &origin, Point &direction, double min_t, double max_t) {
    double closest_t = 1.7e+308;
    std::shared_ptr<objects::Model> closest_model;
    auto models = _scene->getObjects();

    for (auto &obj: models) {
        double t1, t2;
        bool isIntersect = false;
        obj->get_object()->intersectRay(origin, direction, t1, t2, isIntersect);
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

double Raytracer::computeLighting(Point &point, Point &normal, Point &view, double specular) {
    double intensity = 0.2; // TODO dont hardcode ambient intensity
    double length_n = normal.length();
    double length_v = view.length();

    auto lights = _scene->getLights();
    for (auto &light: lights) {
        Point vec_l = light->getDirection(point);
        double t_max = light->getDistance(point);

        auto blocker = closestIntersection(point, vec_l, eps, t_max);
        if (blocker.ok) {
            continue;
        }

        double n_dot_l = normal.product(vec_l);
        if (n_dot_l > 0) {
            intensity += light->getIntensity() * n_dot_l / (length_n * vec_l.length());
        }

        if (specular != -1) {
            Point vec_r = reflectRay(vec_l, normal);

            double r_dot_v = vec_r.product(view);
            if (r_dot_v > 0) {
                intensity += light->getIntensity() * std::pow(r_dot_v / (vec_r.length() * length_v), specular);
            }
        }
    }

    return intensity;
}

Point Raytracer::traceRay(Point &origin, Point &direction, double min_t, double max_t, int depth) {
    auto intersection = closestIntersection(origin, direction, min_t, max_t);
    if (not intersection.ok) {
        return {0, 0, 0}; // TODO add background-color to somewhere
    }

    auto object = intersection.model->get_object();
    auto material = intersection.model->get_material();

    auto point = direction.multScalar(intersection.t1);
    point = origin.add(point);
    auto normal = object->getNormal(point);

    auto view = direction.multScalar(-1);
    auto lighting = computeLighting(point, normal, view, material.specular);
    auto local_color = material.color.multScalar(lighting);

    if (material.reflective <= 0 or depth <= 0) {
        return local_color;
    }

    auto reflected_ray = reflectRay(view, normal);

    std::uniform_real_distribution<double> distribution(0., 1.);
    Point reflected_color = {0, 0, 0};
    int n = 16;
    for (int i = 0; i < n; i++) {
        double e1 = distribution(generator);
        double e2 = distribution(generator);
//        e1 = pow(1 - e1, material.specular);
//        double theta = acos(pow(1 - e1, material.specular));
//        double phi = 2 * M_PI * e2;
        double a = -2. * 0.135;
        double x = - a / 2 + e1 * a; // - sin(phi) * cos(theta);
        double y = - a / 2 + e2 * a; // sin(phi) * sin(phi);
//        double z = cos(phi);
//        std::cout << x << " " << y << std::endl;

        Point u = reflected_ray.cross(normal);
        Point v = reflected_ray.cross(u).multScalar(y);
        u = u.multScalar(x);
        Point test_ray = reflected_ray;//.multScalar(z);
        test_ray = u.add(v).add(test_ray);

//        std::cout << test_ray.x() << "; " << test_ray.y() << "; " << test_ray.z() << "; " << std::endl;
//        std::cout << reflected_ray.x() << "; " << reflected_ray.y() << "; " << reflected_ray.z() << "; " << std::endl;

        auto color = traceRay(point, test_ray, eps, 20000000, depth - 1);
        reflected_color = reflected_color.add(color);
    }
    reflected_color = reflected_color.multScalar(1. / n);

    auto color = local_color.multScalar(1 - material.reflective);
    reflected_color = reflected_color.multScalar(material.reflective);
    return color.add(reflected_color);
}

} // namespace raytracer
