//
// Created by toi on 07/05/2020.
//

#ifndef JURASSICPARK_CMDSTATUS_HPP
#define JURASSICPARK_CMDSTATUS_HPP

#include "../Command.hpp"

class CmdStatus : public Command {
public:
    CmdStatus();
    virtual bool action(RunnerType& runner, std::istringstream& iss) const override;
};

#endif //JURASSICPARK_CMDSTATUS_HPP
