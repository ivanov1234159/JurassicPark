//
// Created by toi on 15/05/2020.
//

#include <iostream>
//for: cout, endl
#include "CmdSupplyFood.hpp"
#include "../String.hpp"
#include "../StorageUnit.hpp"

CmdSupplyFood::CmdSupplyFood(): Command("supply", "<food_name> <amount>",
                            "adds the <amount> of food with name <food_name>") {}

bool CmdSupplyFood::action(RunnerType &runner, std::istringstream &iss) const {
    String name;
    iss >> name;
    if(!iss){
        std::cout << "Some error. Cannot read the name." << std::endl;//TODO: fix message
        return false;
    }
    UnitAmount amount;
    iss >> amount;
    if(!iss){
        std::cout << "Some error. Cannot read the amount of food." << std::endl;//TODO: fix message
        return false;
    }
    if(runner.supply(StorageUnit(name, amount))){
        std::cout << "The supply finished successfully." << std::endl;
    }else{
        std::cout << "The supply didn't finish successfully." << std::endl;
    }
    return true;
}