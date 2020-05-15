//
// Created by toi on 13/05/2020.
//

#ifndef JURASSICPARK_DINOFOODTYPE_HPP
#define JURASSICPARK_DINOFOODTYPE_HPP

#include <fstream>
//for: ofstream, ifstream
#include "String.hpp"

typedef double FoodAmount;// !!! MUST be from the same type as UnitAmount in StorageUnit.hpp

class DinoFoodType {
protected:
    String m_type;
    String m_food;
    FoodAmount m_food_per_day;// food in kg (kilograms) per day
public:
    static char const* type[];
    static char const* food[];

    //DinoFoodType() = default;

    bool setType(String const& type);
    bool setFood(String const& food);
    bool setFoodAmount(FoodAmount const& amount);

    String const& getType() const;
    String const& getFood() const;
    FoodAmount const& getFoodAmount() const;

    virtual bool serialize(std::ofstream& ofs) const = 0;
    virtual bool unserialize(std::ifstream& ifs) = 0;

private:
    static bool validType(String const& _type);

public:
    static bool validFood(String const& _food);
};

#endif //JURASSICPARK_DINOFOODTYPE_HPP
