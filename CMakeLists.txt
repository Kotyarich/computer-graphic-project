cmake_minimum_required(VERSION 3.8)
project(viewer)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -O3")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES
        commands/add_model_command.cpp
        commands/light_edit_command.cpp
        commands/mirror_edit_command.cpp
        commands/move_camera_command.cpp
        commands/pitch_camera_command.cpp
        commands/remove_model_command.cpp
        commands/render_command.cpp
        commands/roll_camera_command.cpp
        commands/yaw_camera_command.cpp
        drawlabel.cpp
        facade/viewer_facade.cpp
        gui/addition_dialog.cpp
        intermediary/intermediary.cpp
        main.cpp
        math/matrix.cpp
        math/vector3d.cpp
        math/transform_matrix.cpp
        objects/camera.cpp
        objects/model.cpp
        render/qt_drawer.cpp
        render/renderer.cpp
        scene/scene.cpp
        transformations/camera_manager.cpp
        lights/PointLight.cpp
        objects/geometry_objects/Sphere.cpp
        raytracer/Raytracer.cpp
        objects/geometry_objects/Triangle.cpp
        objects/geometry_objects/Ray.cpp
        objects/geometry_objects/Parallelepiped.cpp
        objects/geometry_objects/Pyramid.cpp
        objects/geometry_objects/Prism.cpp
        widget.cpp
        commands/add_model_command.h
        commands/basecommand.h
        commands/light_edit_command.h
        commands/mirror_edit_command.h
        commands/move_camera_command.h
        commands/pitch_camera_command.h
        commands/remove_model_command.h
        commands/render_command.h
        commands/roll_camera_command.h
        commands/yaw_camera_command.h
        drawlabel.h
        exceptions/base_viewer_exeption.h
        exceptions/camera_lack_exception.h
        exceptions/drawer_exception.h
        exceptions/file_open_exception.h
        exceptions/model_build_exception.h
        exceptions/object_search_exception.h
        exceptions/object_type_exception.h
        facade/viewer_facade.h
        gui/addition_dialog.h
        intermediary/intermediary.h
        math/matrix.h
        math/vector3d.h
        math/transform_matrix.h
        objects/camera.h
        objects/model.h
        objects/object.h
        render/base_drawer.h
        render/qt_drawer.h
        render/renderer.h
        scene/scene.h
        transformations/camera_manager.h
        lights/BaseLight.h
        lights/PointLight.h
        objects/geometry_objects/GeometryObject.h
        objects/geometry_objects/Sphere.h
        objects/Material.h
        raytracer/Raytracer.h
        objects/geometry_objects/Triangle.h
        objects/geometry_objects/Ray.h
        objects/geometry_objects/Parallelepiped.h
        objects/geometry_objects/Pyramid.h
        objects/geometry_objects/Prism.h
        widget.h)

add_executable(viewer main.cpp ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)