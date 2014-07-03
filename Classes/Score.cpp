//
//  Score.cpp
//  Game
//
//  Created by Mr.Chen on 14-6-5.
//
//

#include "Score.h"
#include "Menu.h"
USING_NS_CC;
Scene* Score::createScene()
{
    auto scene = Scene::create();
    auto layer = Score::create();
    scene->addChild(layer);
    return scene;
}
bool Score::init()
{
    Size vis=Director::getInstance()->getVisibleSize();
    
    Sprite* spr=Sprite::create("score_bg.png");
    spr->setPosition(Point(vis.width/2, vis.height/2));
    this->addChild(spr,0);
    
    Label* back=Label::createWithSystemFont("返回主菜单", "Helvetica-Bold", 24);
    MenuItemLabel* menuLabel=MenuItemLabel::create(back, CC_CALLBACK_1(Score::backMenu,this));
    menuLabel->setPosition(Point(0,-200));
    Menu* menu=Menu::create(menuLabel, NULL);
    this->addChild(menu);
    
    
    return true;
}
void Score::backMenu(Ref* ref)
{
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, GameMenu::createScene(), Color3B::BLACK));
}