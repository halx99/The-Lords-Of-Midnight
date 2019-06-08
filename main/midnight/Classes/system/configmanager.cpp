//
//  configmanager.cpp
//  midnight
//
//  Created by Chris Wild on 07/06/2019.
//  Copyright © 2019 Chilli Hugger Software. All rights reserved.
//

#include "configmanager.h"
#include "moonring.h"
#include "tmemanager.h"
#include "../library/chilli.h"


configmanager::configmanager() :
    skip_adverts(false),
    skip_dedication(false)
{
}

configmanager::~configmanager()
{
}

bool configmanager::LoadXmlConfig (const std::string& filename )
{
    using xml = chilli::lib::xml;
    //char path[MAX_PATH];
    
    UIDEBUG("configmanager::LoadXmlConfig - ENTER");
    
    std::unique_ptr<xml> config ( new xml() );

    if ( !config->Load ( filename.c_str() ) ) {
        COMPLAIN ( "Cannot load config" );
    }
    
    auto main = config->Find("main");
    if ( main == nullptr ) {
        COMPLAIN ( "invalid config file: <main>" );
    }
    
    auto variables = main->Find("variables");
    if ( variables == nullptr ) {
        UIDEBUG ( "missing tag: <variables>" );
        return false;
    }
    
#define IS_VAR(x)    \
    c_stricmp(x,name) == 0
    
    FOREACHELEMENT(variables,t) {
        if ( t->IsType("var") ) {
            
            auto name = t->ReadStr("id");
            auto value = t->ReadBool("value");
            
            UIDEBUG("VAR %s = '%s'", name, t->ReadStr("value"));
            
            if ( IS_VAR("sv_cheat_armies_noblock") ) {
                tme::variables::sv_cheat_armies_noblock = value;
            }
            
            else if ( IS_VAR("sv_cheat_nasties_noblock") ) {
                tme::variables::sv_cheat_nasties_noblock = value;
            }
            
            else if ( IS_VAR("sv_cheat_commands_free") ) {
                tme::variables::sv_cheat_commands_free = value;
            }
            
            else if ( IS_VAR("sv_cheat_movement_cheap") ) {
                tme::variables::sv_cheat_movement_cheap = value;
            }
            
            else if ( IS_VAR("sv_cheat_movement_free") ) {
                tme::variables::sv_cheat_movement_free = value;
            }

            else if ( IS_VAR("skip_dedication") ) {
                skip_dedication = value;
            }
            
            else if ( IS_VAR("skip_adverts") ) {
                skip_adverts = value;
            }
            
        }
    }
    
    UIDEBUG("configmanager::LoadXmlConfig - EXIT");
    
    return true ;
}
