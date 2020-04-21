//
// Created by toi on 01/04/2020.
//

#ifndef JURASSICPARK_COMMANDER_HPP
#define JURASSICPARK_COMMANDER_HPP

#include <iostream>
//for: cout, endl, ostream
#include "Command.hpp"

class Commander {
private:
    static const unsigned EXIT = 0;
    static unsigned cmd_count;
    static unsigned cmd_count_max;
    static Command* cmd_list;
    Commander() = delete;
    Commander(Commander const& other) = delete;
    Commander& operator=(Commander const& other) = delete;

    static void resize();
    static int findIndex(char const* cmd);// returns -1 if not found
    static void outUsage(unsigned index, std::ostream& out);
public:
    static const unsigned BUFFER_SIZE = 256;
    friend bool cmd_help(RunnerType&, std::istringstream&);// uses ONLY cmd_count and outUsage()
    static void add(Command const& item);
    static void run(RunnerType& runner);
};

/*
 * !!! IMPORTANT !!!
 * the exit command MUST be first, else change the static const in Commander class named EXIT
 *
 * the help command has a special function named cmd_help from type FuncCMD
 */
void build_commands();

#endif //JURASSICPARK_COMMANDER_HPP
