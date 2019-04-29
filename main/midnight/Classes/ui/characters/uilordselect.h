//
//  uilordselect.h
//  midnight
//
//  Created by Chris Wild on 29/10/2018.
//
//

#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "../uielement.h"


#include "../../tme_interface.h"

enum LORD_STATUS {
    status_normal=0,
    status_dawn     = MXBIT(1),
    status_night    = MXBIT(2),
    status_inbattle = MXBIT(3),
    status_dead     = MXBIT(4),
    status_tunnel   = MXBIT(5),
    status_selected = MXBIT(6),
    status_location = MXBIT(7),
};

#define MOUSE_OVER_INNER        ((UIMOUSEOVER)(MOUSE_OVER_USER+0))
#define MOUSE_OVER_OUTER        ((UIMOUSEOVER)(MOUSE_OVER_USER+1))
#define MOUSE_OVER_FACE         ((UIMOUSEOVER)(MOUSE_OVER_USER+2))
#define MOUSE_OVER_FOLLOWER     ((UIMOUSEOVER)(MOUSE_OVER_USER+3))

#define DISTANCE_SHIELD         RES(40)
#define DISTANCE_INNER          RES(75)
#define DISTANCE_OUTER          RES(128)
#define SELECT_ELEMENT_WIDTH    DIS(128)
#define SELECT_ELEMENT_HEIGHT   DIS(128)
#define SELECT_IMAGE_HEIGHT     DIS(72)

enum lord_type_t {
    lordtype_select = 0,
    lordtype_single = 1,
    lordtype_group = 2,
    lordtype_grouped = 3
};


class uilordselect : public cocos2d::ui::Widget,
public uidragmoveelement, public uidroptarget
{
public:
    
    CREATE_FUNC(uilordselect);
    
    virtual bool init() override;
    virtual void updateStatus(character& c);
    virtual bool setLord( mxid characterid );
    virtual void refreshStatus();

    virtual UIMOUSEOVER MouseOverHotspot( cocos2d::Vec2 pos, UIMOUSEOVERHINT hint ) const override ;

    cocos2d::Vec2 getCenter() const;
    
protected:
    uilordselect();
    void addTouchListener();

    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event* ) override;
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event* ) override;
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event* )  override;
    void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event* ) override;
    
    virtual void OnStopDrag(uidragevent* event) override;
    virtual void OnStartDrag(uidragevent* event) override;
    virtual void OnDropStart() override;
    virtual void OnDropStop() override;
    
    cocos2d::Vec2 mouse_down_pos;
    cocos2d::Vec2 mouse_last_position;;

public:
    flags16         status;
    mxid            characterId;
    lord_type_t     lordtype;
    
};
