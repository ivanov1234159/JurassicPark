//
// Created by toi on 07/05/2020.
//

#include <iostream>
//for: cout
#include "CmdStatus.hpp"
#include "../Cage.hpp"
#include "../Dinosaur.hpp"

CmdStatus::CmdStatus(): Command("status", "", "print the current state of the program") {}

bool CmdStatus::action(RunnerType &runner, std::istringstream&) const {
    std::cout << runner;
    return true;
}