//
// Created by toi on 25/03/2020.
//

#include "Cage.hpp"
#include "MySpace.hpp"
#include "Storehouse.hpp"

unsigned Cage::getCageSize(String const& size) {
    if(size == "small"){
        return 1;
    }else if(size == "medium"){
        return 3;
    }else if(size == "large"){
        return 10;
    }
    return Cage::DEFAULT_CAGE_SIZE;
}

Cage::Cage(String const& climate, String const& size): m_climate(climate) {
    unsigned capacity = Cage::getCageSize(size);
    if(capacity != Cage::DEFAULT_CAGE_SIZE){
        m_list = Vector<Dinosaur>(capacity, false);
    }
}

bool Cage::canHandle(const Dinosaur& dinosaur){
    if(m_list.empty()){
        return true;
    }
    if(m_list.full() || dinosaur.getEra() != m_era){
        return false;
    }
    return m_list[0].getType() == dinosaur.getType();
}

bool Cage::add(const Dinosaur& dinosaur){
    if(!canHandle(dinosaur)){
        return false;
    }
    if(m_list.empty()){
        m_era = dinosaur.getEra();
    }
    return m_list.push(dinosaur);
}

bool Cage::remove(String const& dinosaur_name){
    int search = findIndex(dinosaur_name);
    if(search < 0){
        return false;
    }
    m_list.remove(search);
    return true;
}

int Cage::findIndex(String const& dinosaur_name) const {
    for(unsigned i = 0; i < m_list.size(); i++){
        if(m_list[i].getName() == dinosaur_name){
            return i;
        }
    }
    return -1;
}

bool Cage::feedAnimals(Storehouse& store) const {
    bool all = true;
    for(unsigned i = 0; i < m_list.size(); i++){
        if(!store.has(m_list[i].getFood(), m_list[i].getFoodAmount())){
            all = false;
            continue;
        }
        store.remove(m_list[i].getFood(), m_list[i].getFoodAmount());
    }
    return all;
}

bool Cage::serialize(std::ofstream &ofs) const {
    if(!m_climate.serialize(ofs)){
        return false;
    }
    if(!m_era.serialize(ofs)){
        return false;
    }
    unsigned size = m_list.size();
    ofs.write((char const*) &size, sizeof(size));
    size = m_list.capacity();
    ofs.write((char const*) &size, sizeof(size));
    for(unsigned i = 0; i < m_list.size(); i++){
        if(!m_list[i].serialize(ofs)){
            break;
        }
    }
    return !(!ofs);
}

bool Cage::unserialize(std::ifstream &ifs) {
    if(!m_climate.unserialize(ifs)){
        return false;
    }
    if(!m_era.unserialize(ifs)){
        return false;
    }
    unsigned size, capacity;
    ifs.read((char*) &size, sizeof(size));
    ifs.read((char*) &capacity, sizeof(capacity));
    m_list = Vector<Dinosaur>(capacity, false);
    for(unsigned i = 0; i < size; i++){
        m_list.push(Dinosaur());
        if(!m_list[i].unserialize(ifs)){
            break;
        }
    }
    return !(!ifs);
}

std::ostream& operator<<(std::ostream& out, Cage const& obj){
    out << "Climate: " << (!obj.m_climate ? "no info" : obj.m_climate) << std::endl;
    out << "Era: " << (!obj.m_era ? "unknown" : obj.m_era) << std::endl;
    out << "Has: " << obj.m_list.size() << "/" << obj.m_list.capacity() << std::endl;
    for(unsigned i = 0; i < obj.m_list.size(); i++){
        out << obj.m_list[i] << std::endl;
    }
    return out;
}