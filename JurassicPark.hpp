//
// Created by toi on 26/03/2020.
//

#ifndef JURASSICPARK_JURASSICPARK_HPP
#define JURASSICPARK_JURASSICPARK_HPP

#include "Dinosaur.hpp"
#include "Cage.hpp"
#include "Storehouse.hpp"

class JurassicPark {
    Cage* m_list;
    unsigned m_list_size;// current cages count
    unsigned m_list_limit;// max cages count

    Storehouse m_storehouse;
public:
    JurassicPark(unsigned limit = 4);
    JurassicPark(const JurassicPark& other) = delete;// TODO: temporary solution
    JurassicPark& operator=(const JurassicPark& other) = delete;
    ~JurassicPark();

    void buildCage(char const* climate, char const* size);
    void buildCage(const Cage& cage);
    bool addAnimal(const Dinosaur& dinosaur);
    bool removeAnimal(const char* dinosaur_name);
    bool addFood(const char* food_name, const UnitAmount food_amount);

private:
    bool empty() const;
    bool full() const;
    void resize();
    Cage* findCage(const Dinosaur& dinosaur);
    Cage* findDinosaursCage(const char* dinosaur_name);
};

#endif //JURASSICPARK_JURASSICPARK_HPP
