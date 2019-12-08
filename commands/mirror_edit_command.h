#ifndef MIRROR_EDIT_COMMAND_H
#define MIRROR_EDIT_COMMAND_H

#include "basecommand.h"
#include "../intermediary/intermediary.h"

namespace commands {

using intermediary::Intermediary;

class MirrorEditCommand: public BaseCommand {
public:
    explicit MirrorEditCommand(double rough);
    void execute(std::shared_ptr<Intermediary> intermediary) override;
private:
    double _rough;
};

} // namespace commands

#endif // MIRROR_EDIT_COMMAND_H
