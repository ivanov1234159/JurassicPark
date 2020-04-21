//
// Created by toi on 01/04/2020.
//

#include "Commander.hpp"

unsigned Commander::cmd_count = 0;
unsigned Commander::cmd_count_max = 2;
Command* Commander::cmd_list = new Command[Commander::cmd_count_max];

void Commander::resize() {
    Commander::cmd_count_max *= 2;
    Command* temp = Commander::cmd_list;
    Commander::cmd_list = new Command[Commander::cmd_count_max];
    for(unsigned i = 0; i < Commander::cmd_count; i++){
        Commander::cmd_list[i] = temp[i];
    }
}

int Commander::findIndex(char const* cmd){
    for (unsigned i = 0; i < Commander::cmd_count; i++){
        if(Commander::cmd_list[i] == cmd){
            return i;
        }
    }
    return -1;
}

void Commander::outUsage(unsigned index, std::ostream& out){
    out << Commander::cmd_list[index];
}

void Commander::add(Command const& item) {
    if(Commander::cmd_count == Commander::cmd_count_max){
        Commander::resize();
    }
    Commander::cmd_list[Commander::cmd_count++] = item;
}

void commander_error(bool print_help = true){
    std::cout << "Invalid command!";
    if(print_help){
        std::cout << " Type 'help' for more information.";
    }
    std::cout << std::endl;
}

void Commander::run(RunnerType& runner) {
    while (true){
        char buffer[Commander::BUFFER_SIZE];
        //char* buffer = new char[Commander::BUFFER_SIZE];
        std::cin.getline(buffer, Commander::BUFFER_SIZE);
        std::istringstream iss(buffer);
        //delete[] buffer;
        char* cmd = buffer;
        iss >> cmd;
        int index = Commander::findIndex(cmd);
        if(index >= 0){
            if(!Commander::cmd_list[index].call(runner, iss)){
                commander_error(false);
                Commander::outUsage(index, std::cout);
            }
            if(index == Commander::EXIT){
                break;
            }
        } else {
            commander_error();
        }
    }
}
