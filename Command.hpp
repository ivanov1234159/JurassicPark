//
// Created by toi on 08/04/2020.
//

#ifndef JURASSICPARK_COMMAND_HPP
#define JURASSICPARK_COMMAND_HPP

#include <iostream>
//for: ostream, cout, endl
#include <sstream>
//for: istringstream
#include "JurassicPark.hpp"
#include "String.hpp"

typedef JurassicPark RunnerType;

class Command {
    String m_name;
    String m_params;
    String m_notes;
    bool m_quit_when_done;
public:
    Command();
    Command(String const& name, String const& params, String const& notes, bool quit = false);
    virtual ~Command() = default;

    ///@return true if the commands has the same names
    bool operator==(String const& cmd);

    /// @return m_quit_when_done
    bool canQuit() const;

    /**
     * depending from the child class do different things
     * @param out
     * @param runner
     * @param iss
     * @return false if cannot read the params of the command
     */
    virtual bool action(std::ostream& out, RunnerType& runner, std::istringstream& iss) const;

    friend std::ostream& operator<<(std::ostream& out, Command const& obj);
};

std::ostream& operator<<(std::ostream& out, Command const& obj);

#endif //JURASSICPARK_COMMAND_HPP
