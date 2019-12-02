#ifndef DRAWLABEL_H
#define DRAWLABEL_H

#include <QObject>
#include <QLabel>
#include <QPainter>

class DrawLabel : public QLabel
{
    Q_OBJECT

public:
    DrawLabel(QImage & pixmap);
    void paintEvent(QPaintEvent * e);

private:
    QImage * _pixmap;
};

#endif // DRAWLABEL_H
