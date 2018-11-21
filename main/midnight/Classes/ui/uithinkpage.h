//
//  uithinkpage.h
//  midnight
//
//  Created by Chris Wild on 16/10/2018.
//Copyright © 2018 Chilli Hugger Software. All rights reserved.
//

#pragma once

#include "../ui/uielement.h"
#include "../frontend/panel_id.h"
#include "../tme_interface.h"

using namespace cocos2d::ui;
using namespace cocos2d;

class uithinkpage : public uielement
            // , public uinotificationdelegate
            // , public uiactioncompletedelegate
            // , public uidragmoveelement
{
public:
   
    CREATE_FUNC(uithinkpage);
    
    void setObject( mxid id, mxid objectId, panelmode_t mode );
    
protected:

    uithinkpage();
    virtual bool init() override;
    
    void setupUI();
    
    void displayCharacter ( const character& c );
    void displayCharacterTerrain(  const character& c );
    void displayTerrain ( mxterrain_t terrain );
    void displayObject ( mxid objectid );
    void displayArmy ( void );
    
    void aheadOrHere( LPSTR text, tme::loc_t location, bool aheaddir );
    void checkPerson(void);
    void checkPlace(void);
    void checkBattle(void);
    void checkNormal(void);
    void checkArmy(void);
    
    void recruitPostOptions ( stronghold& s );
    
protected:
    mxid                id;
    mxid                objectid ;
    panelmode_t         mode;
    character           current_character;
    stronghold          current_stronghold;
    
    cocos2d::Label*     lblName;
    cocos2d::Label*     lblDescription;
    
    Sprite*             imgTerrain;
    ImageView*          imgCharacter;
    ImageView*          imgObject;
    
    ScrollView*         scrollView;
    Layer*              safeArea;
    
public:
    bool                approach;
    bool                fight;
    bool                unhide;
    bool                leave;
    bool                disband;
    bool                postMen;
    bool                recruitMen;
    
};



