//
// Created by toi on 27/03/2020.
//

#ifndef JURASSICPARK_DINOSAUR_HPP
#define JURASSICPARK_DINOSAUR_HPP

class Dinosaur {
    char* m_name;
    char* m_gender;
    char* m_era;
    char* m_type;
    char* m_species;
    char* m_food;
public:
    static char const* era[];
    static char const* type[];
    static char const* species[];
    static char const* food[];

    Dinosaur();
    /*Dino(char const* name, char const* gender, char const* era,
         char const* type, char const* species, char const* food);*/
    Dinosaur(Dinosaur const& other);
    Dinosaur& operator=(Dinosaur const& other);
    ~Dinosaur();

    bool setName(char const* name);
    bool setGender(char const* gender);
    bool setEra(char const* era);
    bool setType(char const* type);
    bool setSpecies(char const* species);
    bool setFood(char const* food);

    char const* getName() const;
    char const* getGender() const;
    char const* getEra() const;
    char const* getType() const;
    char const* getSpecies() const;
    char const* getFood() const;

private:
    void clear();
    void copy(Dinosaur const& other);
    void copy(char const* name, char const* gender, char const* era,
              char const* type, char const* species, char const* food);

    static bool validGender(char const* gender);
    static bool validEra(char const* era);
    static bool validType(char const* type);
    static bool validSpecies(char const* species);
    static bool validFood(char const* food);
};

#endif //JURASSICPARK_DINOSAUR_HPP
