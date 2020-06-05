//
// Created by toi on 07/05/2020.
//

#ifndef JURASSICPARK_CMDADDANIMAL_HPP
#define JURASSICPARK_CMDADDANIMAL_HPP

#include "../Command.hpp"

class CmdAddAnimal : public Command {
public:
    CmdAddAnimal();
    virtual bool action(std::ostream& out, RunnerType& runner, std::istringstream& iss) const override;
};

#endif //JURASSICPARK_CMDADDANIMAL_HPP
