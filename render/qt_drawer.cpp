#include "qt_drawer.h"

namespace render {

QtDrawer::QtDrawer(QPainter *painter): _painter(painter) {}

void QtDrawer::drawLine(const math::Vector3d &p1, const math::Vector3d &p2) {
    auto w = _painter->window().width() / 2;
    auto h = _painter->window().height() / 2;
    _painter->drawLine(w + std::round(p1.x()), h - std::round(p1.y()),
                       w + std::round(p2.x()), h - std::round(p2.y()));
}

void QtDrawer::drawPoint(const QColor &color, int x, int y) {
    auto w = _painter->window().width() / 2;
    auto h = _painter->window().height() / 2;
    _painter->setPen(color);
    _painter->drawPoint(w + x , h - y);
}

std::pair<int, int> QtDrawer::getSize() {
    return {_painter->window().width(), _painter->window().height()};
}

} // namespace render
