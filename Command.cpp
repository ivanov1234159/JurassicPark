//
// Created by toi on 08/04/2020.
//

#include "Command.hpp"
#include "MySpace.hpp"

Command::Command(): m_quit_when_done(false) {}

Command::Command(String const& name, String const& params, String const& notes, bool quit)
        : m_name(name), m_params(params), m_notes(notes), m_quit_when_done(quit) {}

bool Command::operator==(String const& cmd){
    return m_name == cmd;
}

bool Command::canQuit() const {
    return m_quit_when_done;
}

bool Command::action(std::ostream& out, RunnerType&, std::istringstream&) const {
    out << "Invalid command! Type 'help' for more information." << std::endl;
    return true;
}

std::ostream& operator<<(std::ostream& out, Command const& obj){
    if(obj.m_name == nullptr){
        return out;
    }
    return out << obj.m_name << ' ' << obj.m_params << std::endl
           << '\t' << obj.m_notes << std::endl;
}