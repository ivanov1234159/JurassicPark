//
// Created by toi on 02/05/2020.
//

#include <iostream>
//for: cout, endl
#include "CmdExit.hpp"
#include "../Commander.hpp"

CmdExit::CmdExit(): Command("exit", "[ <save> = Yes ]",
        "exit from the program\nbut before that do the 'save' command if <save> equals Yes or yes", true) {}

bool CmdExit::action(RunnerType &runner, std::istringstream &iss) const {
    std::cout << "Exiting the program..." << std::endl;
    char answer;
    iss >> answer;
    if(!iss || answer == 'y' || answer == 'Y'){
        iss.clear();
        std::cout << "Wait a moment." << std::endl;
        Commander::call("save", runner, iss);
    }
    std::cout << "Bye." << std::endl;
    return true;
}