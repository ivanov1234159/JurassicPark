//
// Created by toi on 02/05/2020.
//

#include "CmdHelp.hpp"
#include "../Commander.hpp"

CmdHelp::CmdHelp(): Command("help", "", "prints this information") {}

bool CmdHelp::action(RunnerType&, std::istringstream&) const {
    std::cout << "Support the following commands:" << std::endl;
    for(unsigned i = 0; i < Commander::cmd_list.size(); i++){
        std::cout << *Commander::cmd_list[i];
    }
    return true;
}