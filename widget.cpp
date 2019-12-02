#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget),
    _facade(new ViewerFacade),
    _elements_num(0) {
    ui->setupUi(this);
    _draw_label = new DrawLabel(_pixmap);
    _draw_label->resize(width() - ui->frame->width(), height());
    layout()->addWidget(_draw_label);
    _pixmap = QImage(_draw_label->width(), _draw_label->height(), QImage::Format_RGB32);
    _pixmap.fill(Qt::white);
}

Widget::~Widget() {
    delete _draw_label;
    delete ui;
}

void Widget::render() {
    QPainter painter(&_pixmap);
    _pixmap.fill(Qt::black);
    auto drawer = new render::QtDrawer(&painter);
    auto command = new commands::RenderCommand(std::shared_ptr<render::BaseDrawer>(drawer));
    try {
        auto begin = std::chrono::steady_clock::now();
        _facade->execCommand(command);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << elapsed_ms.count() << std::endl;
        _draw_label->update();
    } catch(exceptions::CameraLackException &e) {
        QMessageBox::critical(nullptr, "Error", "Choose camera to render smth");
    }
    delete command;
}
