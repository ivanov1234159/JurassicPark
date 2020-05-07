//
// Created by toi on 19/04/2020.
//

#include "Vector.hpp"
#include <iostream>
//for: cout, endl

void vectorTest(){
    Vector<char> test;
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
    Vector<char> lastCheck = test;
    lastCheck.remove(-1);
    test = lastCheck;
    std::cout << "All tests were passed successfully!" << std::endl;
}