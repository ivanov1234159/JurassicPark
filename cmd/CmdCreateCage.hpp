//
// Created by toi on 07/05/2020.
//

#ifndef JURASSICPARK_CMDCREATECAGE_HPP
#define JURASSICPARK_CMDCREATECAGE_HPP

#include "../Command.hpp"

class CmdCreateCage : public Command {
public:
    CmdCreateCage();
    virtual bool action(std::ostream& out, RunnerType& runner, std::istringstream& iss) const override;
};

#endif //JURASSICPARK_CMDCREATECAGE_HPP
