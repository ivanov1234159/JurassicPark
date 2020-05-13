//
// Created by toi on 27/03/2020.
//

#include <cstring>
//for: strcmp()
#include "Dinosaur.hpp"
#include "MySpace.hpp"

/*Dinosaur::Dinosaur(char const *name, char const *gender, char const *era,
           char const *type, char const *species, char const *food)
        : m_name(nullptr), m_gender(nullptr), m_era(nullptr)
        , m_type(nullptr), m_species(nullptr), m_food(nullptr) {
    copy(name, gender, era, type, species, food);
}*/

bool Dinosaur::setName(String const& name) {
    m_name = name;
    return true;
}

bool Dinosaur::setGender(String const& gender) {
    if(!Dinosaur::validGender(gender)){
        return false;
    }
    m_gender = gender;
    return true;
}

String const& Dinosaur::getName() const { return m_name; }
String const& Dinosaur::getGender() const { return m_gender; }

bool Dinosaur::serialize(std::ofstream &ofs) const {
    return m_name.serialize(ofs) && m_gender.serialize(ofs) && m_era.serialize(ofs)
        && m_type.serialize(ofs) && m_species.serialize(ofs) && m_food.serialize(ofs);
}

bool Dinosaur::unserialize(std::ifstream &ifs) {
    return m_name.unserialize(ifs) && m_gender.unserialize(ifs) && m_era.unserialize(ifs)
        && m_type.unserialize(ifs) && m_species.unserialize(ifs) && m_food.unserialize(ifs);
}

bool Dinosaur::validGender(String const& gender) {
    return gender == "male" || gender == "female";
}

std::ostream& operator<<(std::ostream& out, Dinosaur const& obj){
    return out << "Dino named " << obj.getName()
                     << " is " << obj.getGender()
                     << ", from " << obj.getEra()
                     << " era, " << obj.getSpecies()
                     << ", eats " << obj.getFood()
                     << " (" << obj.getType() << ")";
}