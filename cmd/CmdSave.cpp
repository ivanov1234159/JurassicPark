//
// Created by toi on 02/05/2020.
//

#include "CmdSave.hpp"

CmdSave::CmdSave(): Command("save", "", "save the current state of the program") {}

bool CmdSave::action(RunnerType &runner, std::istringstream&) const {
    std::cout << "Trying to save ... ";
    if(runner.save()) {
        std::cout << "done" << std::endl << "Successfully saved!" << std::endl;
        return true;
    }
    std::cout << std::endl << "Couldn't save the file." << std::endl;
    return true;
}