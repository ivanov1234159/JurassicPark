//
// Created by toi on 27/03/2020.
//

#ifndef ___MYSPACE_MYSPACE_HPP___
#define ___MYSPACE_MYSPACE_HPP___

#include <iostream>
//for: istream, cin
#include <fstream>
//for: ofstream, ifstream

namespace MySpace {
    bool array_find_str(char const *arr[], char const *str);

    void mem_copy(char *&to, char const *from = nullptr, bool canDeleteTo = true);

    char *read_stream(std::istream &in = std::cin, char breaker = '\n', bool ignoreAtStart = true);

    unsigned rand(unsigned max, unsigned min = 0);

    template <typename T>
    T const& max(T const& first, T const& second){
        if(second > first){
            return second;
        }
        return first;
    }

    unsigned intToCharPointer(int num, char*& pointer);

    bool serialize(std::ofstream& ofs, char const* data);

    bool unserialize(std::ifstream& ifs, char*& data);

    //unsigned str_split(const char* str, char**& output, char split_by = ' ')
}
#endif //___MYSPACE_MYSPACE_HPP___
