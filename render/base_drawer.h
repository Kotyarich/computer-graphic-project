#ifndef LAB4_BASEDRAWER_H
#define LAB4_BASEDRAWER_H

#include <QtGui/QColor>
#include "../math/point.h"

namespace render {

using math::Point;

class BaseDrawer {
public:
    virtual ~BaseDrawer() = default;
    virtual void drawLine(const Point &p1, const Point &p2) = 0;
    virtual void drawPoint(const QColor &color, int x, int y) = 0;
    virtual std::pair<int, int> getSize() = 0;
};

} // namespace render

#endif //LAB4_BASEDRAWER_H
