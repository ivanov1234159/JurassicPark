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

typedef JurassicPark RunnerType;

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

    ///@return true if the commands has the same names
    bool operator==(char const* cmd);

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

private:
    /// free the memory of m_name, m_params and m_notes
    void clear();

    /**
     * copy <other> into this
     * @param other
     */
    void copy(Command const& other);
};

std::ostream& operator<<(std::ostream& out, Command const& obj);

#endif //JURASSICPARK_COMMAND_HPP
