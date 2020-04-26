//
// Created by toi on 25/03/2020.
//

#include <cstring>
//for: strcmp()
#include "Cage.hpp"
#include "MySpace.hpp"

unsigned Cage::getCageSize(char const* size) {
    if(size != nullptr){
        if(std::strcmp(size, "small") == 0){
            return 1;
        }else if(std::strcmp(size, "medium") == 0){
            return 3;
        }else if(std::strcmp(size, "large") == 0){
            return 10;
        }
    }
    return Cage::DEFAULT_CAGE_SIZE;
}

Cage::Cage(char const* climate, char const* size): m_climate(nullptr), m_era(nullptr), m_list(nullptr) {
    copy(climate, Cage::getCageSize(size), nullptr, nullptr, 0);
}

Cage::Cage(const Cage& other): m_climate(nullptr), m_era(nullptr), m_list(nullptr) {
    copy(other);
}

Cage& Cage::operator=(const Cage& other){
    if(this != &other){
        //clear();
        copy(other);
    }
    return *this;
}

Cage::~Cage(){
    clear();
}

bool Cage::empty() const {
    return m_list_count == 0;
}

bool Cage::full() const {
    return m_list_count == m_size;
}

unsigned Cage::free() const {
    return m_size - m_list_count;
}


bool Cage::canHandle(const Dinosaur& dinosaur){
    if(full() || (m_era != nullptr && std::strcmp(m_era, dinosaur.getEra()) != 0)){
        return false;
    }
    if(empty()){
        return true;
    }
    return std::strcmp(m_list[0].getType(), dinosaur.getType()) != 0;
}

bool Cage::add(const Dinosaur& dinosaur){
    if(!canHandle(dinosaur)){
        return false;
    }
    if(empty()){
        MySpace::mem_copy(m_era, dinosaur.getEra());
    }
    m_list[m_list_count] = dinosaur;
    m_list_count++;
    return true;
}

bool Cage::remove(const char* dinosaur_name){
    Dinosaur* search = find(dinosaur_name);
    if(search == nullptr){
        return false;
    }
    Dinosaur* last = &m_list[m_list_count-1];
    while (search < last){
        *search = *(search + 1);
        search++;
    }
    return true;
}

Dinosaur* Cage::find(const char* dinosaur_name) const {
    for(unsigned i = 0; i < m_list_count; i++){
        if(std::strcmp(m_list[i].getName(), dinosaur_name) == 0){
            return &m_list[i];
        }
    }
    return nullptr;
}

bool Cage::serialize(std::ofstream &ofs) const {
    if(!MySpace::serialize(ofs, m_climate)){
        return false;
    }
    if(!MySpace::serialize(ofs, m_era)){
        return false;
    }
    ofs.write((char const*) &m_size, sizeof(m_size));
    ofs.write((char const*) &m_list_count, sizeof(m_list_count));
    for(unsigned i = 0; i < m_list_count; i++){
        if(!m_list[i].serialize(ofs)){
            break;
        }
    }
    return !(!ofs);
}

bool Cage::unserialize(std::ifstream &ifs) {
    if(!MySpace::unserialize(ifs, m_climate)){
        return false;
    }
    if(!MySpace::unserialize(ifs, m_era)){
        return false;
    }
    ifs.read((char*) &m_size, sizeof(m_size));
    ifs.read((char*) &m_list_count, sizeof(m_list_count));
    if(m_list != nullptr){
        delete[] m_list;// I'm sure that this won't be needed; (never used)
    }
    m_list = new Dinosaur[m_size];
    for(unsigned i = 0; i < m_list_count; i++){
        if(!m_list[i].unserialize(ifs)){
            break;
        }
    }
    return !(!ifs);
}

void Cage::clear(){
    if(m_climate != nullptr){
        delete[] m_climate;
        m_climate = nullptr;
    }
    if(m_era != nullptr){
        delete[] m_era;
        m_era = nullptr;
    }
    if(m_list != nullptr){
        delete[] m_list;
        m_list = nullptr;
    }
}

void Cage::copy(const Cage &other){
    copy(other.m_climate, other.m_size, other.m_era, other.m_list, other.m_list_count);
}

void Cage::copy(char const* climate, const unsigned size, char const* era,
                const Dinosaur* list, const unsigned list_count){
    //clear();
    m_size = size;
    MySpace::mem_copy(m_climate, climate);
    MySpace::mem_copy(m_era, era);
    if(m_list != nullptr){
        delete[] m_list;
        m_list = nullptr;
    }
    if(size == Cage::DEFAULT_CAGE_SIZE){
        // can be from the default constructor (the default value of func getCageSize() is the same)
        return;// it's safe
    }
    m_list = new Dinosaur[size];
    m_list_count = list_count;
    if(list != nullptr){
        for(unsigned i = 0; i < list_count; i++){
            m_list[i] = list[i];
        }
    }
}
