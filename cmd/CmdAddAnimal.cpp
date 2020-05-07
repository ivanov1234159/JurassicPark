//
// Created by toi on 07/05/2020.
//

#include "CmdAddAnimal.hpp"
#include "../Commander.hpp"
#include "../Dinosaur.hpp"

CmdAddAnimal::CmdAddAnimal(): Command("add", "<name> <gender> <era> <type> <species> <food>",
        "add a new dinosaur in the zoopark") {}

bool CmdAddAnimal::action(RunnerType &runner, std::istringstream& iss) const {
    char buff[Commander::BUFFER_SIZE];
    iss >> buff;
    if(!iss){
        std::cout << "Some error. Cannot read the name." << std::endl;//TODO: fix message
        return false;
    }
    Dinosaur dino;
    dino.setName(buff);
    iss >> buff;
    if(!iss || !dino.setGender(buff)){
        std::cout << "Invalid gender." << std::endl;
        return false;
    }
    iss >> buff;
    if(!iss || !dino.setEra(buff)){
        std::cout << "Invalid era." << std::endl;
        return false;
    }
    iss >> buff;
    if(!iss || !dino.setType(buff)){
        std::cout << "Invalid type." << std::endl;
        return false;
    }
    iss >> buff;
    if(!iss || !dino.setSpecies(buff)){
        std::cout << "Invalid species." << std::endl;
        return false;
    }
    iss >> buff;
    if(!iss || !dino.setFood(buff)){
        std::cout << "Invalid food name." << std::endl;
        return false;
    }
    if(!runner.addAnimal(dino)){
        std::cout << "No cage for this dinosaur. Please create one." << std::endl;
    } else {
        std::cout << "The dinosaur added successfully." << std::endl;
    }
    return true;
}