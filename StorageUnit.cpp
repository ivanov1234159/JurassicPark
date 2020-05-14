//
// Created by toi on 26/03/2020.
//

#include "StorageUnit.hpp"

const UnitAmount StorageUnit::EPS = 1E-4;

bool StorageUnit::areEqual(const UnitAmount amount1, const UnitAmount amount2){
    return std::abs(amount1 - amount2) <= EPS;
}

StorageUnit::StorageUnit(String const& name, UnitAmount amount): m_name(name), m_amount(amount) {}

String const& StorageUnit::getName() const {
    return m_name;
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