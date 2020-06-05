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
#include "StorageUnit.hpp"
#include "Vector.hpp"

/// @class JurassicPark - main class for the project
class JurassicPark {
    Vector<Cage> m_list;

    Storehouse m_storehouse;

    /// default constructor and constructor with argument limit
    JurassicPark(unsigned limit = 4);

    /// DELETE copy constructor
    JurassicPark(const JurassicPark& other) = delete;

    /// DELETE operator =
    JurassicPark& operator=(const JurassicPark& other) = delete;
public:
    /**
     * used to hold the ONLY instance of this object
     * @param limit - used for the constructor (ONLY at the first call of the function)
     * @return the ONLY instance of this object
     */
    static JurassicPark& self(unsigned limit = 4);

    static const char* FILE_PATH;

    /**
     * open the file at location JurassicPark::FILE_PATH
     * @return false if can't deserialize the object
     */
    bool open();

    /**
     * save the file at location JurassicPark::FILE_PATH
     * @return false if can't serialize the object
     */
    bool save() const;

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

    /**
     * build a cage
     * @param climate
     * @param size
     * @return false if there isn't enough staff
     */
    bool buildCage(String const& climate, String const& size);

    /**
     * add an animal (dinosaur)
     * @param dinosaur
     * @return false if there isn't a suitable cage
     */
    bool addAnimal(const Dinosaur& dinosaur);

    /**
     * remove an animal (dinosaur) by its name
     * @param dinosaur_name
     * @return false if can't find an animal with the given name
     */
    bool removeAnimal(String const& dinosaur_name);

    /**
     * add food in the storehouse;
     * calls Storehouse::add() method
     * @param food_name
     * @param food_amount
     * @return false if can't add the food (see: Storehouse::add() method)
     */
    bool addFood(String const& food_name, const UnitAmount food_amount);

    /**
     * hire new staff;
     * calls Storehouse::add() method
     * @param amount
     * @return false if can't add the food (see: Storehouse::add() method)
     */
    bool addStaff(const UnitAmount amount);

    /**
     * check if exists a dinosaur with the given name
     * @param name
     * @return false if it doesn't exist
     */
    bool hasDinosaur(String const& name) const;

    /**
     * make a food supply
     * @param food
     * @return false if it's NOT a valid food name OR can't add the food (see: Storehouse::add() method)
     */
    bool supply(StorageUnit const& food);

    /// @return false if can't feed all animals in one (any) cage
    bool feedAllAnimals();

    friend std::ostream& operator<<(std::ostream& out, JurassicPark const& obj);
private:
    /**
     * search for a cage which is suitable for the given dinosaur
     * @param dinosaur
     * @return nullptr if NOT found OR a pointer to the first match
     */
    Cage* findCage(const Dinosaur& dinosaur);

    /**
     * search for a cage by the dinosaur in it
     * @param dinosaur_name - used to identify the dinosaur
     * @return nullptr if NOT found OR a pointer to the first match
     */
    Cage const* findDinosaursCage(String const& dinosaur_name) const;
};

std::ostream& operator<<(std::ostream& out, JurassicPark const& obj);

#endif //JURASSICPARK_JURASSICPARK_HPP
