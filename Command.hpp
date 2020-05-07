//
// Created by toi on 08/04/2020.
//

#ifndef JURASSICPARK_COMMAND_HPP
#define JURASSICPARK_COMMAND_HPP

#include <iostream>
//for: ostream, cout, endl
#include <sstream>
//for: istringstream
#include "Program.hpp"

typedef Program RunnerType;

class Command {
    char* m_name;
    char* m_params;
    char* m_notes;
    bool m_quit_when_done;
public:
    Command();
    Command(char const* name, char const* params, char const* notes, bool quit = false);
    Command(Command const& other);
    Command& operator=(Command const& other);
    virtual ~Command();

    bool operator==(char const* cmd);
    bool canQuit() const;

    virtual bool action(RunnerType& runner, std::istringstream& iss) const;

    friend std::ostream& operator<<(std::ostream& out, Command const& obj);

private:
    void clear();
    void copy(Command const& other);
};

std::ostream& operator<<(std::ostream& out, Command const& obj);

#endif //JURASSICPARK_COMMAND_HPP
