//
// Created by toi on 13/05/2020.
//

#include <cstring>
//for: strlen(), strcpy(), strcmp()
#include "String.hpp"
#include "MySpace.hpp"

String::String(const char *str) {
    set(str);
}

bool String::set(char const *str) {
    if(str == nullptr){
        return false;
    }
    while (!empty()){
        pop();
    }
    unsigned size = std::strlen(str)+1;
    for(unsigned i = 0; i < size; i++){
        push(str[i]);
    }
    return true;
}

char const* String::get() const {
    if(empty()){
        return "";
    }
    return list();
}

bool String::get(char*& str) const {
    if(str != nullptr || empty()){
        return false;
    }
    str = new char[size()];
    std::strcpy(str, get());
    return true;
}

void String::append(String const &other) {
    if(other.empty()){
        return;
    }
    bool zeroAtEnd = !empty() && at(-1) == '\0';
    if(zeroAtEnd){
        at(-1) = other[0];
    }
    for(unsigned i = zeroAtEnd; i < other.size(); i++){
        push(other[i]);
    }
    if(zeroAtEnd && at(-1) != '\0'){
        push('\0');
    }
}

bool String::operator!() const {
    return empty();
}

bool String::operator==(String const &other) const {
    return std::strcmp(get(), other.get()) == 0;
}

bool String::operator!=(String const &other) const {
    return !(*this == other);
}

bool String::operator>(String const &other) const {
    return std::strcmp(get(), other.get()) > 0;
}

bool String::operator>=(String const &other) const {
    return !(*this < other);
}

bool String::operator<(String const &other) const {
    return std::strcmp(get(), other.get()) < 0;
}

bool String::operator<=(String const &other) const {
    return !(*this > other);
}

String& String::operator+=(String const &other) {
    append(other);
    return *this;
}

bool String::serialize(std::ofstream &ofs) const {
    return MySpace::serialize(ofs, list());
}

bool String::unserialize(std::ifstream &ifs) {
    char* str = nullptr;
    bool result = MySpace::unserialize(ifs, str);
    if(str != nullptr){
        *this = str;
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, String const& obj){
    return out << obj.get();
}

std::istream& operator>>(std::istream& in, String& obj){
    obj.set(MySpace::read_stream(in, ' '));
    return in;
}