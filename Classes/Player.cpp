//
//  Player.cpp
//  Game
//
//  Created by Mr.Chen on 14-6-5.
//
//

#include "Player.h"
#include "World.h"
USING_NS_CC;
Player* Player::create()
{
    Player *pRet = new Player();
    if (pRet && pRet->initWithFile("player.png"))
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
bool Player::init()
{
    Size visible = Director::getInstance()->getVisibleSize();
    
    this->setPosition(Point(visible.width/2, this->getContentSize().height/2));
    a=0;
    hpMax=3;
    hp=3;
    score=0;
    strongTime=2*60;
    isStrong=false;
    //添加血量
    for(int i=0;i<3;i++)
    {
        Sprite* spHp=Sprite::create("icon_hp.png");
        spHp->setPosition(Point(visible.width-this->getContentSize().width*0.5*i-20, spHp->getContentSize().height/2));
        if(i==0){spHp->setTag(10);}
        if(i==1){spHp->setTag(11);}
        if(i==2){spHp->setTag(12);}
        World::getWorldScene()->addChild(spHp,10);
    }
    
    //初始化"分数"文字加入layer中
    Label* label=Label::createWithSystemFont("分数:", "Helvetica-Blod", 24);
    label->setPosition(Point(30, visible.height-22));
    World::getWorldScene()->addChild(label,10);
    
    //分数数字加入layer中
    std::string strScore=Convert2String(score);
    Label* labelScore=Label::createWithSystemFont(strScore.c_str(), "Helvetica-Blod", 24);
    labelScore->setPosition(Point(110, visible.height-22));
    labelScore->setColor(Color3B::GREEN);
    World::getWorldScene()->addChild(labelScore,10,tag_Score);
    
    //”杀敌“文字
    Label* labelKill=Label::createWithSystemFont("杀敌:","Helvetica-Blod", 24);
    labelKill->setPosition(Point(30, visible.height-52));
    World::getWorldScene()->addChild(labelKill,10);
    
    //杀敌数量
    std::string strKillCount=Convert2String(killCount);
    Label* labelKillCount=Label::createWithSystemFont(strKillCount.c_str(),"Helvetica-Blod", 24);
    labelKillCount->setPosition(Point(110, visible.height-52));
    labelKillCount->setColor(Color3B::ORANGE);
    World::getWorldScene()->addChild(labelKillCount,10,tag_KillCount);
    //
    auto listener=EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan=[](Touch* touch,Event* event)
    {
        auto tager=static_cast<Sprite*>(event->getCurrentTarget());
        Point pos=tager->convertToNodeSpace(touch->getLocation());
        Size siz=tager->getContentSize();
        Rect re=Rect(0, 0, siz.width, siz.height);
        if(re.containsPoint(pos))
        {
            return true;
        }
        return false;
    };
    listener->onTouchMoved=[=](Touch* touch,Event* event)
    {
        auto tager=static_cast<Sprite*>(event->getCurrentTarget());
        tager->setPosition(tager->getPosition()+touch->getDelta());
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    this->scheduleUpdate();
    return true;
}
void Player::addScore(float _value)
{
    score+=_value;
    std::string str=Convert2String(score);
    Label* lab=(Label*)World::getWorldScene()->getChildByTag(tag_Score);
    lab->setString(str.c_str());
}
void Player::addKillCount(float _value)
{
    killCount+=_value;
    std::string str=Convert2String(killCount);
    str+="/100";
    Label* lab=(Label*)World::getWorldScene()->getChildByTag(tag_KillCount);
    lab->setString(str.c_str());
    if(killCount>=100)
    {
        int oldScore=atoi(UserDefault::getInstance()->getStringForKey("user_score","-1").c_str());
        if(score>oldScore)
        {
            UserDefault::getInstance()->setStringForKey("user_score", Convert2String(score));
            UserDefault::getInstance()->flush();
        }
        //调用胜利界面
//        World::getWorldScene()->winGame();
    }
}
void Player::update(float time)
{
    //边界检测
    this->boundary();
}
void Player::downHp()
{
    if(isStrong)
    {
        return;
    }
    hp-=1;
    if(hp<=0)
    {
        this->setVisible(false);
        isDead=true;
        World::getWorldScene()->removeChildByTag(10);
        int oldScore=atoi(UserDefault::getInstance()->getStringForKey("user_score").c_str());
        if(score>oldScore)
        {
            UserDefault::getInstance()->setStringForKey("user_score", Convert2String(score));
            UserDefault::getInstance()->flush();
        }
        //调用失败界面
//        World::getWorldScene()->lostGame();
    }
    else
    {
      switch (hp)
        {
            case 2:
                World::getWorldScene()->removeChildByTag(12);
                break;
            case 1:
                World::getWorldScene()->removeChildByTag(11);
                break;
        }
    }
    isStrong=true;
    strongCount=0;
    this->schedule(schedule_selector(Player::strongIn));
}
void Player::strongIn(float dt)
{
    strongCount++;
    if(strongCount%strongTime==0)
    {
        this->setVisible(true);
        isStrong=false;
        this->unschedule(schedule_selector(Player::strongIn));
    }
    else
    {
        if(strongCount%3==0){this->setVisible(false);}
        else{this->setVisible(true);}
    }
}
void Player::boundary()
{
    Point pos=this->getPosition();
    Size si=this->getContentSize();
    Size vis=Director::getInstance()->getVisibleSize();
    if(pos.x>=(vis.width-si.width/2))
    {
        this->setPosition(Point(vis.width-si.width/2, pos.y));
    }
    else if(pos.x<=si.width/2)
    {
        this->setPosition(Point(si.width/2, pos.y));
    }
    else if(pos.y>=(vis.height-si.height/2))
    {
        this->setPosition(Point(pos.x, vis.height-si.height/2));
    }
    else if(pos.y<=si.height/2)
    {
        this->setPosition(Point(pos.x, si.height/2));
    }

}





