#include "addition_dialog.h"
#include <ui_addition_dialog.h>
#include <QtWidgets/QColorDialog>
#include <iostream>

AdditionDialog::AdditionDialog(QWidget *parent)
    : QDialog(parent),
      _ui(new Ui::Dialog),
      _color(Qt::red),
      _added(false) {
    _ui->setupUi(this);
}

AdditionDialog::~AdditionDialog() {
    delete _ui;
}

void AdditionDialog::color() {
    auto color = QColorDialog::getColor();
    if (color.isValid()) {
        _color = color;
        std::string style = "background-color: rgb("
                + std::to_string(color.red()) + ","
                + std::to_string(color.green()) + ","
                + std::to_string(color.blue()) + ");";
        _ui->pushButton->setStyleSheet(QString(style.c_str()));
    }
}

void AdditionDialog::accept() {
    switch (_ui->tabWidget->currentIndex()) {
    case 0:
        createSphere();
        break;
    case 1:
        createParallelepiped();
        break;
    case 2:
        createPyramid();
        break;
    case 3:
        createPrism();
    }
    createMaterial();
    _added = true;
    close();
}

void AdditionDialog::cancel() {
    close();
}

std::vector<std::shared_ptr<objects::GeometryObject>> AdditionDialog::object() const {
    return _object;
}

Material AdditionDialog::material() const {
    return _material;
}

bool AdditionDialog::is_added() const {
    return _added;
}

void AdditionDialog::createSphere() {
    double x = _ui->s_x->value();
    double y = _ui->s_y->value();
    double z = _ui->s_z->value();
    double r = _ui->s_r->value();
    _object.push_back(std::make_shared<objects::Sphere>(math::Vector3d(x, y, z), r));
}

void AdditionDialog::createParallelepiped() {
    math::Vector3d dot = {_ui->paral_x->value(), _ui->paral_y->value(), _ui->paral_z->value()};
    double w = _ui->paral_w->value();
    double h = _ui->paral_h->value();
    double l = _ui->paral_l->value();
    double angle = _ui->paral_a->value();

    auto triangles = objects::Parallelepiped(dot, w, l, h, angle).get_polygons();
    _object.resize(triangles.size());
    for (size_t i = 0; i < triangles.size(); i++) {
        _object[i].reset(triangles[i]);
    }
}

void AdditionDialog::createPyramid() {
    math::Vector3d dot = {_ui->pyr_x->value(), _ui->pyr_y->value(), _ui->pyr_z->value()};
    double h = _ui->pyr_h->value();
    double l = _ui->pyr_l->value();
    double angle = _ui->pyr_a->value();

    auto triangles = objects::Pyramid(dot, l, h, angle).get_polygons();
    _object.resize(triangles.size());
    for (size_t i = 0; i < triangles.size(); i++) {
        _object[i].reset(triangles[i]);
    }
}

void AdditionDialog::createPrism() {
    math::Vector3d dot = {_ui->pr_x->value(), _ui->pr_y->value(), _ui->pr_z->value()};
    double h = _ui->pr_h->value();
    double l = _ui->pr_l->value();
    double angle = _ui->pr_a->value();

    auto triangles = objects::Prism(dot, l, h, angle).get_polygons();
    _object.resize(triangles.size());
    for (size_t i = 0; i < triangles.size(); i++) {
        _object[i].reset(triangles[i]);
    }
}

void AdditionDialog::createMaterial() {
    double spec = _ui->spec->value();
    double refl = _ui->refl->value();
    double rough = _ui->rough->value();
    _material = {
        math::Vector3d{
            double(_color.red()),
            double(_color.green()),
            double(_color.blue())},
        spec, refl, rough
    };
}
