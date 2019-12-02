#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <memory>
#include "drawlabel.h"
#include "math/vector3d.h"
#include "commands/add_model_command.h"
#include "commands/render_command.h"
#include "commands/transform_model_command.h"
#include "commands/yaw_camera_command.h"
#include "commands/roll_camera_command.h"
#include "commands/pitch_camera_command.h"
#include "commands/transform_model_command.h"
#include "commands/move_camera_command.h"
#include "commands/remove_model_command.h"
#include "exceptions/file_open_exception.h"
#include "exceptions/camera_lack_exception.h"
#include "facade/viewer_facade.h"
#include "render/qt_drawer.h"

namespace Ui {
class Widget;
}

using facade::ViewerFacade;
using math::Vector3d;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void render();

private:
    Ui::Widget *ui;
    DrawLabel *_draw_label;
    QImage _pixmap;
    std::unique_ptr<ViewerFacade> _facade;
    size_t _elements_num;
};

#endif // WIDGET_H
