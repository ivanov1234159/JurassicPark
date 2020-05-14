//
// Created by toi on 25/03/2020.
//

#ifndef JURASSICPARK_CAGE_HPP
#define JURASSICPARK_CAGE_HPP

#include <fstream>
//for: ifstream, ofstream
#include <iostream>
//for: ostream, endl
#include "Dinosaur.hpp"
#include "String.hpp"
#include "Vector.hpp"

class Cage {
    String m_climate;
    String m_era;// if any dinosaur; all dinosaurs MUST be (and are) from one era
    Vector<Dinosaur> m_list;
public:
    static unsigned getCageSize(String const& size);
    static const unsigned DEFAULT_CAGE_SIZE = 0;// MUST be different from the other cage sizes

    Cage(String const& climate = nullptr, String const& size = nullptr);

    bool canHandle(const Dinosaur& dinosaur);
    bool add(const Dinosaur& dinosaur);
    bool remove(const char* dinosaur_name);
    int findIndex(const char* dinosaur_name) const;
    bool serialize(std::ofstream& ofs) const;
    bool unserialize(std::ifstream& ifs);

    friend std::ostream& operator<<(std::ostream& out, Cage const& obj);
};

std::ostream& operator<<(std::ostream& out, Cage const& obj);

#endif //JURASSICPARK_CAGE_HPP
