//
//  uioptionitem.cpp
//  midnight
//
//  Created by Chris Wild on 09/12/2017.
//

#include "uioptionitem.h"
#include "../system/resolutionmanager.h"
#include "uihelper.h"


USING_NS_CC;

using namespace cocos2d::ui;

uioptionitem* uioptionitem::create( f32 width, uitextmenuitem* item )
{
    uioptionitem* node = new (std::nothrow) uioptionitem();
    if (node && node->initWithItem(width,item))
    {
        node->autorelease();
        return node;
    }
    CC_SAFE_DELETE(node);
    return nullptr;
}


bool uioptionitem::initWithItem(f32 width, uitextmenuitem* item)
{
    if ( !initWithFile(Rect::ZERO, BOX_BACKGROUND_FILENAME) )
        return false;
    
    //f32 itemHeight = uihelper::font_config_big.fontSize;
    f32 paddingY = RES(10);
    f32 height=0;
    
    title = Label::createWithTTF( uihelper::font_config_big, item->type.text );
    title->getFontAtlas()->setAntiAliasTexParameters();
    title->setTextColor(Color4B(_clrBlue));
    //title->setLineHeight(itemHeight);
    addChild(title);
    height += title->getBoundingBox().size.height;
    
    value = Label::createWithTTF(uihelper::font_config_big, "OPTION" );
    value->getFontAtlas()->setAntiAliasTexParameters();
    value->setTextColor(Color4B(_clrRed));
    //value->setLineHeight(itemHeight);
    addChild(value);
    height += value->getBoundingBox().size.height;
    
    this->setContentSize(Size(width,height+(2*paddingY)) );

    uihelper::PositionParentCenter(title, 0, 0 );
    title->setAnchorPoint( uihelper::AnchorBottomCenter );
    
    uihelper::PositionParentCenter(value, 0, 0 );
    value->setAnchorPoint( uihelper::AnchorTopCenter );
    
    return true;
}

void uioptionitem::setValue( const std::string& text )
{
    value->setString(text);
}


MenuItemNode* MenuItemNode::create( Node* option )
{
    MenuItemNode* node = new (std::nothrow) MenuItemNode();
    if (node && node->initWithNode(option))
    {
        node->autorelease();
        return node;
    }
    CC_SAFE_DELETE(node);
    return nullptr;
}

bool MenuItemNode::initWithNode( Node* option)
{
    if (!initWithNormalSprite(option, nullptr, nullptr, nullptr) )
        return false;
    
    setEnabled(true);
    
    return true;
}

void MenuItemNode::selected()
{
    MenuItemSprite::selected();
    setScale(0.9f);
}

void MenuItemNode::unselected()
{
    MenuItemSprite::unselected();
    setScale(1.0f);
}


