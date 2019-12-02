cmake_minimum_required(VERSION 3.8)
project(viewer)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# включаем поиск библиотек с использованием find_package()
# через REQUIRED указываем, что библиотеки обязательны
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES
        commands/add_model_command.cpp commands/add_model_command.h
        commands/basecommand.h
        commands/move_camera_command.cpp commands/move_camera_command.h
        commands/pitch_camera_command.cpp commands/pitch_camera_command.h
        commands/remove_model_command.cpp commands/remove_model_command.h
        commands/render_command.cpp commands/render_command.h
        commands/roll_camera_command.cpp commands/roll_camera_command.h
        commands/transform_model_command.cpp commands/transform_model_command.h
        commands/yaw_camera_command.cpp commands/yaw_camera_command.h
        exceptions/base_viewer_exeption.h exceptions/camera_lack_exception.h
        exceptions/drawer_exception.h exceptions/file_open_exception.h
        exceptions/model_build_exception.h exceptions/object_search_exception.h
        exceptions/object_type_exception.h
        facade/viewer_facade.cpp facade/viewer_facade.h
        intermediary/intermediary.cpp intermediary/intermediary.h
        math/matrix.cpp math/matrix.h math/vector3d.h math/vector3d.cpp
        math/transform_matrix.cpp math/transform_matrix.h
        objects/camera.h objects/camera.cpp
        objects/object.h
        objects/model.cpp objects/model.h
        render/base_drawer.h render/renderer.cpp render/renderer.h
        render/qt_drawer.cpp render/qt_drawer.h
        scene/scene.h scene/scene.cpp
        transformations/transformer.h transformations/transformer.cpp
        transformations/camera_manager.cpp transformations/camera_manager.h
        uploading/abs_model_loader.h uploading/base_loader.h uploading/base_loader_imp.h
        uploading/file_loader.h uploading/file_loader.cpp
        uploading/model_loader.h uploading/model_loader.cpp
        uploading/model_builder.cpp uploading/model_builder.h
        drawlabel.cpp drawlabel.h
        widget.cpp widget.h lights/BaseLight.h lights/PointLight.cpp lights/PointLight.h objects/geometry_objects/GeometryObject.h objects/geometry_objects/Sphere.cpp objects/geometry_objects/Sphere.h objects/Material.h raytracer/Raytracer.cpp raytracer/Raytracer.h objects/geometry_objects/Triangle.cpp objects/geometry_objects/Triangle.h objects/geometry_objects/Ray.cpp objects/geometry_objects/Ray.h objects/geometry_objects/Parallelepiped.cpp objects/geometry_objects/Parallelepiped.h objects/geometry_objects/Pyramid.cpp objects/geometry_objects/Pyramid.h)

add_executable(viewer main.cpp ${SOURCE_FILES})

set(TEST_SOURCE_FILES
        tests/test_triangle.cpp
        objects/geometry_objects/Triangle.cpp
        objects/geometry_objects/Triangle.h
        objects/geometry_objects/GeometryObject.h
        objects/geometry_objects/Ray.h
        objects/geometry_objects/Ray.cpp
        math/vector3d.h
        math/vector3d.cpp
        math/matrix.h
        math/matrix.cpp)

add_executable(test ${TEST_SOURCE_FILES})


# указываем, какие библиотеки необходимо подключить
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)