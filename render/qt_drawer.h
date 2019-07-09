#ifndef LAB4_QTDRAWER_H
#define LAB4_QTDRAWER_H

#include <QPainter>
#include <cmath>
#include "base_drawer.h"

namespace render {

class QtDrawer: public BaseDrawer {
public:
    explicit QtDrawer(QPainter *painter);
    void drawLine(const Point &p1, const Point &p2) override;
    std::pair<int, int> getSize() override;
    void drawPoint(const QColor &color, int x, int y) override;
private:
    QPainter *_painter;
};

} // namespace render

#endif //LAB4_QTDRAWER_H
