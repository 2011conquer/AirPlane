//
//  World.cpp
//  Game
//
//  Created by Mr.Chen on 14-6-5.
//
//

#include "World.h"
#include "Menu.h"
USING_NS_CC;

World* pt=NULL;

Scene* World::createScene()
{
    auto scene = Scene::create();
    auto layer = World::create();
    scene->addChild(layer);
    return scene;
}
bool World::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    pt=this;
    this->addChild(GameMap::create("map.png"),0);
    this->addChild(Player::create(),1,666);
    //生成怪物
    this->schedule(schedule_selector(World::createEnemy), 1);
    //生成子弹
    this->schedule(schedule_selector(World::createBullet), 0.3);
    
    return true;
}
World* World::getWorldScene()
{
    if(pt!=NULL){return pt;}
    else{return NULL;}
}
Player* World::getPlayer()
{
    Player* pl=(Player*)this->getChildByTag(666);
    return pl;
}
Vector<Sprite*> World::getEnemyArray()
{
    return arrayEnemy;
}
void World::createBullet(float time)
{
    Bullet* bull=Bullet::create();
    Player* pl=World::getWorldScene()->getPlayer();
    bull->setPosition(Point(pl->getPosition().x,pl->getPosition().y+pl->getContentSize().height/2-2));
    this->addChild(bull);
}
void World::winGame()
{
    Size si=Director::getInstance()->getWinSize();
    LayerColor* layercolor=LayerColor::create(Color4B::GRAY);
    Sprite* spr=Sprite::create("game_win.png");
    spr->setPosition(Point(si.width/2, si.height/2));
    layercolor->addChild(spr);
    this->addChild(layercolor,100);
    
    Label* back=Label::createWithSystemFont("返回主菜单", "Helvetica-Bold", 24);
    MenuItemLabel* menuLabel=MenuItemLabel::create(back, CC_CALLBACK_1(World::backMenu,this));
    menuLabel->setPosition(Point(0,-200));
    Menu* menu=Menu::create(menuLabel, NULL);
    this->addChild(menu);
    
    Director::getInstance()->pause();
}
void World::lostGame()
{
    Size si=Director::getInstance()->getWinSize();
    LayerColor* layercolor=LayerColor::create(Color4B::GRAY);
    Sprite* spr=Sprite::create("game_lost.png");
    spr->setPosition(Point(si.width/2, si.height/2));
    layercolor->addChild(spr);
    this->addChild(layercolor,100);
    
    Label* back=Label::createWithSystemFont("返回主菜单", "Helvetica-Bold", 24);
    MenuItemLabel* menuLabel=MenuItemLabel::create(back, CC_CALLBACK_1(World::backMenu,this));
    menuLabel->setPosition(Point(0,-200));
    Menu* menu=Menu::create(menuLabel, NULL);
    this->addChild(menu);
    
    Director::getInstance()->pause();
}
void World::backMenu(Ref* ref)
{
    Director::getInstance()->replaceScene(TransitionFade::create(1, GameMenu::createScene(), Color3B::BLACK));
}
void World::createEnemy(float time)
{
    int rand1=CCRANDOM_0_1()*10;
    int type1=0;
    char* name;
    
    if(rand1>=0&&rand1<=2)
    {
        name="enemy_bug.png";
        type1=0;
    }
    if(rand1>=3&&rand1<=6)
    {
        name="enemy_duck.png";
        type1=1;
    }
    if(rand1>=7&&rand1<=10)
    {
        name="enemy_pig.png";
        type1=2;
    }
    Enemy* enemy=Enemy::createEnemy(name, type1);
    arrayEnemy.pushBack(enemy);
    this->addChild(enemy,1);
}
