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
#include "Storehouse.hpp"

/// @class Cage
class Cage {
    String m_climate;
    String m_era;// if any dinosaur; all dinosaurs MUST be (and are) from one era
    Vector<Dinosaur> m_list;
public:
    /**
     * get the cage size from the size name
     * @param size
     * @return number - the cage size
     */
    static unsigned getCageSize(String const& size);

    /// default cage size
    /// MUST be different from the other cage sizes
    static const unsigned DEFAULT_CAGE_SIZE = 0;

    /// default constructor and constructor with arguments climate (and size)
    Cage(String const& climate = nullptr, String const& size = nullptr);

    /**
     * check if this cage can handle the dinosaur
     * @param dinosaur
     * @return false if it can't handle the dinosaur
     */
    bool canHandle(const Dinosaur& dinosaur);

    /**
     * add the dinosaur
     * @param dinosaur
     * @return false if it can't handle the dinosaur
     */
    bool add(const Dinosaur& dinosaur);

    /**
     * remove a dinosaur by its name
     * @param dinosaur_name
     * @return false if there isn't a dinosaur with the given name
     */
    bool remove(String const& dinosaur_name);

    /**
     * find position of a dinosaur by its name
     * @param dinosaur_name
     * @return negative number if its NOT found
     */
    int findIndex(String const& dinosaur_name) const;

    /**
     * feed all animals in the cage
     * @param store
     * @return false if can't feed all (reason: not enough food)
     */
    bool feedAnimals(Storehouse& store) const;

    /**
     * serialize this object
     * @param ofs
     * @return false on fail
     */
    bool serialize(std::ofstream& ofs) const;

    /**
     * deserialize this object
     * @param ifs
     * @return false on fail
     */
    bool unserialize(std::ifstream& ifs);

    friend std::ostream& operator<<(std::ostream& out, Cage const& obj);
};

std::ostream& operator<<(std::ostream& out, Cage const& obj);

#endif //JURASSICPARK_CAGE_HPP
