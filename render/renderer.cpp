#include "renderer.h"
#include <thread>

namespace render {

void Renderer::setDrawer(std::shared_ptr<BaseDrawer> drawer) {
    _drawer = drawer;
}

void Renderer::render(scene::Scene &scene, int sample_num) {
    if (!_drawer) {
        throw exceptions::DrawerInitException("Drawer wasn't set");
    }

    _raytracer.setScene(&scene);
    _raytracer.setSamplesNum(sample_num);
    auto size = _drawer->getSize();
    size.first = size.second = 600;

    std::vector<std::thread> threads;
    int threads_number = 6;
    for (int i = 0; i < threads_number; i++) {
        int n = size.second / threads_number;
        int y0 = -size.second / 2 + i * n;
        std::thread thread(
            [this](scene::Scene scene1, int y_start, int delta) { this->threadRender(scene1, y_start, delta); },
            scene, y0, n);
        threads.push_back(std::move(thread));
    }

    for (auto &thr: threads) {
        if (thr.joinable()) {
            thr.join();
        }
    }
}

Vector3d Renderer::rotatePoint(math::Vector3d &p, Camera &camera) {        
    std::shared_ptr<Matrix> transform_matrix(new RotateOxMatrix(-camera.getXAngle()));
    p.transform(transform_matrix);
    transform_matrix.reset(new RotateOyMatrix(-camera.getYAngle()));
    p.transform(transform_matrix);
    transform_matrix.reset(new RotateOzMatrix(-camera.getZAngle()));
    p.transform(transform_matrix);

    return p;
}

Vector3d Renderer::canvasToViewport(double x, double y) {
    auto size = _drawer->getSize();
    size.first = size.second = 600;
    double v = double(size.second) / size.first;
    return {x / v / size.first, y / size.second, 1};
}

void Renderer::threadRender(scene::Scene &scene, int y0, int n) {
    auto camera = scene.getCamera();
    Vector3d cam_position = camera->getPosition();
    auto size = _drawer->getSize();
    size.first = size.second = 600;

    for (int x = -size.first / 2; x < size.first / 2; x++) {
        for (int y = y0; y < y0 + n; y++) {
            auto direction = canvasToViewport(x, y);
            direction = rotatePoint(direction, *camera);
            auto result_color = _raytracer.traceRay(Ray(cam_position, direction), 1, 2000000, 3);

            result_color = result_color.clamp();
            QColor q_color(result_color.x(), result_color.y(), result_color.z());
            _mutex.lock();
            _drawer->drawPoint(q_color, x, y);
            _mutex.unlock();
        }
    }
}

} // namespace render
