//
// Created by toi on 15/05/2020.
//

#include "CmdSupplyFood.hpp"
#include "../String.hpp"
#include "../StorageUnit.hpp"

CmdSupplyFood::CmdSupplyFood(): Command("supply", "<food_name> <amount>",
                            "adds the <amount> of food with name <food_name>") {}

bool CmdSupplyFood::action(std::ostream& out, RunnerType &runner, std::istringstream &iss) const {
    String name;
    iss >> name;
    if(!iss){
        out << "Some error. Cannot read the name." << std::endl;
        return false;
    }
    UnitAmount amount;
    iss >> amount;
    if(!iss){
        out << "Some error. Cannot read the amount of food." << std::endl;
        return false;
    }
    if(runner.supply(StorageUnit(name, amount))){
        out << "The supply finished successfully." << std::endl;
    }else{
        out << "The supply didn't finish successfully." << std::endl;
    }
    return true;
}