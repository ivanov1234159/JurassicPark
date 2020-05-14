//
// Created by toi on 26/03/2020.
//

#ifndef JURASSICPARK_STORAGEUNIT_HPP
#define JURASSICPARK_STORAGEUNIT_HPP

#include "String.hpp"

typedef double UnitAmount;

class StorageUnit {
    static const UnitAmount EPS;
    String m_name;
    UnitAmount m_amount;
public:
    static bool areEqual(const UnitAmount amount1, const UnitAmount amount2);

    StorageUnit(String const& name = nullptr, UnitAmount amount = 0);

    String const& getName() const;
    UnitAmount getAmount() const;

    bool add(const UnitAmount amount);
    bool remove(const UnitAmount amount);
};

#endif //JURASSICPARK_STORAGEUNIT_HPP
