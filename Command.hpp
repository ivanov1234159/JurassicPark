//
// Created by toi on 08/04/2020.
//

#ifndef JURASSICPARK_COMMAND_HPP
#define JURASSICPARK_COMMAND_HPP

#include <iostream>
//for: ostream, endl
#include <sstream>
//for: istringstream
#include "JurassicPark.hpp"

typedef JurassicPark RunnerType;

typedef bool (*FuncCMD)(RunnerType&, std::istringstream&);

class Command {
    char* m_name;
    char* m_params;
    char* m_notes;
    FuncCMD m_func;
public:
    Command();
    Command(char const* name, char const* params, char const* notes, FuncCMD func);
    Command(Command const& other);
    Command& operator=(Command const& other);
    ~Command();

    bool operator==(char const* cmd);

    bool call(RunnerType& runner, std::istringstream& iss) const;

    friend std::ostream& operator<<(std::ostream& out, Command const& obj);

private:
    void clear();
    void copy(Command const& other);
};

std::ostream& operator<<(std::ostream& out, Command const& obj);

#endif //JURASSICPARK_COMMAND_HPP
