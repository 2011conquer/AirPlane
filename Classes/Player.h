//
//  Player.h
//  Game
//
//  Created by Mr.Chen on 14-6-5.
//
//

#ifndef __Game__Player__
#define __Game__Player__

#include "sstream"
#include <iostream>
#include "cocos2d.h"
using namespace std;
using namespace cocos2d;

template <typename T>
string Convert2String(const T &value)
{
    stringstream ss;
    ss<<value;
    return ss.str();
};

class Player : public cocos2d::Sprite
{
public:
    
    int hpMax;
    int hp;
    int score;
    int strongTime;
    bool isStrong;
    int strongCount;
    int killCount;
    bool isDead;
    float a=0;
    
    void addScore(float _value);
    void addKillCount(float _value);
    void update(float time);
    void downHp();
    void strongIn(float dt);
    void boundary();
    
    static Player* create();
    virtual bool init();
};

#endif /* defined(__Game__Player__) */
