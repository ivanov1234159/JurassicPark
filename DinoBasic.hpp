//
// Created by toi on 13/05/2020.
//

#ifndef JURASSICPARK_DINOBASIC_HPP
#define JURASSICPARK_DINOBASIC_HPP

#include <fstream>
//for: ofstream, ifstream
#include "DinoFoodType.hpp"
#include "String.hpp"

/**
 * @class DinoBasic - abstract class
 * a child of DinoFoodType
 */
class DinoBasic : public DinoFoodType {
protected:
    String m_era;
    String m_species;
public:
    /// list of all valid era
    static char const* era[];

    /// list of all valid species
    static char const* species[];

    //DinoBasic() = default;

    /**
     * setter for m_era
     * @param era
     * @return false if <era> is NOT valid one
     */
    bool setEra(String const& era);

    /**
     * setter for m_species
     * @param species
     * @return false if <species> is NOT valid one
     */
    bool setSpecies(String const& species);

    /**
     * getter for m_era
     * @return m_era
     */
    String const& getEra() const;

    /**
     * getter for m_species
     * @return m_species
     */
    String const& getSpecies() const;

    //virtual bool serialize(std::ofstream& ofs) const = 0;
    //virtual bool unserialize(std::ifstream& ifs) = 0;

private:
    /**
     * check if <_era> is a valid one
     * @param _era
     * @return true if it is and false if it's NOT
     */
    static bool validEra(String const& _era);

    /**
     * check if <_species> is a valid one
     * @param _species
     * @return true if it is and false if it's NOT
     */
    static bool validSpecies(String const& _species);
};

#endif //JURASSICPARK_DINOBASIC_HPP
