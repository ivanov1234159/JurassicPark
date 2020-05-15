//
// Created by toi on 15/05/2020.
//

#include <iostream>
//for: cout, endl
#include "CmdFeedAnimals.hpp"

CmdFeedAnimals::CmdFeedAnimals(): Command("feed", "", "feeds all animals in the zoopark") {}

bool CmdFeedAnimals::action(RunnerType &runner, std::istringstream&) const {
    std::cout << "Starting to feed the animals ..." << std::endl;
    if(runner.feedAllAnimals()){
        std::cout << "All animals were fed up successfully." << std::endl;
    }else{
        std::cout << "There was a problem in one of the cages. The rest of the animals aren't feed up." << std::endl;
    }
    return true;
}