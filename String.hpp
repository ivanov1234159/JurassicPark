//
// Created by toi on 13/05/2020.
//

#ifndef ___MYSPACE_STRING_HPP___
#define ___MYSPACE_STRING_HPP___

#include "Vector.hpp"

class String : public Vector<char> {
public:
    String(char const* str = nullptr);

    bool set(char const* str);

    char const* get() const;
    bool get(char*& str) const;

    void append(String const& other);

    bool operator==(String const& other) const;
    bool operator!=(String const& other) const;

    bool operator>(String const& other) const;
    bool operator>=(String const& other) const;

    bool operator<(String const& other) const;
    bool operator<=(String const& other) const;

    String& operator+=(String const& other);
};

#endif //___MYSPACE_STRING_HPP___
