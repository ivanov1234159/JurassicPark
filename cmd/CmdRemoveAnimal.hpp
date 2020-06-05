//
// Created by toi on 05/06/2020.
//

#ifndef JURASSICPARK_CMDREMOVEANIMAL_HPP
#define JURASSICPARK_CMDREMOVEANIMAL_HPP

#include "../Command.hpp"

class CmdRemoveAnimal : public Command {
public:
    CmdRemoveAnimal();
    virtual bool action(std::ostream& out, RunnerType& runner, std::istringstream& iss) const override;
};

#endif //JURASSICPARK_CMDREMOVEANIMAL_HPP
