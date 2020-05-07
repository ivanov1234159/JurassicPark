//
// Created by toi on 01/04/2020.
//

#ifndef JURASSICPARK_COMMANDER_HPP
#define JURASSICPARK_COMMANDER_HPP

#include <iostream>
//for: cout, endl, ostream
#include "Command.hpp"
#include "Vector.hpp"

class Commander {
private:
    static Vector<Command*> cmd_list;
    Commander() = delete;
    Commander(Commander const& other) = delete;
    Commander& operator=(Commander const& other) = delete;

    static Command* find(char const* cmd);// returns nullptr if not found
public:
    static const unsigned BUFFER_SIZE = 256;
    friend class CmdHelp;
    static void add(Command* item);
    static void run(RunnerType& runner);
};

void build_commands();

#endif //JURASSICPARK_COMMANDER_HPP
