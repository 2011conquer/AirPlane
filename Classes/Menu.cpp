//
//  Menu.cpp
//  Game
//
//  Created by Mr.Chen on 14-6-5.
//
//

#include "Menu.h"
USING_NS_CC;

Scene* GameMenu::createScene()
{
    auto scene = Scene::create();
    auto layer = GameMenu::create();
    scene->addChild(layer);
    return scene;
}
bool GameMenu::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
//    Point origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite* menuMap=Sprite::create("menu_bg.png");
    menuMap->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    this->addChild(menuMap,0);
    
    auto menuPlay=MenuItemImage::create("play_nor.png", "play_pre.png", CC_CALLBACK_1(GameMenu::playGame, this));
    menuPlay->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    
    auto menuScore=MenuItemImage::create("score_nor.png", "score_pre.png", CC_CALLBACK_1(GameMenu::scoreGame, this));
    menuScore->setPosition(Point(visibleSize.width/2, visibleSize.height/2-80));
    
    auto menuAbout=MenuItemImage::create("about_nor.png", "about_pre.png", CC_CALLBACK_1(GameMenu::aboutGame, this));
    menuAbout->setPosition(Point(visibleSize.width/2, visibleSize.height/2-160));
    
    auto menu=Menu::create(menuPlay,menuScore,menuAbout,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu,1);
    return true;
}
void GameMenu::playGame(Ref *ref)
{
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, World::createScene(), Color3B::BLACK));
}
void GameMenu::scoreGame(Ref* ref)
{
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, Score::createScene(), Color3B::BLACK));
}
void GameMenu::aboutGame(Ref* ref)
{
    
}
