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
    auto sample_n = ui->samples_num->value();
    auto command = new commands::RenderCommand(std::shared_ptr<render::BaseDrawer>(drawer), sample_n);
    try {
        auto begin = std::chrono::steady_clock::now();
        _facade->execCommand(command);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << elapsed_ms.count() << std::endl;
        _draw_label->update();
    } catch(exceptions::CameraLackException) {
        QMessageBox::critical(nullptr, "Error", "Choose camera to render smth");
    }
    delete command;
}

void Widget::remove() {
    if (ui->comboBox->count() <= 0) {
        return;
    }

    std::string name = ui->comboBox->currentText().toStdString();
    commands::RemoveModelCommand command(name);
    _facade->execCommand(&command);
    ui->comboBox->removeItem(ui->comboBox->currentIndex());
}

void Widget::move() {
    auto x = static_cast<double>(ui->dx->value());
    auto y = static_cast<double>(ui->dy->value());
    auto z = static_cast<double>(ui->dz->value());
    commands::MoveCameraCommand command("camera", Vector3d{x, y, z});
    _facade->execCommand(&command);
}

void Widget::rotate() {
    auto ox = ui->ox->value();
    auto oy = ui->oy->value();
    commands::RollCameraCommand command1("camera", ox);
    _facade->execCommand(&command1);
    commands::PitchCameraCommand command2("camera", oy);
    _facade->execCommand(&command2);
}

void Widget::change_light() {
    Vector3d pos = {
        ui->x_light_input->value(),
        ui->y_light_input->value(),
        ui->z_light_input->value()
    };
    auto intensity = ui->int_light_input->value();
    commands::LightEditCommand command(pos, intensity);
    _facade->execCommand(&command);
}

void Widget::change_mirrow() {
    commands::MirrorEditCommand command(ui->mir_inp->value());
    _facade->execCommand(&command);
}

void Widget::resizeEvent(QResizeEvent *) {
    render();
}

void Widget::add() {
    AdditionDialog dialog;
    dialog.exec();
    if (dialog.is_added()) {
        std::string obj_name = "Object" + std::to_string(++_elements_num);
        for (auto &obj: dialog.object()) {
            commands::AddModelCommand command(obj_name, obj, dialog.material());
            _facade->execCommand(&command);
        }
        ui->comboBox->addItem(obj_name.c_str());
    }
    dialog.close();
}
