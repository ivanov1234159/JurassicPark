//
// Created by toi on 26/03/2020.
//

#ifndef JURASSICPARK_STOREHOUSE_HPP
#define JURASSICPARK_STOREHOUSE_HPP

#include <iostream>
//for: ostream, endl
#include "StorageUnit.hpp"
#include "Vector.hpp"

/// @class Storehouse
class Storehouse {
    /// list of all storage units (food and staff)
    Vector<StorageUnit> m_list;
public:
    /// default constructor and constructor with argument limit
    Storehouse(unsigned limit = 2);

    /**
     * check if exists a storage unit with the given name
     * @param unit_name
     * @return false if there is no unit with that name
     */
    bool has(String const& unit_name) const;

    /**
     * check if exists a storage unit like the given one;
     * calls has(String const&, const UnitAmount) method
     * @param unit
     * @return false if there is no unit with that name OR there isn't enough amount
     */
    bool has(const StorageUnit& unit) const;

    /**
     * check if exists a storage unit with the given name and enough amount
     * @param unit_name
     * @param unit_amount
     * @return false if there is no unit with that name OR there isn't enough amount OR <unit_amount> is negative
     */
    bool has(String const& unit_name, const UnitAmount unit_amount) const;

    /**
     * add a new storage unit using <unit>;
     * calls add(String const&, const UnitAmount, bool) method
     * @param unit
     * @return false if can't remove the amount (reason: not enough amount)
     */
    bool add(const StorageUnit& unit);

    /**
     * add a new storage unit with name and amount
     * @param unit_name
     * @param unit_amount - can be negative
     * @param whole_number - by default is false
     * @return false if can't remove the amount (reason: not enough amount OR there is no unit with that name)
     */
    bool add(String const& unit_name, const UnitAmount unit_amount, bool whole_number = false);

    /**
     * remove amount from a storage unit using <unit>;
     * calls remove(String const&, const UnitAmount) method
     * @param unit
     * @return false if can't remove the amount (reason: not enough amount OR there is no unit with that name)
     */
    bool remove(const StorageUnit& unit);

    /**
     * remove amount from a storage unit with <name>
     * @param unit_name
     * @param unit_amount
     * @return false if can't remove the amount (reason: not enough amount OR there is no unit with that name)
     */
    bool remove(String const& unit_name, const UnitAmount unit_amount);

    friend std::ostream& operator<<(std::ostream& out, Storehouse const& obj);
private:
    /**
     * search for a storage unit by name
     * @param unit_name
     * @return nullptr if NOT found OR a pointer to the first match
     */
    StorageUnit const* find(String const& unit_name) const;
};

std::ostream& operator<<(std::ostream& out, Storehouse const& obj);

#endif //JURASSICPARK_STOREHOUSE_HPP
