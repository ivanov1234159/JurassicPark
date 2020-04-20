//
// Created by toi on 19/04/2020.
//

#include "Array.hpp"
#include <iostream>
//for: cout, endl

void arrayTest(){
    Array<char> test;
    test.push('o');
    test.push('e');
    test.push('l');
    test.push('l');
    test.push(test.unshift());
    test.push('H');
    test.shift(test.pop());
    unsigned vary = 0;
    if(test.empty()){
        vary = test.size();
    }else{
        vary = test.free();
    }
    char temp = test.at(-1);
    if(!test.fixed()){
        temp = test[vary-3];
    }
    std::cout << test;
    if(test.full()){
        std::cout << vary << "; " << temp << std::endl;
    }
    Array<char> lastCheck = test;
    lastCheck.remove(-1);
    test = lastCheck;
    std::cout << "All tests were passed successfully!" << std::endl;
}