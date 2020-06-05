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

/**
 * @class Dinosaur
 * a child of DinoBasic
 */
class Dinosaur : public DinoBasic {
    String m_name;
    String m_gender;
public:
    //Dinosaur() = default;
    /*Dino(char const* name, char const* gender, char const* era,
         char const* type, char const* species, char const* food);*/

    /**
     * setter for m_name
     * @param name
     * @return true (always)
     */
    bool setName(String const& name);

    /**
     * setter for m_gender
     * @param gender - MUST be 'male' or 'female'
     * @return false if <gender> is NOT valid one
     */
    bool setGender(String const& gender);

    /**
     * getter for m_name
     * @return m_name
     */
    String const& getName() const;

    /**
     * getter for m_gender
     * @return m_gender
     */
    String const& getGender() const;

    virtual bool serialize(std::ofstream& ofs) const override final;
    virtual bool unserialize(std::ifstream& ifs) override final;

    friend std::ostream& operator<<(std::ostream& out, Dinosaur const& obj);
private:
    /**
     * check if <gender> is a valid one
     * @param gender
     * @return true if it is and false if it's NOT
     */
    static bool validGender(String const& gender);
};

std::ostream& operator<<(std::ostream& out, Dinosaur const& obj);

#endif //JURASSICPARK_DINOSAUR_HPP
