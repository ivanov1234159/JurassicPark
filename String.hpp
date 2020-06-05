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

/**
 * @class String
 * child of Vector<char>
 */
class String : public Vector<char> {
public:
    /**
     * generate string from integer
     * @param num
     * @return object from type String
     */
    static String to_string(int num);

    /// default constructor and constructor with argument str
    String(char const* str = nullptr);

    /**
     * set str to the object char by char
     * @param str
     * @return false if str is nullptr
     */
    bool set(char const* str);

    /// @return pointer to the list of characters
    char const* get() const;

    /**
     * get a pointer to the list of characters
     * @param str - used to return a copy of the list of characters
     * @return false if str is NOT nullptr or the object is empty
     */
    bool get(char*& str) const;

    /**
     * join both strings (this as first and other as second)
     * also it cares about the determining zero '\0'
     * @param other
     */
    void append(String const& other);

    /**
     * read fromm the source and set the read with set() method
     * calls MySpace::read_stream()
     * @param from - the source
     * @param until - reads until this character is read
     */
    void read(std::istream& from, char until = ' ');

    /**
     * check if this string contains other one
     * @param other
     * @return true if it does
     */
    bool contains(String const& other) const;

    /// @return true if is empty
    bool operator!() const;

    /**
     * compare the two strings
     * @param other
     * @return true if they are equal
     */
    bool operator==(String const& other) const;

    /**
     * compare the two strings
     * @param other
     * @return true if they are NOT equal
     */
    bool operator!=(String const& other) const;

    /**
     * compare the two strings
     * @param other
     * @return true if the first is bigger than the second
     */
    bool operator>(String const& other) const;

    /**
     * compare the two strings
     * @param other
     * @return true if the first is bigger than the second or they are equal
     */
    bool operator>=(String const& other) const;

    /**
     * compare the two strings
     * @param other
     * @return true if the first is smaller than the second
     */
    bool operator<(String const& other) const;

    /**
     * compare the two strings
     * @param other
     * @return true if the first is smaller than the second or they are equal
     */
    bool operator<=(String const& other) const;

    /**
     * join both strings (this as first and other as second)
     * calls append() method
     * @param other
     * @return this
     */
    String& operator+=(String const& other);

    /**
     * serialize this object
     * calls MySpace::serialize() method
     * @param ofs
     * @return false on fail
     */
    bool serialize(std::ofstream& ofs) const;

    /**
     * deserialize this object
     * calls MySpace::unserialize() method
     * @param ifs
     * @return false on fail
     */
    bool unserialize(std::ifstream& ifs);
};

std::ostream& operator<<(std::ostream& out, String const& obj);
std::istream& operator>>(std::istream& in, String& obj);

#endif //___MYSPACE_STRING_HPP___
