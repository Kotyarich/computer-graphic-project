#include "render_command.h"

namespace commands {

RenderCommand::RenderCommand(std::shared_ptr<render::BaseDrawer> drawer, int sample_n):
    _drawer(drawer), _sample_n(sample_n) {}

void RenderCommand::execute(std::shared_ptr<Intermediary> intermediary) {
    intermediary->draw(_drawer, _sample_n);
}

} // namespace commands
