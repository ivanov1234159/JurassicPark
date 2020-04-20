#include <iostream>
//for: cout, cin, endl
#include <cstring>
//for: strcmp()
#include "tests.hpp"
#include "JurassicPark.hpp"
#include "Dinosaur.hpp"

static const unsigned BUFFER_LENGTH = 100;// including '\0'

void cmd_help();
void cmd_create_cage(JurassicPark& park);
void cmd_add_animal(JurassicPark& park);
void cmd_save(JurassicPark& park);

int main() {
    //runAllTests();
    JurassicPark park;
    //TODO: if has saved file, restore it
    char cmd[10];
    do {
        std::cout << "> ";
        std::cin >> cmd;
        if(std::strcmp(cmd, "exit") == 0){
            break;
        } else if(std::strcmp(cmd, "help") == 0){
            cmd_help();
        } else if(std::strcmp(cmd, "save") == 0){
            cmd_save(park);
        } else if(std::strcmp(cmd, "create") == 0){
            cmd_create_cage(park);
        } else if(std::strcmp(cmd, "add") == 0){
            cmd_add_animal(park);
        //} else if(std::strcmp(cmd, "help") == 0){
        //    cmd_help();
        //} else if(std::strcmp(cmd, "help") == 0){
        //    cmd_help();
        } else {
            std::cout << "Invalid command! Type 'help' for more information." << std::endl;
        }
    } while (true);
    std::cout << "Wait a moment." << std::endl;
    cmd_save(park);
    std::cout << "Bye." << std::endl;
    return 0;
}

void cmd_help(){
    std::cout << "The following commands are supported:" << std::endl << std::endl;
    std::cout << "create <climate> <size>" << std::endl;
    std::cout << "\t\t- create a cage with given climate and size" << std::endl;
    //std::cout << "\t\t- climate has no specifications" << std::endl;
    std::cout << "\t\t- size MUST be 'small' (for 1), 'medium' (for 3)" << std::endl;
    std::cout << "\t\t  or 'large' (for 10)" << std::endl;
    std::cout << "save" << std::endl;
    std::cout << "\t\t- save all data for the zoopark" << std::endl;
    std::cout << "help" << std::endl;
    std::cout << "\t\t- prints this information" << std::endl;
    std::cout << "exit" << std::endl;
    std::cout << "\t\t- exit from the program" << std::endl;
    std::cout << "\t\t  but before that do the 'save' command" << std::endl;
    std::cout << "add <name> <gender> <era> <type> <species> <food>" << std::endl;
    std::cout << "\t\t- add a new dinosaur in the zoopark" << std::endl;
    std::cout << "\t\t- TODO: no info" << std::endl;
}

void cmd_create_cage(JurassicPark& park){
    char climate[BUFFER_LENGTH];
    std::cin >> climate;
    char size[BUFFER_LENGTH];
    std::cin >> size;
    if(Cage::getCageSize(size) != Cage::DEFAULT_CAGE_SIZE){
        park.buildCage(climate, size);
        std::cout << "Cage builded successfully!" << std::endl;
    }else{
        std::cout << "Couldn't build the cage. Size didn't match." << std::endl;
    }
}

void cmd_add_animal(JurassicPark& park){
    Dinosaur dino;
    bool success = true;
    char buff[BUFFER_LENGTH];
    std::cin >> buff;
    dino.setName(buff);
    std::cin >> buff;
    if(!dino.setGender(buff)){
        success = false;
        std::cout << "Invalid gender." << std::endl;
    }
    std::cin >> buff;
    if(!dino.setEra(buff)){
        success = false;
        std::cout << "Invalid era." << std::endl;
    }
    std::cin >> buff;
    if(!dino.setType(buff)){
        success = false;
        std::cout << "Invalid type." << std::endl;
    }
    std::cin >> buff;
    if(!dino.setSpecies(buff)){
        success = false;
        std::cout << "Invalid species." << std::endl;
    }
    std::cin >> buff;
    if(!dino.setFood(buff)){
        success = false;
        std::cout << "Invalid food name." << std::endl;
    }
    if(!success) {
        std::cout << "Type 'help' for more information." << std::endl;
    } else if(!park.addAnimal(dino)){
        std::cout << "No cage for this dinosaur. Please create one." << std::endl;
    } else {
        std::cout << "The dinosaur added successfully." << std::endl;
    }
}

void cmd_save(JurassicPark& park){
    std::cout << "Strating procedure of saving the data ... ";
    bool error = false;
    //TODO: save the data
    if(!error){
        std::cout << "Done" << std::endl;
    }
}