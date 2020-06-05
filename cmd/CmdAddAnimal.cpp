//
// Created by toi on 07/05/2020.
//

#include <iostream>
//for: cout, endl
#include "CmdAddAnimal.hpp"
#include "../Commander.hpp"
#include "../Dinosaur.hpp"
#include "../String.hpp"

CmdAddAnimal::CmdAddAnimal(): Command("add", "<name> <gender> <era> <type> <species> <food>",
        "add a new dinosaur in the zoopark") {}

bool CmdAddAnimal::action(std::ostream& out, RunnerType &runner, std::istringstream& iss) const {
    String buff;
    iss >> buff;
    if(!iss){
        out << "Some error. Cannot read the name." << std::endl;
        return false;
    }
    Dinosaur dino;
    dino.setName(buff);
    iss >> buff;
    if(!iss || !dino.setGender(buff)){
        out << "Invalid gender." << std::endl;
        return false;
    }
    iss >> buff;
    if(!iss || !dino.setEra(buff)){
        out << "Invalid era." << std::endl;
        return false;
    }
    iss >> buff;
    if(!iss || !dino.setType(buff)){
        out << "Invalid type." << std::endl;
        return false;
    }
    iss >> buff;
    if(!iss || !dino.setSpecies(buff)){
        out << "Invalid species." << std::endl;
        return false;
    }
    iss >> buff;
    if(!iss || !dino.setFood(buff)){
        out << "Invalid food name." << std::endl;
        return false;
    }
    dino.setFoodAmount(1);//TODO: its better to be read from the console
    if(runner.hasDinosaur(dino.getName())){
        out << "Duplicate name. Please, change the name of your dinosaur." << std::endl;
        return true;
    }
    if(!runner.addAnimal(dino)){
        out << "No cage for this dinosaur. Please create one." << std::endl;
    } else {
        out << "The dinosaur added successfully." << std::endl;
    }
    return true;
}