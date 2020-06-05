//
// Created by toi on 02/05/2020.
//

#include <iostream>
//for: cout, endl
#include "CmdExit.hpp"
#include "../Commander.hpp"

CmdExit::CmdExit(): Command("exit", "[ <save> = Yes ]",
        "exit from the program\nbut before that do the 'save' command if <save> equals Yes or yes", true) {}

bool CmdExit::action(std::ostream& out, RunnerType &runner, std::istringstream &iss) const {
    out << "Exiting the program..." << std::endl;
    char answer;
    iss >> answer;
    if(!iss || answer == 'y' || answer == 'Y'){
        iss.clear();
        out << "Wait a moment." << std::endl;
        Commander::call("save", runner, iss, out);
    }
    out << "Bye." << std::endl;
    return true;
}