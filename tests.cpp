//
// Created by toi on 26/03/2020.
//

#include <iostream>
#include "tests.hpp"
#include "JurassicPark.hpp"
#include "Dinosaur.hpp"

void runAllTests(){
    std::clog << "-------------------------------------------------------------" << std::endl;
    std::clog << "Strarting all tests." << std::endl;
    std::clog << "-------------------------------------------------------------" << std::endl;
    int success = 0;

    JurassicPark park;
    success += testBuildCage(park);
    success += testAddFood(park);
    success += testAddAnimal(park);
    success += testRemoveAnimal(park);

    std::clog << "-------------------------------------------------------------" << std::endl;
    std::clog << "Count of all successfully finished tests is " << success << " (from 4 total)" << std::endl;
    std::clog << "-------------------------------------------------------------" << std::endl;
}

bool testBuildCage(JurassicPark& park){
    std::clog << "Strarting test for: building cage" << std::endl;
    bool success = true;

    Cage cage("continental", "large");
    park.buildCage(cage);

    std::clog << "Test finished " << (success ? "" : "un") << "successfully!" << std::endl;
    return success;
}

bool testAddFood(JurassicPark& park){
    std::clog << "Strarting test for: adding food" << std::endl;
    bool success = true;

    success &= park.addFood("meat", 120.80);

    std::clog << "Test finished " << (success ? "" : "un") << "successfully!" << std::endl;
    return success;
}

bool testAddAnimal(JurassicPark& park){
    std::clog << "Strarting test for: adding animal" << std::endl;
    bool success = true;

    Dinosaur dino;
    success &= dino.setName("Rexy");
    success &= dino.setGender("male");
    success &= dino.setEra("cretaceous");
    success &= dino.setType("carnivorous");
    success &= dino.setSpecies("tyrannosaurus");
    success &= dino.setFood("meat");
    success &= park.addAnimal(dino);

    std::clog << "Test finished " << (success ? "" : "un") << "successfully!" << std::endl;
    return success;
}

bool testRemoveAnimal(JurassicPark& park){
    std::clog << "Strarting test for: removing animal" << std::endl;
    bool success = true;

    success &= park.removeAnimal("Rexy");

    std::clog << "Test finished " << (success ? "" : "un") << "successfully!" << std::endl;
    return success;
}















