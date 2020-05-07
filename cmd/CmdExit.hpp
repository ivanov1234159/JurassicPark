//
// Created by toi on 02/05/2020.
//

#ifndef JURASSICPARK_CMDEXIT_HPP
#define JURASSICPARK_CMDEXIT_HPP

#include "../Command.hpp"

class CmdExit : public Command {
public:
    CmdExit();
    virtual bool action(RunnerType& runner, std::istringstream& iss) const override;
};

#endif //JURASSICPARK_CMDEXIT_HPP
