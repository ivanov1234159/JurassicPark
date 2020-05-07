//
// Created by toi on 02/05/2020.
//

#ifndef JURASSICPARK_CMDSAVE_HPP
#define JURASSICPARK_CMDSAVE_HPP

#include "../Command.hpp"

class CmdSave : public Command {
public:
    CmdSave();
    virtual bool action(RunnerType& runner, std::istringstream& iss) const override;
};

#endif //JURASSICPARK_CMDSAVE_HPP
