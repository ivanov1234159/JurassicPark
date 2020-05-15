//
// Created by toi on 13/05/2020.
//

#ifndef ___MYSPACE_STRING_HPP___
#define ___MYSPACE_STRING_HPP___

#include <fstream>
//for: ofstream, ifstream
#include <iostream>
//for: istraem, ostream
#include "Vector.hpp"

class String : public Vector<char> {
public:
    String(char const* str = nullptr);

    bool set(char const* str);

    char const* get() const;
    bool get(char*& str) const;

    void append(String const& other);

    bool operator!() const;

    bool operator==(String const& other) const;
    bool operator!=(String const& other) const;

    bool operator>(String const& other) const;
    bool operator>=(String const& other) const;

    bool operator<(String const& other) const;
    bool operator<=(String const& other) const;

    String& operator+=(String const& other);

    bool serialize(std::ofstream& ofs) const;
    bool unserialize(std::ifstream& ifs);
};

std::ostream& operator<<(std::ostream& out, String const& obj);
std::istream& operator>>(std::istream& in, String& obj);

#endif //___MYSPACE_STRING_HPP___
