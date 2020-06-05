//
// Created by toi on 05/06/2020.
//

#include "CmdHire.hpp"
#include "../StorageUnit.hpp"

CmdHire::CmdHire(): Command("hire", "<count>", "hire a new staff (<count> of them)") {}

bool CmdHire::action(std::ostream& out, RunnerType &runner, std::istringstream &iss) const {
    UnitAmount count;
    iss >> count;
    if(!iss){
        out << "Some error. Cannot read the count." << std::endl;
        return false;
    }
    out << "The new staff was ";
    if(!runner.addStaff(count)){
        out << "NOT ";
    }
    out << "hired successfully." << std::endl;
    return true;
}