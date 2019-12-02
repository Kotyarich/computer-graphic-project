#include "drawlabel.h"


DrawLabel::DrawLabel(QImage &pixmap)
    : _pixmap(&pixmap) {}

void DrawLabel::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.drawImage(QPoint(0, 0), *_pixmap);
    painter.end();
}
