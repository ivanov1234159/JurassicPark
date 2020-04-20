//
// Created by toi on 26/03/2020.
//

#ifndef JURASSICPARK_STORAGEUNIT_HPP
#define JURASSICPARK_STORAGEUNIT_HPP

typedef double UnitAmount;

class StorageUnit {
    static const UnitAmount EPS;
    char* m_name;
    unsigned m_name_size;// size of "the pointer" (length of name + 1); 1 for '\0'
    UnitAmount m_amount;

public:
    static bool areEqual(const UnitAmount amount1, const UnitAmount amount2);

    StorageUnit(const char* name = nullptr, UnitAmount amount = 0);
    StorageUnit(const StorageUnit& other);
    StorageUnit& operator=(const StorageUnit& other);
    ~StorageUnit();

    void getName(char*& name) const;
    UnitAmount getAmount() const;

    bool add(const UnitAmount amount);
    bool remove(const UnitAmount amount);

private:
    void clear();
    void copy(const StorageUnit& other);
    void copy(const char* name, const unsigned name_size, const UnitAmount amount);
};

#endif //JURASSICPARK_STORAGEUNIT_HPP
