//
// Created by toi on 27/03/2020.
//

#ifndef ___MYSPACE_MYSPACE_HPP___
#define ___MYSPACE_MYSPACE_HPP___

#include <iostream>
//for: istream, cin
namespace MySpace {
    bool array_find_str(char const *arr[], char const *str);

    void mem_copy(char *&to, char const *from = nullptr, bool canDeleteTo = true);

    char *read_stream(std::istream &in = std::cin, char breaker = '\n');

    unsigned rand(unsigned max, unsigned min = 0);

    unsigned intToCharPointer(int num, char*& pointer);

    //unsigned str_split(const char* str, char**& output, char split_by = ' ')
}
#endif //___MYSPACE_MYSPACE_HPP___
