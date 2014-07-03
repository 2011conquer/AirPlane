//
//  Enemy.cpp
//  Game
//
//  Created by Mr.Chen on 14-6-6.
//
//

#include "Enemy.h"
#include "World.h"
USING_NS_CC;
Enemy* Enemy::createEnemy(char* name,int type)
{
    Enemy *pRet = new Enemy();
    if (pRet && pRet->initWithFile(name))
    {
        pRet->init(name,type);
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}
bool Enemy::init(char* name,int type)
{
    isActed=false;
    this->type=type;
    createAnimate(name, 10);
    Size si=Director::getInstance()->getWinSize();
    if(type==0){scoreValue=50;}
    else if(type==1){scoreValue=100;}
    else if(type==2){scoreValue=200;}
    
    this->setPosition(Point(CCRANDOM_0_1()*si.width, si.height+this->getContentSize().height));
    
    this->scheduleUpdate();
    
    return true;
}
void Enemy::update(float time)
{
    switch (type)
    {
        case 0:
        {
            this->setPosition(this->getPosition()+Point(0, -3));
            break;
        }
        case 1:
        {
            if(isActed){break;}
            isActed=true;
            this->runAction(Sequence::create(MoveTo::create(0.8, World::getWorldScene()->getPlayer()->getPosition()),DelayTime::create(1),MoveTo::create(0.6, this->getPosition()), NULL));
            break;
        }
        case 2:
        {
            this->setPosition(this->getPosition()+Point(CCRANDOM_0_1()*10-5, -3));
            break;
        }
    }
    
    if(this->getPositionY()<-this->getContentSize().height)
    {
        this->getParent()->removeChild(this,true);
        World::getWorldScene()->getEnemyArray().eraseObject(this);
    }
    Player* player=World::getWorldScene()->getPlayer();
    if(!player->isDead)
    {
        if(player->boundingBox().intersectsRect(this->boundingBox()))
        {
            player->downHp();
        }
    }
}
//怪物的动态效果
void Enemy::createAnimate(char* name,int allCount)
{
    Animation* animation=Animation::create();
    Texture2D* texture=Director::getInstance()->getTextureCache()->addImage(name);
    
    int each=this->getContentSize().width/allCount;
    for(int i=0;i<allCount;i++)
    {
        animation->addSpriteFrameWithTexture(texture, Rect(i*each, 0, each, this->getContentSize().height));
    }
    animation->setDelayPerUnit(0.5);//
    animation->setRestoreOriginalFrame(true);
    animation->setLoops(-1);//重复次数。。。。-1为无线循环
    FiniteTimeAction* animate=Animate::create(animation);
    this->runAction(animate);
}





