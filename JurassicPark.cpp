//
// Created by toi on 26/03/2020.
//

#include "JurassicPark.hpp"
//#include <ctime>


JurassicPark::JurassicPark(unsigned limit): m_list_limit(limit), m_list_size(0) {
    m_list = new Cage[limit];
    /*unsigned max = limit;
    srand(time(0));
    if(limit > 0){
        max = (rand() % limit) + 1;
        max = (max > limit) ? limit : max;
    }
    for(unsigned i = 0; i < max; i++){
        m_list[i] = Cage("TODO", "large");
    }*/
    m_storehouse = Storehouse();
}

JurassicPark::~JurassicPark(){
    if(m_list != nullptr){
        delete[] m_list;
    }
}

JurassicPark& JurassicPark::self(unsigned limit) {
    static JurassicPark park(limit);
    return park;
}

const char* JurassicPark::FILE_PATH = "data.bin";

bool JurassicPark::save() const {
    std::ofstream ofs(JurassicPark::FILE_PATH, std::ios::binary);
    return serialize(ofs);
}

bool JurassicPark::serialize(std::ofstream &ofs) const {
    ofs.write((char const*) &m_list_size, sizeof(m_list_size));
    for(unsigned i = 0; i < m_list_size; i++){
        if(!m_list[i].serialize(ofs)){
            break;
        }
    }
    return ofs;
}

void JurassicPark::buildCage(char const* climate, char const* size){
    buildCage(Cage(climate, size));
}

void JurassicPark::buildCage(const Cage& cage){
    if(full()){
        resize();
    }
    m_list[m_list_size] = cage;
    m_list_size++;
}

bool JurassicPark::addAnimal(const Dinosaur& dinosaur){
    Cage* search = findCage(dinosaur);
    if(search == nullptr){
        return false;
    }
    return search->add(dinosaur);
}

bool JurassicPark::removeAnimal(const char* dinosaur_name){
    Cage* search = findDinosaursCage(dinosaur_name);
    if(search == nullptr){
        return false;
    }
    return search->remove(dinosaur_name);
}

bool JurassicPark::addFood(const char* food_name, const UnitAmount food_amount){
    return m_storehouse.add(food_name, food_amount);
}

bool JurassicPark::empty() const {
    return m_list_size == 0;
}

bool JurassicPark::full() const {
    return m_list_size == m_list_limit;
}

void JurassicPark::resize(){
    m_list_limit *= 2;
    Cage* temp = m_list;
    m_list = new Cage[m_list_limit];
    for(unsigned i = 0; i < m_list_size; i++){
        m_list[i] = temp[i];
    }
    delete[] temp;
}

Cage* JurassicPark::findCage(const Dinosaur& dinosaur){
    for(unsigned i = 0; i < m_list_size; i++){
        if(m_list[i].canHandle(dinosaur)){
            return &m_list[i];
        }
    }
    return nullptr;
}

Cage* JurassicPark::findDinosaursCage(const char* dinosaur_name){
    for(unsigned i = 0; i < m_list_size; i++){
        Dinosaur* search = m_list[i].find(dinosaur_name);
        if(search != nullptr){
            return &m_list[i];
        }
    }
    return nullptr;
}