//
// Created by toi on 27/03/2020.
//
#include <cstring>
//for: strlen(), strcpy(), strcmp()
#include <utility>
//for: swap()
#include <ctime>
//for: clock()
#include "MySpace.hpp"

bool MySpace::array_find_str(char const* arr[], char const* str) {
    if(str == nullptr){
        return false;
    }
    unsigned index = 0;
    while(arr[index] != nullptr && std::strcmp(arr[index], str) != 0){
        index++;
    }
    return arr[index] != nullptr;
}

void MySpace::mem_copy(char *& to, char const* from, bool canDeleteTo) {
    if (canDeleteTo && to != nullptr) {
        delete[] to;
        to = nullptr;
    }
    if (from == nullptr || (!canDeleteTo && to != nullptr)) {
        return;
    }
    to = new char[std::strlen(from) + 1];
    std::strcpy(to, from);
}

// local (help) function
void str_add_one(char*& str, unsigned& size, char symbol){
    if (str == nullptr) {
        size = 2;
        str = new char[size];
        str[0] = symbol;
        str[1] = '\0';
        return;
    }
    char* temp = new char[size + 1];
    std::strcpy(temp, str);
    temp[size-1] = symbol;
    temp[size] = '\0';
    ++size;
    delete[] str;
    str = temp;
}

char* MySpace::read_stream(std::istream& in, char breaker, bool ignoreAtStart){
    unsigned size = 0;// with '\0'
    char* readed = nullptr;
    for(;;){
        char symbol;
        in.get(symbol);
        if(!in.good()){
            in.clear();
            return readed;
        }
        if(symbol == breaker || symbol == '\n'){
            if(ignoreAtStart){
                continue;
            }
            return readed;
        }
        ignoreAtStart = false;
        str_add_one(readed, size, symbol);
    }
}


unsigned MySpace::rand(unsigned max, unsigned min){
    if(min > max){
        std::swap(min, max);
    }
    srand(clock());
    return (std::rand() % (max + 1)) + min;
}

unsigned intLength(int num){
    unsigned length = 0;
    do{
        length++;
        num /= 10;
    }while (num != 0);
    return length;
}

unsigned MySpace::intToCharPointer(int num, char*& pointer){
    if(pointer != nullptr){
        return 0;
    }
    unsigned length = intLength(num);
    bool negative = num < 0;
    length += negative;
    pointer = new char[length+1];
    if(negative){
        pointer[0] = '-';
    }
    for (unsigned i = 0, max = length - negative; i < max; i++){
        pointer[length-i-1] = '0' + (num % 10);
        num /= 10;
    }
    pointer[length] = '\0';
    return length;
}

bool MySpace::serialize(std::ofstream& ofs, char const* data){
    if(!ofs){
        return false;
    }
    unsigned len = 0;
    if(data != nullptr){
        len = std::strlen(data) + 1;
    }
    ofs.write((char const*) &len, sizeof(len));
    if(len != 0){
        ofs.write((char const*) data, len);
    }
    return !(!ofs);
}

bool MySpace::unserialize(std::ifstream &ifs, char *&data) {
    if(!ifs){
        return false;
    }
    if(data != nullptr){
        return false;
    }
    unsigned len = 0;
    ifs.read((char*) &len, sizeof(len));
    if(len != 0){
        data = new char[len];
        ifs.read(data, len);
    }
    return !(!ifs);
}

/*
// local (help) function
char* extractOneWord(const char*& str, char split_by){
    while (*str && *str == split_by){
        ++str;
    }
    if(*str == '\0'){
        return nullptr;
    }
    unsigned word_size = 0;
    char* word = nullptr;
    while(*str != split_by){
        str_add_one(word, word_size, *str);
        ++str;
    }
    str_add_one(word, word_size, '\0');
    return word;
}

unsigned MySpace::str_split(const char* str, char**& output, char split_by){
    if(output != nullptr || str == nullptr){
        return 0;
    }
    unsigned count = 0;
    output = char const*[str_count(str, split_by)+1];
    for(char* temp = extractOneWord(str, split_by); temp != nullptr; temp = extractOneWord(str, split_by)){
        output[count++] = temp;
    }
    return count;
}*/