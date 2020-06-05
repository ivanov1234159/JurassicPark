//
// Created by toi on 26/03/2020.
//

#ifndef JURASSICPARK_STORAGEUNIT_HPP
#define JURASSICPARK_STORAGEUNIT_HPP

#include <iostream>
//for: ostream, endl
#include "String.hpp"

typedef double UnitAmount;

/// @class StorageUnit
class StorageUnit {
    /// used if UnitAmount is a floating point number,
    /// but is still valid and for whole numbers
    static const UnitAmount EPS;

    String m_name;
    UnitAmount m_amount;

    /// used to get amount as a whole number
    bool m_integer;
public:
    /**
     * check if amount1 and amount2 are equal (using StorageUnit::EPS)
     * @param amount1
     * @param amount2
     * @return false if they are NOT equal
     */
    static bool areEqual(const UnitAmount amount1, const UnitAmount amount2);

    /// default constructor and constructor with arguments name (and amount (and integer) )
    StorageUnit(String const& name = nullptr, UnitAmount amount = 0, bool integer = false);

    /**
     * getter for m_name
     * @return m_name
     */
    String const& getName() const;

    /**
     * getter for m_amount
     * @return m_amount
     */
    UnitAmount getAmount() const;

    /**
     * getter for m_integer
     * @return m_integer
     */
    bool isWholeNumber() const;

    /**
     * add <amount> to m_amount
     * @param amount - if is negative, then removes; calls remove() method
     * @return false if can't remove the <amount> (reason: not enough)
     */
    bool add(const UnitAmount amount);

    /**
     * remove <amount> form m_amount
     * @param amount - if is negative, then adds
     * @return false if can't remove the <amount> (reason: not enough)
     */
    bool remove(const UnitAmount amount);
};

std::ostream& operator<<(std::ostream& out, StorageUnit const& obj);

#endif //JURASSICPARK_STORAGEUNIT_HPP
