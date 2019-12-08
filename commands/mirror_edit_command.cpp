#include "mirror_edit_command.h"

commands::MirrorEditCommand::MirrorEditCommand(double rough): _rough(rough) {}

void commands::MirrorEditCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    intermediary->changeMirror(_rough);
}
