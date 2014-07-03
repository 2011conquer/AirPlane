//
//  Enemy.h
//  Game
//
//  Created by Mr.Chen on 14-6-6.
//
//

#ifndef __Game__Enemy__
#define __Game__Enemy__

#include <iostream>
#include "cocos2d.h"
class Enemy : public cocos2d::Sprite
{
public:
    
    int type;
    int scoreValue;
    bool isActed;
    
    static Enemy* createEnemy(char* name,int type);
    virtual bool init(char* name,int type);
    
    void createAnimate(char* name,int allCount);
    
    void update(float time);
    
};
#endif /* defined(__Game__Enemy__) */
