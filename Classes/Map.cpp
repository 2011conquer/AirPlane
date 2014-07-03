//
//  Map.cpp
//  Game
//
//  Created by Mr.Chen on 14-6-5.
//
//

#include "Map.h"
#include "cocos2d.h"
USING_NS_CC;
GameMap* GameMap::create(char* mapName)
{
    GameMap *pRet = new GameMap();
    if (pRet && pRet->initWithMap(mapName))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
bool GameMap::initWithMap(char* mapName)
{
    Size visible=Director::getInstance()->getVisibleSize();
    
    Sprite* spr1=Sprite::create(mapName);
    spr1->setPosition(Point(visible.width*0.5, spr1->getContentSize().height*0.5));
    this->addChild(spr1,0,110);
    
    Sprite* spr2=Sprite::create(mapName);
    spr2->setPosition(Point(visible.width*0.5, spr2->getContentSize().height*1.5));
    this->addChild(spr2,0,111);
    
//    this->schedule(schedule_selector(GameMap::update), 0.03f);
    this->scheduleUpdate();
    
    return true;
}
void GameMap::update(float time)
{
    Sprite* spr1=(Sprite*)this->getChildByTag(110);
    Sprite* spr2=(Sprite*)this->getChildByTag(111);
    
    spr1->setPosition(spr1->getPosition()+Point(0, -1.5));
    spr2->setPosition(spr2->getPosition()+Point(0, -1.5));
    
    if(spr1->getPosition().y < -(spr1->getContentSize().height/2))
    {
        spr1->setPosition(Point(spr1->getContentSize().width/2, spr1->getContentSize().height*1.5-1.5));
    }
    if(spr2->getPosition().y < -(spr2->getContentSize().height/2))
    {
        spr2->setPosition(Point(spr2->getContentSize().width/2, spr2->getContentSize().height*1.5-1.5));
    }

}




