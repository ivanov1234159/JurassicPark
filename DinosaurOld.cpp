//
// Created by toi on 25/03/2020.
//

#include <cstring>
//for: strlen(), strcpy()
#include "DinosaurOld.hpp"

DinosaurOld::DinosaurOld(const char *name, const DinosaurGender gender, const DinosaurEra era,
        const DinosaurType type, const DinosaurSpecies species, const DinosaurFood food): m_name(nullptr) {
    copy(name, gender, era, type, species, food);
}

DinosaurOld::DinosaurOld(const DinosaurOld& other): m_name(nullptr) {
    copy(other);
}

DinosaurOld& DinosaurOld::operator=(const DinosaurOld& other){
    if(this != &other){
        clear();
        copy(other);
    }
    return *this;
}

DinosaurOld::~DinosaurOld(){
    clear();
}

void DinosaurOld::setGender(const DinosaurGender gender){
    m_gender = (gender == DinosaurGender::FEMALE) ? DinosaurGender::FEMALE : DinosaurGender::MALE;
}

void DinosaurOld::setEra(const DinosaurEra era){
    m_era = (era < DinosaurEra::_COUNT) ?  era : DinosaurEra::UNKNOWN;
}

void DinosaurOld::setType(const DinosaurType type){
    m_type = (type < DinosaurType::_COUNT) ?  type : DinosaurType::UNKNOWN;
}

void DinosaurOld::setSpecies(const DinosaurSpecies species){
    m_species = (species < DinosaurSpecies::_COUNT) ?  species : DinosaurSpecies::UNKNOWN;
}

void DinosaurOld::setFood(const DinosaurFood food){
    m_food = (food < DinosaurFood::_COUNT) ?  food : DinosaurFood::UNKNOWN;
}


void DinosaurOld::getName(char*& name) const {
    if(name == nullptr){
        name = new char[std::strlen(m_name)+1];
        std::strcpy(name, m_name);
    }
}

DinosaurEra DinosaurOld::getEra() const {
    return m_era;
}

DinosaurType DinosaurOld::getType() const {
    return m_type;
}

void DinosaurOld::clear() {
    if(m_name != nullptr){
        delete[] m_name;
    }
}

void DinosaurOld::copy(const Dinosaur &other) {
    copy(other.m_name, other.m_gender, other.m_era, other.m_type, other.m_species, other.m_food);
}

void DinosaurOld::copy(const char *name, const DinosaurGender gender, const DinosaurEra era, const DinosaurType type,
                    const DinosaurSpecies species, const DinosaurFood food) {
    if(m_name != nullptr){
        delete[] m_name;
    }
    m_name = new char[std::strlen(name) + 1];
    std::strcpy(m_name, name);
    setGender(gender);
    setEra(era);
    setType(type);
    setSpecies(species);
    setFood(food);
}


//====================================== [ Cage.cpp ] ======================================
//
// Created by toi on 25/03/2020.
//

//#include <cstring>
//for: strcmp()
//#include "Cage.hpp"
/*
unsigned Cage::getCageSize(const CageSize size) {
    switch (size) {
        case CageSize::SMALL:
            return 1;
        case CageSize::MEDIUM:
            return 3;
        case CageSize::LARGE:
            return 10;
        default:
            break;
    }
    return 0;
}

Cage::Cage(const CageClimate climate, const CageSize size): m_list(nullptr) {
    copy(climate, size, DinosaurEra::UNKNOWN, nullptr, 0);
}

Cage::Cage(const Cage& other): m_list(nullptr) {
    copy(other);
}

Cage& Cage::operator=(const Cage& other){
    if(this != &other){
        clear();
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
    return m_list_count == Cage::getCageSize(m_size);
}

unsigned Cage::free() const {
    return Cage::getCageSize(m_size) - m_list_count;
}


bool Cage::canHandle(const Dinosaur& dinosaur){
    if(full() || dinosaur.getEra() != m_era){
        return false;
    }
    if(empty()){
        return true;
    }
    return m_list[0].getType() == dinosaur.getType();
}

bool Cage::add(const Dinosaur& dinosaur){
    if(!canHandle(dinosaur)){
        return false;
    }
    if(empty()){
        m_era = dinosaur.getEra();
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
        char* current_name = nullptr;
        m_list[i].getName(current_name);
        if(std::strcmp(current_name, dinosaur_name) == 0){
            delete[] current_name;
            return &m_list[i];
        }
        delete[] current_name;
    }
    return nullptr;
}

void Cage::setEra(const DinosaurEra era){
    m_era = (era < DinosaurEra::_COUNT) ?  era : DinosaurEra::UNKNOWN;
}

void Cage::clear(){
    if(m_list != nullptr){
        delete[] m_list;
    }
}

void Cage::copy(const Cage &other){
    copy(other.m_climate, other.m_size, other.m_era, other.m_list, other.m_list_count);
}

void Cage::copy(const CageClimate climate, const CageSize size, const DinosaurEra era,
                const Dinosaur* list, const unsigned list_count){
    m_climate = climate;
    m_size = size;
    setEra(era);
    if(m_list != nullptr){
        delete[] m_list;
    }
    m_list = new Dinosaur[Cage::getCageSize(size)];
    m_list_count = list_count;
    if(list != nullptr){
        for(unsigned i = 0; i < list_count; i++){
            m_list[i] = list[i];
        }
    }
}
*/