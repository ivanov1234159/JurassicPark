//
// Created by toi on 05/06/2020.
//

#ifndef JURASSICPARK_CMDHIRE_HPP
#define JURASSICPARK_CMDHIRE_HPP

#include "../Command.hpp"

class CmdHire : public Command {
public:
    CmdHire();
    virtual bool action(std::ostream& out, RunnerType& runner, std::istringstream& iss) const override;
};

#endif //JURASSICPARK_CMDHIRE_HPP
