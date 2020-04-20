//
// Created by toi on 26/03/2020.
//

#ifndef JURASSICPARK_STOREHOUSE_HPP
#define JURASSICPARK_STOREHOUSE_HPP

#include "StorageUnit.hpp"

class Storehouse {
    StorageUnit* m_list;// list of all storage unit (food)
    unsigned m_size;
    unsigned m_limit;
public:
    Storehouse(unsigned limit = 3);
    Storehouse(const Storehouse& other);
    Storehouse& operator=(const Storehouse& other);
    ~Storehouse();

    bool empty() const;
    bool full() const;

    bool has(const char* unit_name) const;// returns false if no such unit name
    bool has(const StorageUnit& unit) const;// same as has(const char* unit_name, const double unit_amount)
    bool has(const char* unit_name, const UnitAmount unit_amount) const;// returns false if has(unit_name) returns false OR current amount < unit_amount

    bool add(const StorageUnit& unit);// same as add(const char* unit_name, const double unit_amount)
    bool add(const char* unit_name, const UnitAmount unit_amount);// returns false if unit_amount < 0 and remove() returns false

    bool remove(const StorageUnit& unit);// same as remove(const char* unit_name, const double unit_amount)
    bool remove(const char* unit_name, const UnitAmount unit_amount);// returns false if(!has(unit_name, unit_amount))

private:
    StorageUnit* find(const char* unit_name) const;// !!! this function doesn't returns const type value
    void clear();
    void copy(const Storehouse& other);
    void copy(const StorageUnit* list, const unsigned size, const unsigned limit);
    void resize();
};

#endif //JURASSICPARK_STOREHOUSE_HPP
