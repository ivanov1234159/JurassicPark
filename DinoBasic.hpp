//
// Created by toi on 13/05/2020.
//

#ifndef JURASSICPARK_DINOBASIC_HPP
#define JURASSICPARK_DINOBASIC_HPP

#include <fstream>
//for: ofstream, ifstream
#include "DinoFoodType.hpp"
#include "String.hpp"

class DinoBasic : public DinoFoodType {
protected:
    String m_era;
    String m_species;
public:
    static char const* era[];
    static char const* species[];

    //DinoBasic() = default;

    bool setEra(String const& era);
    bool setSpecies(String const& species);

    String const& getEra() const;
    String const& getSpecies() const;

    //virtual bool serialize(std::ofstream& ofs) const = 0;
    //virtual bool unserialize(std::ifstream& ifs) = 0;

private:
    static bool validEra(String const& _era);
    static bool validSpecies(String const& _species);
};

#endif //JURASSICPARK_DINOBASIC_HPP
