//
// Created by toi on 07/05/2020.
//

#include <iostream>
//for: cout, endl
#include "CmdCreateCage.hpp"
#include "../Commander.hpp"
#include "../Cage.hpp"
#include "../String.hpp"

CmdCreateCage::CmdCreateCage(): Command("create", "<climate> <size>",
        "create a cage with given <climate> and <size>\n<size> can be 'small' (for 1), 'medium' (for 3)\nor 'large' (for 10)")
{}

bool CmdCreateCage::action(RunnerType &runner, std::istringstream& iss) const {
    String climate;
    iss >> climate;
    if(!iss){
        std::cout << "Some error. Cannot read the climate." << std::endl;//TODO: fix message
        return false;
    }
    String size;
    iss >> size;
    if(!iss){
        std::cout << "Some error. Cannot read the size." << std::endl;//TODO: fix message
        return false;
    }
    if(Cage::getCageSize(size) != Cage::DEFAULT_CAGE_SIZE){
        runner.buildCage(climate, size);
        std::cout << "Cage builded successfully!" << std::endl;
    }else{
        std::cout << "Couldn't build the cage. Unknown size." << std::endl;
    }
    return true;
}