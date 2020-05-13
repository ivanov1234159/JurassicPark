//
// Created by toi on 13/05/2020.
//

#ifndef JURASSICPARK_DINOFOODTYPE_HPP
#define JURASSICPARK_DINOFOODTYPE_HPP

#include <fstream>
//for: ofstream, ifstream
#include "String.hpp"

class DinoFoodType {
protected:
    String m_type;
    String m_food;
public:
    static char const* type[];
    static char const* food[];

    //DinoFoodType() = default;

    bool setType(String const& type);
    bool setFood(String const& food);

    String const& getType() const;
    String const& getFood() const;

    virtual bool serialize(std::ofstream& ofs) const = 0;
    virtual bool unserialize(std::ifstream& ifs) = 0;

private:
    static bool validType(String const& _type);
    static bool validFood(String const& _food);
};

#endif //JURASSICPARK_DINOFOODTYPE_HPP
