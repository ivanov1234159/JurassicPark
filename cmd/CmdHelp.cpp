//
// Created by toi on 02/05/2020.
//

#include "CmdHelp.hpp"
#include "../Commander.hpp"

CmdHelp::CmdHelp(): Command("help", "", "prints this information") {}

bool CmdHelp::action(std::ostream& out, RunnerType&, std::istringstream&) const {
    out << "Support the following commands:" << std::endl;
    for(unsigned i = 0; i < Commander::cmd_list.size(); i++){
        out << *Commander::cmd_list[i];
    }
    return true;
}