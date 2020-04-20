//
// Created by toi on 26/03/2020.
//

#include <cstring>
//for: strcmp()
#include "Storehouse.hpp"

Storehouse::Storehouse(unsigned limit): m_list(nullptr) {
    copy(nullptr, 0, limit);
}

Storehouse::Storehouse(const Storehouse& other): m_list(nullptr) {
    copy(other);
}

Storehouse& Storehouse::operator=(const Storehouse& other){
    if(this != &other){
        clear();
        copy(other);
    }
    return *this;
}

Storehouse::~Storehouse(){
    clear();
}

bool Storehouse::empty() const {
    return m_size == 0;
}

bool Storehouse::full() const {
    return m_size == m_limit;
}

bool Storehouse::has(const char* unit_name) const {
    return find(unit_name) != nullptr;
}

bool Storehouse::has(const StorageUnit& unit) const {
    char* unit_name = nullptr;
    unit.getName(unit_name);
    if(has(unit_name, unit.getAmount())){
        delete[] unit_name;
        return true;
    }
    delete[] unit_name;
    return false;
}

bool Storehouse::has(const char* unit_name, const UnitAmount unit_amount) const {
    StorageUnit* search = find(unit_name);
    if(search == nullptr){
        return false;
    }
    if(search->getAmount() > unit_amount){
        return false;
    }
    return StorageUnit::areEqual(search->getAmount(), unit_amount);
}

bool Storehouse::add(const StorageUnit& unit){
    char* unit_name = nullptr;
    unit.getName(unit_name);
    if(add(unit_name, unit.getAmount())){
        delete[] unit_name;
        return true;
    }
    delete[] unit_name;
    return false;
}

bool Storehouse::add(const char* unit_name, const UnitAmount unit_amount){
    if(unit_amount < 0){
        return remove(unit_name, -unit_amount);
    }
    StorageUnit* search = find(unit_name);
    if(search == nullptr){
        if(full()){
            resize();
        }
        m_list[m_size] = StorageUnit(unit_name, unit_amount);
        m_size++;
        return true;
    }
    return search->add(unit_amount);
}

bool Storehouse::remove(const StorageUnit& unit){
    char* unit_name = nullptr;
    unit.getName(unit_name);
    if(remove(unit_name, unit.getAmount())){
        delete[] unit_name;
        return true;
    }
    delete[] unit_name;
    return false;
}

bool Storehouse::remove(const char* unit_name, const UnitAmount unit_amount){
    StorageUnit* search = find(unit_name);
    if(search == nullptr){
        return false;
    }
    return search->remove(unit_amount);
}

StorageUnit* Storehouse::find(const char* unit_name) const {
    for(unsigned i = 0; i < m_size; i++){
        char* list_unit_name = nullptr;
        m_list[i].getName(list_unit_name);
        if(std::strcmp(list_unit_name, unit_name) == 0){
            delete[] list_unit_name;
            return &m_list[i];
        }
        delete[] list_unit_name;
    }
    return nullptr;
}

void Storehouse::clear() {
    if(m_list != nullptr){
        delete[] m_list;
        m_list = nullptr;
    }
}

void Storehouse::copy(const Storehouse& other) {
    copy(other.m_list, other.m_size, other.m_limit);
}

void Storehouse::copy(const StorageUnit* list, const unsigned size, const unsigned limit) {
    m_size = size;
    m_limit = limit;
    if(m_list != nullptr){
        delete[] m_list;
    }
    m_list = new StorageUnit[limit];
    if(list != nullptr){
        for (unsigned i = 0; i < size; i++){
            m_list[i] = list[i];
        }
    }
}

void Storehouse::resize(){
    m_limit *= 2;
    StorageUnit* temp = m_list;
    m_list = new StorageUnit[m_limit];
    for(unsigned i = 0; i < m_size; i++){
        m_list[i] = temp[i];
    }
    delete[] temp;
}