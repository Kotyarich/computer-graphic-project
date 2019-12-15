#-------------------------------------------------
#
# Project created by QtCreator 2019-05-19T00:24:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = viewer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        commands/add_model_command.cpp \
        commands/light_edit_command.cpp \
        commands/mirror_edit_command.cpp \
        commands/move_camera_command.cpp \
        commands/pitch_camera_command.cpp \
        commands/remove_model_command.cpp \
        commands/render_command.cpp \
        commands/roll_camera_command.cpp \
        commands/yaw_camera_command.cpp \
        drawlabel.cpp \
        facade/viewer_facade.cpp \
        gui/addition_dialog.cpp \
        intermediary/intermediary.cpp \
        main.cpp \
        math/matrix.cpp \
        math/vector3d.cpp \
        math/transform_matrix.cpp \
        objects/camera.cpp \
        objects/model.cpp \
        render/qt_drawer.cpp \
        render/renderer.cpp \
        scene/scene.cpp \
        transformations/camera_manager.cpp \
        lights/PointLight.cpp \
        objects/geometry_objects/Sphere.cpp \
        raytracer/Raytracer.cpp \
        objects/geometry_objects/Triangle.cpp \
        objects/geometry_objects/Ray.cpp \
        objects/geometry_objects/Parallelepiped.cpp \
        objects/geometry_objects/Pyramid.cpp \
        objects/geometry_objects/Prism.cpp \
        widget.cpp

HEADERS += \
        commands/add_model_command.h \
        commands/basecommand.h \
        commands/light_edit_command.h \
        commands/mirror_edit_command.h \
        commands/move_camera_command.h \
        commands/pitch_camera_command.h \
        commands/remove_model_command.h \
        commands/render_command.h \
        commands/roll_camera_command.h \
        commands/yaw_camera_command.h \
        drawlabel.h \
        exceptions/base_viewer_exeption.h \
        exceptions/camera_lack_exception.h \
        exceptions/drawer_exception.h \
        exceptions/file_open_exception.h \
        exceptions/model_build_exception.h \
        exceptions/object_search_exception.h \
        exceptions/object_type_exception.h \
        facade/viewer_facade.h \
        gui/addition_dialog.h \
        intermediary/intermediary.h \
        math/matrix.h \
        math/vector3d.h \
        math/transform_matrix.h \
        objects/camera.h \
        objects/model.h \
        objects/object.h \
        render/base_drawer.h \
        render/qt_drawer.h \
        render/renderer.h \
        scene/scene.h \
        transformations/camera_manager.h \
        lights/BaseLight.h \
        lights/PointLight.h \
        objects/geometry_objects/GeometryObject.h \
        objects/geometry_objects/Sphere.h \
        objects/Material.h \
        raytracer/Raytracer.h \
        objects/geometry_objects/Triangle.h \
        objects/geometry_objects/Ray.h \
        objects/geometry_objects/Parallelepiped.h \
        objects/geometry_objects/Pyramid.h \
        objects/geometry_objects/Prism.h \
        widget.h

FORMS += \
        gui/addition_dialog.ui \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
