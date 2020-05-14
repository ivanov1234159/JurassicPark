//
// Created by toi on 26/03/2020.
//

#ifndef JURASSICPARK_STOREHOUSE_HPP
#define JURASSICPARK_STOREHOUSE_HPP

#include "StorageUnit.hpp"
#include "Vector.hpp"

class Storehouse {
    Vector<StorageUnit> m_list;// list of all storage unit (food)
public:
    Storehouse(unsigned limit = 2);

    bool has(String const& unit_name) const;// returns false if no such unit name
    bool has(const StorageUnit& unit) const;// same as has(String const& unit_name, const UnitAmount unit_amount)
    bool has(String const& unit_name, const UnitAmount unit_amount) const;// returns false if has(unit_name) returns false OR current amount < unit_amount

    bool add(const StorageUnit& unit);// same as add(String const& unit_name, const UnitAmount unit_amount)
    bool add(String const& unit_name, const UnitAmount unit_amount);// returns false if unit_amount < 0 and remove() returns false

    bool remove(const StorageUnit& unit);// same as remove(String const& unit_name, const UnitAmount unit_amount)
    bool remove(String const& unit_name, const UnitAmount unit_amount);// returns false if(!has(unit_name, unit_amount))

private:
    StorageUnit const* find(String const& unit_name) const;
};

#endif //JURASSICPARK_STOREHOUSE_HPP
