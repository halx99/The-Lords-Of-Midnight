//
//  LandscapeDebug.cpp
//  citadel
//
//  Created by Chris Wild on 22/08/2017.
//
//

#include "LandscapeView.h"

void LandscapeDebug::Init(LandscapeOptions* options)
{
    LandscapeNode::Init(options);
    
    setContentSize( Size(RES(1024),RES(768)) );
    
    BuildDebug(options->generator->items);
}





void LandscapeDebug::BuildDebug( LandscapeItems* items )
{
    if ( options->debugMode != 0 ) {
        
        
        for(auto const& item: *items) {
            
            if ((item->position.z>=options->generator->viewportNear)&&(item->position.z<options->generator->viewportFar))
            {
                
                int x = options->generator->NormaliseXPosition(item->position.x);
                
                f32 y = item->position.y + horizonOffset ;
                
                // debug
                auto dot = Sprite::createWithSpriteFrameName( "dot" );
                dot->setColor(Color3B::RED);
                dot->setPosition(x, this->getContentSize().height - y);
                dot->setScale(0.1f);
                dot->setAnchorPoint(Vec2(0.5,0.5));
                this->addChild(dot);
                
                char buffer[20];
                
                switch (options->debugMode) {
                    case 1:
                        sprintf(buffer, "%d,%d", item->loc.x-(options->here.x/DIR_STEPS), item->loc.y-(options->here.y/DIR_STEPS));
                        break;
                    case 2:
                        sprintf(buffer, "%f", item->scale);
                        break;
                    case 3:
                        sprintf(buffer, "%d,%d", (int)item->position.x, (int)item->position.y);
                        break;
                    case 4:
                        sprintf(buffer, "%d,%d", item->loc.x, item->loc.y);
                        break;
                    default:
                        break;
                }
                
                
                auto label = Label::createWithTTF( buffer, "fonts/arial.ttf", 10);
                
                label->setColor(Color3B::BLUE);
                label->setAlignment(TextHAlignment::CENTER);
                label->setAnchorPoint(Vec2(0.5,0.5));
                label->setPosition(x, this->getContentSize().height - y - RES(5));
                this->addChild(label, 1);
                
                //        auto dot1 = Sprite::createWithSpriteFrameName( "dot" );
                //        dot1->setColor(Color3B::BLUE);
                //        dot1->setPosition(x-(256*scale), this->getContentSize().height - y);
                //        dot1->setScale(0.1f);
                //        dot1->setAnchorPoint(Vec2(0.5,0.5));
                //        current_landscape_node->addChild(dot1);
                //
                //        auto dot2 = Sprite::createWithSpriteFrameName( "dot" );
                //        dot2->setColor(Color3B::RED);
                //        dot2->setPosition(x+(256*scale), this->getContentSize().height - y);
                //        dot2->setScale(0.1f);
                //        dot2->setAnchorPoint(Vec2(0.5,0.5));
                //        current_landscape_node->addChild(dot2);
                
            }
            
        }
        
    }
    
    
    
    char buffer[255];
    
    sprintf(buffer, "Location %d,%d - Looking %d Landscape Adj=(%f,%f) Rotating=%d"
            , options->currentLocation.x, options->currentLocation.y
            , options->currentDirection
            , options->landScaleX, options->landScaleY
            , (int)options->rotate_look
            );
    
    
    
    auto label = Label::createWithTTF( buffer, "fonts/arial.ttf", 20);
    
    label->setMaxLineWidth(this->getContentSize().width);
    label->setAnchorPoint(Vec2(0,0));
    label->setColor(Color3B::WHITE);
    label->setPosition(RES(10), (this->getContentSize().height - RES(20)));
    this->addChild(label, 1);
    
    
}


