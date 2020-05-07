//
// Created by toi on 08/04/2020.
//

#include "Commander.hpp"
#include "CmdAddAnimal.hpp"
#include "CmdCreateCage.hpp"
#include "CmdExit.hpp"
#include "CmdHelp.hpp"
#include "CmdSave.hpp"
#include "CmdStatus.hpp"

void build_commands(){
    Commander::add(new CmdAddAnimal);
    Commander::add(new CmdCreateCage);
    Commander::add(new CmdExit);
    Commander::add(new CmdHelp);
    Commander::add(new CmdSave);
    Commander::add(new CmdStatus);
}