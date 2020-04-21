//
// Created by toi on 08/04/2020.
//

#include "Commander.hpp"

/* For all of the following functions:
 *      returns false if there is a problem with the arguments (their type or count)
 *
 * MUST handle the situation when the runner cannot do the operation
 */

bool cmd_exit(RunnerType& runner, std::istringstream& iss){
    /* NEEDED; executes before break the while in Commander::run() */

    std::cout << "Exiting the program..." << std::endl;
    std::cout << "Wait a moment." << std::endl;
    Commander::call("save", runner, iss);
    std::cout << "Bye." << std::endl;
    return true;
}

bool cmd_save(RunnerType& runner, std::istringstream&){
    std::cout << "Trying to save ... ";
    if(runner.save()) {
        std::cout << "done" << std::endl << "Successfully saved!" << std::endl;
        return true;
    }
    std::cout << std::endl << "Couldn't save the file." << std::endl;
    return false;
}

bool cmd_help(RunnerType&, std::istringstream&){
    std::cout << "Support the following commands:" << std::endl;
    for(unsigned i = 0; i < Commander::cmd_count; i++){
        Commander::outUsage(i, std::cout);
    }
    return true;
}

bool cmd_create_cage(RunnerType& runner, std::istringstream& iss){
    char climate[Commander::BUFFER_SIZE];
    iss >> climate;
    if(!iss){
        std::cout << "Some error." << std::endl;//TODO: fix message
        return false;
    }
    char size[Commander::BUFFER_SIZE];
    iss >> size;
    if(!iss){
        std::cout << "Some error." << std::endl;//TODO: fix message
        return false;
    }
    if(Cage::getCageSize(size) != Cage::DEFAULT_CAGE_SIZE){
        runner.buildCage(climate, size);
        std::cout << "Cage builded successfully!" << std::endl;
    }else{
        std::cout << "Couldn't build the cage. Unknown size." << std::endl;
    }
    return true;
}

void build_commands(){
    Commander::add(Command("exit", "", "exit from the program", cmd_exit));
    Commander::add(Command("save", "", "save the current state of the program", cmd_save));
    Commander::add(Command("help", "", "prints this information", cmd_help));
    Commander::add(Command("create", "<climate> <size>", "create a cage with given <climate> and <size>\n<size> can be 'small' (for 1), 'medium' (for 3)\nor 'large' (for 10)", cmd_create_cage));
}