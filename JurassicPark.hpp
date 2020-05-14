//
// Created by toi on 26/03/2020.
//

#ifndef JURASSICPARK_JURASSICPARK_HPP
#define JURASSICPARK_JURASSICPARK_HPP

#include <fstream>
//for: ifstream, ofstream, ios::binary, ios::end
#include <iostream>
//for: ostream, endl
#include "Dinosaur.hpp"
#include "Cage.hpp"
#include "Storehouse.hpp"
#include "Vector.hpp"

class JurassicPark {
    Vector<Cage> m_list;

    Storehouse m_storehouse;
    JurassicPark(unsigned limit = 4);
    JurassicPark(const JurassicPark& other) = delete;
    JurassicPark& operator=(const JurassicPark& other) = delete;
public:
    static JurassicPark& self(unsigned limit = 4);
    static const char* FILE_PATH;

    bool open();
    bool save() const;
    bool serialize(std::ofstream& ofs) const;
    bool unserialize(std::ifstream& ifs);
    void buildCage(char const* climate, char const* size);
    bool addAnimal(const Dinosaur& dinosaur);
    bool removeAnimal(const char* dinosaur_name);
    bool addFood(const char* food_name, const UnitAmount food_amount);

    friend std::ostream& operator<<(std::ostream& out, JurassicPark const& obj);
private:
    Cage* findCage(const Dinosaur& dinosaur);
    Cage* findDinosaursCage(const char* dinosaur_name);
};

std::ostream& operator<<(std::ostream& out, JurassicPark const& obj);

#endif //JURASSICPARK_JURASSICPARK_HPP
