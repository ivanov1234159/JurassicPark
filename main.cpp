#include "Commander.hpp"
#include "JurassicPark.hpp"
//#include <sstream>
//for: istringstream

int main() {
    //runAllTests();
    build_commands();
    //std::istringstream iss;
    //Commander::call("open", JurassicPark::self(), iss);
    //TODO: if has saved file, restore it
    Commander::run(JurassicPark::self());
    return 0;
}