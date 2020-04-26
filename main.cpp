#include "Commander.hpp"
#include "JurassicPark.hpp"
#include <iostream>
//for: cout, endl

int main() {
    build_commands();
    if(!JurassicPark::self().open()){
        std::cout << "Couldn't restore the data." << std::endl;
        return 1;
    }
    std::cout << "The data was successfully restored." << std::endl;
    Commander::run(JurassicPark::self());
    return 0;
}