#include "drawlabel.h"


DrawLabel::DrawLabel(QImage &pixmap)
    : _pixmap(&pixmap) {}

void DrawLabel::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawImage(QPoint(0, 0), _pixmap->scaled(width(), height()));
    painter.end();
}
