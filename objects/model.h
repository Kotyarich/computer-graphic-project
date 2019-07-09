#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "object.h"
#include "Material.h"
#include "geometry_objects/GeometryObject.h"
#include "geometry_objects/Sphere.h"
#include "../math/point.h"

namespace objects {

using math::Point;

class Model: public Object {
public:
    explicit Model(std::string);

    std::shared_ptr<GeometryObject> get_object() const;
    const Material &get_material() const;
    void set_object(std::shared_ptr<GeometryObject> _object);
    void set_material(const Material &_material);

    void transform(std::shared_ptr<Matrix> matrix) override;

private:
    std::shared_ptr<GeometryObject> _object;
    Material _material;
};

} // namespace objects

#endif // MODEL_H
