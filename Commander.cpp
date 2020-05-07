//
// Created by toi on 01/04/2020.
//

#include "Commander.hpp"

Vector<Command*> Commander::cmd_list = Vector<Command*>();

Command* Commander::find(char const* cmd){
    for (unsigned i = 0; i < Commander::cmd_list.size(); i++){
        if(*Commander::cmd_list[i] == cmd){
            return Commander::cmd_list[i];
        }
    }
    return nullptr;
}

void Commander::add(Command* item) {
    Commander::cmd_list.push(item);
}

void Commander::run(RunnerType& runner) {
    for (;;){
        char buffer[Commander::BUFFER_SIZE];
        std::cin.getline(buffer, Commander::BUFFER_SIZE);
        std::istringstream iss(buffer);
        char* cmd = buffer;
        iss >> cmd;
        Command* search = Commander::find(cmd);
        bool found = search != nullptr;
        if(!found){
            search = new Command();
        }
        if(!search->action(runner, iss)){
            std::cout << "Wrong command format! Action is NOT done." << std::endl;
            std::cout << *search;
        }
        if(search->canQuit()){
            if(!found){// never
                delete search;
            }
            break;
        }
        if(!found){
            delete search;
        }
    }
}
