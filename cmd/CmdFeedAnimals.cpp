//
// Created by toi on 15/05/2020.
//

#include "CmdFeedAnimals.hpp"

CmdFeedAnimals::CmdFeedAnimals(): Command("feed", "", "feeds all animals in the zoopark") {}

bool CmdFeedAnimals::action(std::ostream& out, RunnerType &runner, std::istringstream&) const {
    out << "Starting to feed the animals ..." << std::endl;
    if(runner.feedAllAnimals()){
        out << "All animals were fed up successfully." << std::endl;
    }else{
        out << "There was a problem in one of the cages. The rest of the animals aren't feed up." << std::endl;
    }
    return true;
}