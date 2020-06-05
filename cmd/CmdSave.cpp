//
// Created by toi on 02/05/2020.
//

#include <iostream>
//for: cout, endl
#include "CmdSave.hpp"

CmdSave::CmdSave(): Command("save", "", "save the current state of the program") {}

bool CmdSave::action(std::ostream& out, RunnerType &runner, std::istringstream&) const {
    out << "Trying to save ... ";
    if(runner.save()) {
        out << "done" << std::endl << "Successfully saved!" << std::endl;
        return true;
    }
    out << std::endl << "Couldn't save the file." << std::endl;
    return true;
}