#ifndef VIEWER_MATERIAL_H
#define VIEWER_MATERIAL_H

struct Material {
    math::Vector3d color;
    double specular;
    double reflective;
    double roughness;
};

#endif //VIEWER_MATERIAL_H
