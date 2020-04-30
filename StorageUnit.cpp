//
// Created by toi on 26/03/2020.
//

#include <cstring>
//for: strlen(), strcpy()
#include "StorageUnit.hpp"

const UnitAmount StorageUnit::EPS = 1E-4;

bool StorageUnit::areEqual(const UnitAmount amount1, const UnitAmount amount2){
    return ((amount2 - amount1) >= -EPS) && ((amount1 - amount2) <= EPS);
}

StorageUnit::StorageUnit(const char* name, UnitAmount amount): m_name(nullptr) {
    if(name != nullptr){
        copy(name, std::strlen(name)+1, amount);
    } else {
        copy(nullptr, 0, amount);
    }
}

StorageUnit::StorageUnit(const StorageUnit& other): m_name(nullptr) {
    copy(other);
}

StorageUnit& StorageUnit::operator=(const StorageUnit& other){
    if(this != &other){
        clear();
        copy(other);
    }
    return *this;
}

StorageUnit::~StorageUnit(){
    clear();
}

void StorageUnit::getName(char*& name) const{
    if(name == nullptr && m_name != nullptr){
        name = new char[m_name_size];
        std::strcpy(name, m_name);
    }
}

UnitAmount StorageUnit::getAmount() const {
    return m_amount;
}

bool StorageUnit::add(const UnitAmount amount){
    if(amount < 0){
        return remove(-amount);
    }
    m_amount += amount;
    return true;
}

bool StorageUnit::remove(const UnitAmount amount){
    if(m_amount < amount){
        return false;
    }
    m_amount -= amount;
    return true;
}

void StorageUnit::clear() {
    if(m_name != nullptr){
        delete[] m_name;
        m_name = nullptr;
    }
}

void StorageUnit::copy(const StorageUnit &other) {
    copy(other.m_name, other.m_name_size, other.m_amount);
}

void StorageUnit::copy(const char *name, const unsigned name_size, const UnitAmount amount) {
    m_name_size = name_size;
    m_amount = amount;
    if(m_name != nullptr){
        delete[] m_name;
        m_name = nullptr;
    }
    if(name_size > 0){// same as: name_size != 0
        m_name = new char[name_size];
        if(name != nullptr){
            std::strcpy(m_name, name);
        }
    }
}