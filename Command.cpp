//
// Created by toi on 08/04/2020.
//

#include "Command.hpp"
#include "MySpace.hpp"
#include <cstring>
//for: strcmp()

Command::Command(): m_name(nullptr), m_params(nullptr), m_notes(nullptr), m_quit_when_done(false) {}

Command::Command(char const *name, char const *params, char const *notes, bool quit)
        : m_name(nullptr), m_params(nullptr), m_notes(nullptr), m_quit_when_done(quit) {
    MySpace::mem_copy(m_name, name);
    MySpace::mem_copy(m_params, params);
    MySpace::mem_copy(m_notes, notes);
}

Command::Command(Command const &other) {
    copy(other);
}

Command& Command::operator=(Command const &other) {
    if(this != &other){
        clear();
        copy(other);
    }
    return *this;
}

Command::~Command() {
    clear();
}

bool Command::operator==(char const* cmd){
    return std::strcmp(m_name, cmd) == 0;
}

bool Command::canQuit() const {
    return m_quit_when_done;
}

bool Command::action(RunnerType&, std::istringstream&) const {
    std::cout << "Invalid command! Type 'help' for more information." << std::endl;
    return true;
}

void Command::clear() {
    if(m_name != nullptr){
        delete[] m_name;
        m_name = nullptr;
    }
    if(m_params != nullptr){
        delete[] m_params;
        m_params = nullptr;
    }
    if(m_notes != nullptr){
        delete[] m_notes;
        m_notes = nullptr;
    }
}

void Command::copy(Command const &other) {
    MySpace::mem_copy(m_name, other.m_name);
    MySpace::mem_copy(m_params, other.m_params);
    MySpace::mem_copy(m_notes, other.m_notes);
}

std::ostream& operator<<(std::ostream& out, Command const& obj){
    if(obj.m_name == nullptr){
        return out;
    }
    return out << obj.m_name << ' ' << obj.m_params << std::endl
           << '\t' << obj.m_notes << std::endl;
}