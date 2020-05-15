//
// Created by toi on 15/05/2020.
//

#ifndef JURASSICPARK_CMDFEEDANIMALS_HPP
#define JURASSICPARK_CMDFEEDANIMALS_HPP

#include "../Command.hpp"

class CmdFeedAnimals : public Command {
public:
    CmdFeedAnimals();
    virtual bool action(RunnerType& runner, std::istringstream& iss) const override;
};

#endif //JURASSICPARK_CMDFEEDANIMALS_HPP
