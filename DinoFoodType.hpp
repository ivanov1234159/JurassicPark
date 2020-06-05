//
// Created by toi on 13/05/2020.
//

#ifndef JURASSICPARK_DINOFOODTYPE_HPP
#define JURASSICPARK_DINOFOODTYPE_HPP

#include <fstream>
//for: ofstream, ifstream
#include "String.hpp"

typedef double FoodAmount;// !!! MUST be from the same type as UnitAmount in StorageUnit.hpp

/// @class DinoFoodType - abstract class
class DinoFoodType {
protected:
    String m_type;
    String m_food;
    FoodAmount m_food_per_day;// food in kg (kilograms) per day
public:
    /// list of all valid types
    static char const* type[];
    /// list of all valid food names
    static char const* food[];

    //DinoFoodType() = default;

    /**
     * setter for m_type
     * @param type
     * @return false if <type> is NOT valid one
     */
    bool setType(String const& type);

    /**
     * setter for m_food
     * @param food
     * @return false if <food> is NOT valid one
     */
    bool setFood(String const& food);

    /**
     * setter for m_food_per_day
     * @param amount
     * @return true (always)
     */
    bool setFoodAmount(FoodAmount const& amount);

    /**
     * getter for m_type
     * @return m_type
     */
    String const& getType() const;

    /**
     * getter for m_food
     * @return m_food
     */
    String const& getFood() const;

    /**
     * getter for m_food_per_day
     * @return m_food_per_day
     */
    FoodAmount const& getFoodAmount() const;

    /**
     * serialize this object
     * @param ofs
     * @return false on fail
     */
    virtual bool serialize(std::ofstream& ofs) const = 0;

    /**
     * deserialize this object
     * @param ifs
     * @return false on fail
     */
    virtual bool unserialize(std::ifstream& ifs) = 0;

private:
    /**
     * check if <_type> is a valid one
     * @param _type
     * @return true if it is and false if it's NOT
     */
    static bool validType(String const& _type);

public:
    /**
     * check if <_food> is a valid one
     * @param _food
     * @return true if it is and false if it's NOT
     */
    static bool validFood(String const& _food);
};

#endif //JURASSICPARK_DINOFOODTYPE_HPP
