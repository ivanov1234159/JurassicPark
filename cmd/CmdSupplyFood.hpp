//
// Created by toi on 15/05/2020.
//

#ifndef JURASSICPARK_CMDSUPPLYFOOD_HPP
#define JURASSICPARK_CMDSUPPLYFOOD_HPP

#include "../Command.hpp"

class CmdSupplyFood : public Command {
public:
    CmdSupplyFood();
    virtual bool action(std::ostream& out, RunnerType& runner, std::istringstream& iss) const override;
};

#endif //JURASSICPARK_CMDSUPPLYFOOD_HPP
