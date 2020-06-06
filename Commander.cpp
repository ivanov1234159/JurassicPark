//
// Created by toi on 01/04/2020.
//

#include "Commander.hpp"

Vector<Command*> Commander::cmd_list = Vector<Command*>();

Command* Commander::find(String const& cmd){
    for (unsigned i = 0; i < Commander::cmd_list.size(); i++){
        if(*Commander::cmd_list[i] == cmd){
            return Commander::cmd_list[i];
        }
    }
    return nullptr;
}

void Commander::clear() {
    while (!cmd_list.empty()){
        delete cmd_list.pop();
    }
    cmd_list = Vector<Command*>();
}

void Commander::add(Command* item) {
    Commander::cmd_list.push(item);
}

void Commander::run(RunnerType& runner) {
    for (;;){
        char buffer[Commander::BUFFER_SIZE];
        std::cin.getline(buffer, Commander::BUFFER_SIZE);
        std::istringstream iss(buffer);
        String cmd;
        iss >> cmd;
        if(!Commander::call(cmd, runner, iss, std::cout)){
            break;
        }
    }
    Commander::clear();
}

bool Commander::call(String const& cmd, RunnerType& runner, std::istringstream& iss, std::ostream& out) {
    Command* search = Commander::find(cmd);
    bool found = search != nullptr;
    if(!found){
        search = new Command();
    }
    if(!search->action(out, runner, iss)){
        out << "Wrong command format! Action is NOT done." << std::endl;
        out << *search;
    }
    if(search->canQuit()){
        if(!found){
            delete search;
        }
        return false;
    }
    if(!found){
        delete search;
    }
    return true;
}