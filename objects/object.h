#ifndef OBJECT_H
#define OBJECT_H

#include <memory>
#include <string>
#include "math/vector3d.h"
#include "../math/matrix.h"

namespace objects {

using math::Matrix;

class Object {
public:
    Object() = default;
    Object(std::string name): _name(name) {}
    virtual ~Object() = default;
    virtual void transform(const std::shared_ptr<Matrix>) = 0;
    std::string getName() { return _name; }
private:
    std::string _name;
};

} // namespace objects

#endif // OBJECT_H
