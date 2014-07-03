//
//  Bullet.cpp
//  Game
//
//  Created by Mr.Chen on 14-6-5.
//
//

#include "Bullet.h"
#include "World.h"
USING_NS_CC;
Bullet* Bullet::create()
{
    Bullet *pRet = new Bullet();
    if (pRet && pRet->initWithFile("p_bullet.png"))
    {
        pRet->init();
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
bool Bullet::init()
{
    this->scheduleUpdate();
    return true;
}
void Bullet::update(float time)
{
    //移动子弹
    this->setPosition(this->getPosition()+Point(0, 5));
    //边界
    if(this->getPosition().y>Director::getInstance()->getVisibleSize().height)
    {
        World::getWorldScene()->removeChild(this,true);
    }
    //获得怪物数组
    Vector<Sprite*> array=World::getWorldScene()->getEnemyArray();
    //碰撞检测
    for(int i=0; i<array.size();i++)
    {
        Enemy* ene=(Enemy*)array.at(i);
        if(ene->boundingBox().intersectsRect(this->boundingBox()))
        {
            //移除怪物和子弹
            World::getWorldScene()->removeChild(ene,true);
            array.eraseObject(ene);
            World::getWorldScene()->removeChild(this,true);
            //添加粒子效果
            ParticleSystemQuad* particle=ParticleSystemQuad::create("particle_boom.plist");
            particle->setPosition(ene->getPosition());
            particle->setAutoRemoveOnFinish(true);
            World::getWorldScene()->addChild(particle);
            //添加分数和杀敌数
            World::getWorldScene()->getPlayer()->addScore(ene->scoreValue);
            World::getWorldScene()->getPlayer()->addKillCount(1);
            break;
        }
    }
    
}


