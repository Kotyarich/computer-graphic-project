#ifndef LAB4_BASEDRAWER_H
#define LAB4_BASEDRAWER_H

#include <QtGui/QColor>
#include "math/vector3d.h"

namespace render {

using math::Vector3d;

class BaseDrawer {
public:
    virtual ~BaseDrawer() = default;
    virtual void drawLine(const Vector3d &p1, const Vector3d &p2) = 0;
    virtual void drawPoint(const QColor &color, int x, int y) = 0;
    virtual std::pair<int, int> getSize() = 0;
};

} // namespace render

#endif //LAB4_BASEDRAWER_H
