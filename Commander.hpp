//
// Created by toi on 01/04/2020.
//

#ifndef JURASSICPARK_COMMANDER_HPP
#define JURASSICPARK_COMMANDER_HPP

#include <iostream>
//for: cout, endl, ostream
#include "Command.hpp"
#include "Vector.hpp"
#include "String.hpp"

class Commander {
private:
    static Vector<Command*> cmd_list;
    Commander() = delete;
    Commander(Commander const& other) = delete;
    Commander& operator=(Commander const& other) = delete;

    /**
     * search for a command called <cmd>
     * @param cmd
     * @return nullptr if not found
     */
    static Command* find(String const& cmd);

    /// free the memory and removes the commands
    static void clear();
public:
    static const unsigned BUFFER_SIZE = 256;
    friend class CmdHelp;

    /**
     * add the command in the list (cmd_list)
     * @param item
     */
    static void add(Command* item);

    /**
     * base function for the class
     * @param runner
     */
    static void run(RunnerType& runner);

    /**
     * calls the command named <cmd>; if no such command, uses the "empty" ("default") command
     * @param cmd
     * @param runner
     * @param iss
     * @param out
     * @return false if the command can quit
     */
    static bool call(String const& cmd, RunnerType& runner, std::istringstream& iss, std::ostream& out);
};

/// used to add all commands to the array (cmd_list)
void build_commands();

#endif //JURASSICPARK_COMMANDER_HPP
