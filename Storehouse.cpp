//
// Created by toi on 26/03/2020.
//

#include "Storehouse.hpp"

Storehouse::Storehouse(unsigned limit): m_list(Vector<StorageUnit>(limit)) {}

bool Storehouse::has(String const& unit_name) const {
    return find(unit_name) != nullptr;
}

bool Storehouse::has(const StorageUnit& unit) const {
    if(has(unit.getName(), unit.getAmount())){
        return true;
    }
    return false;
}

bool Storehouse::has(String const& unit_name, const UnitAmount unit_amount) const {
    StorageUnit const* search = find(unit_name);
    if(search == nullptr){
        return false;
    }
    if(search->getAmount() < unit_amount){
        return false;
    }
    return StorageUnit::areEqual(search->getAmount(), unit_amount);
}

bool Storehouse::add(const StorageUnit& unit){
    return add(unit.getName(), unit.getAmount());
}

bool Storehouse::add(String const& unit_name, const UnitAmount unit_amount){
    if(unit_amount < 0){
        return remove(unit_name, -unit_amount);
    }
    StorageUnit const* search = find(unit_name);
    if(search == nullptr){
        m_list.push(StorageUnit(unit_name, unit_amount));
        return true;
    }
    return const_cast<StorageUnit*>(search)->add(unit_amount);
}

bool Storehouse::remove(const StorageUnit& unit){
    if(remove(unit.getName(), unit.getAmount())){
        return true;
    }
    return false;
}

bool Storehouse::remove(String const& unit_name, const UnitAmount unit_amount){
    StorageUnit* search = const_cast<StorageUnit*>(find(unit_name));
    if(search == nullptr){
        return false;
    }
    return search->remove(unit_amount);
}

StorageUnit const* Storehouse::find(String const& unit_name) const {
    for(unsigned i = 0; i < m_list.size(); i++){
        if(m_list[i].getName() == unit_name){
            return &m_list[i];
        }
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& out, Storehouse const& obj){
    if(!obj.m_list.empty()){
        out << obj.m_list;
    }else{
        out << "Empty store.";
    }
    return out << std::endl;
}