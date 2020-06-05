//
// Created by toi on 26/03/2020.
//

#include "JurassicPark.hpp"
//#include <ctime>


JurassicPark::JurassicPark(unsigned limit) {
    m_list = Vector<Cage>(limit);
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

JurassicPark& JurassicPark::self(unsigned limit) {
    static JurassicPark park(limit);
    return park;
}

const char* JurassicPark::FILE_PATH = "data.bin";

bool JurassicPark::open() {
    std::ifstream ifs(JurassicPark::FILE_PATH, std::ios::binary);
    if(!ifs){// if (no such file) then { create one }
        std::ofstream ofs(JurassicPark::FILE_PATH, std::ios::binary);
        return true;
    }
    int temp_pos = ifs.tellg();
    if(ifs.seekg(0, std::ios::end).tellg() == 0){
        return true;// empty file
    }
    ifs.seekg(temp_pos);
    return unserialize(ifs);
}

bool JurassicPark::save() const {
    std::ofstream ofs(JurassicPark::FILE_PATH, std::ios::binary);
    return serialize(ofs);
}

bool JurassicPark::serialize(std::ofstream &ofs) const {
    unsigned size = m_list.size();
    ofs.write((char const*) &size, sizeof(size));
    for(unsigned i = 0; i < size; i++){
        if(!m_list[i].serialize(ofs)){
            break;
        }
    }
    return !(!ofs);
}

bool JurassicPark::unserialize(std::ifstream &ifs) {
    unsigned size;
    ifs.read((char*) &size, sizeof(size));
    m_list = Vector<Cage>(size);
    for(unsigned i = 0; i < size; i++){
        m_list.push(Cage());
        if(!m_list[i].unserialize(ifs)){
            break;
        }
    }
    return !(!ifs);
}

void JurassicPark::buildCage(String const& climate, String const& size){
    m_list.push(Cage(climate, size));
}

bool JurassicPark::addAnimal(const Dinosaur& dinosaur){
    Cage* search = findCage(dinosaur);
    if(search == nullptr){
        return false;
    }
    return search->add(dinosaur);
}

bool JurassicPark::removeAnimal(String const& dinosaur_name){
    Cage const* search = findDinosaursCage(dinosaur_name);
    if(search == nullptr){
        return false;
    }
    return const_cast<Cage*>(search)->remove(dinosaur_name);
}

bool JurassicPark::addFood(String const& food_name, const UnitAmount food_amount){
    return m_storehouse.add(food_name, food_amount);
}

bool JurassicPark::addStaff(const UnitAmount amount){
    return m_storehouse.add("Staff", amount, true);
}

bool JurassicPark::hasDinosaur(String const &name) const {
    return findDinosaursCage(name) != nullptr;
}

bool JurassicPark::supply(StorageUnit const &food) {
    if(!Dinosaur::validFood(food.getName())){
        return false;
    }
    return m_storehouse.add(food);
}

bool JurassicPark::feedAllAnimals() {
    for(unsigned i = 0; i < m_list.size(); i++){
        if(!m_list[i].feedAnimals(m_storehouse)){
            return false;
        }
    }
    return true;
}

Cage* JurassicPark::findCage(const Dinosaur& dinosaur){
    for(unsigned i = 0; i < m_list.size(); i++){
        if(m_list[i].canHandle(dinosaur)){
            return &m_list[i];
        }
    }
    return nullptr;
}

Cage const* JurassicPark::findDinosaursCage(String const& dinosaur_name) const{
    for(unsigned i = 0; i < m_list.size(); i++){
        int search = m_list[i].findIndex(dinosaur_name);
        if(search >= 0){
            return &m_list[i];
        }
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& out, JurassicPark const& obj){
    if(!obj.m_list.empty()){
        for(unsigned i = 0; i < obj.m_list.size(); i++){
            out << "Cage No." << i+1 << std::endl;
            out << obj.m_list[i];
            out << "-----------------------------------------------------------------------------------------------" << std::endl;
        }
    }else{
        out << "No cages." << std::endl;
    }
    out << std::endl;
    out << "===============================================================================================" << std::endl;
    out << std::endl;
    out << obj.m_storehouse;
    return out;
}