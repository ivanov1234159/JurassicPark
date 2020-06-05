//
// Created by toi on 05/06/2020.
//

#include "CmdRemoveAnimal.hpp"

CmdRemoveAnimal::CmdRemoveAnimal(): Command("remove", "<name>", "remove an already existing animal with <name>") {}

bool CmdRemoveAnimal::action(std::ostream& out, RunnerType &runner, std::istringstream &iss) const {
    String name;
    iss >> name;
    if(!iss){
        out << "Some error. Cannot read the name." << std::endl;
        return false;
    }
    if(runner.removeAnimal(name)){
        out << "The dinosaur was removed successfully." << std::endl;
    } else {
        out << "There isn't a dinosaur named " << name << '.' << std::endl;
    }
    return true;
}