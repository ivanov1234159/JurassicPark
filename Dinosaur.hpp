//
// Created by toi on 27/03/2020.
//

#ifndef JURASSICPARK_DINOSAUR_HPP
#define JURASSICPARK_DINOSAUR_HPP

#include <fstream>
//for: ifstream, ofstream
#include <iostream>
//for: ostream
#include "DinoBasic.hpp"
#include "String.hpp"

class Dinosaur : public DinoBasic {
    String m_name;
    String m_gender;
public:
    //Dinosaur() = default;
    /*Dino(char const* name, char const* gender, char const* era,
         char const* type, char const* species, char const* food);*/

    bool setName(String const& name);
    bool setGender(String const& gender);

    String const& getName() const;
    String const& getGender() const;

    virtual bool serialize(std::ofstream& ofs) const override final;
    virtual bool unserialize(std::ifstream& ifs) override final;

    friend std::ostream& operator<<(std::ostream& out, Dinosaur const& obj);
private:
    static bool validGender(String const& gender);
};

std::ostream& operator<<(std::ostream& out, Dinosaur const& obj);

#endif //JURASSICPARK_DINOSAUR_HPP
