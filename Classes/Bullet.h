//
//  Bullet.h
//  Game
//
//  Created by Mr.Chen on 14-6-5.
//
//

#ifndef __Game__Bullet__
#define __Game__Bullet__

#include <iostream>
#include "cocos2d.h"
#include "Player.h"
#include "Enemy.h"

class Bullet : public cocos2d::Sprite
{
public:
    static Bullet* create();
    virtual bool init();

    void update(float time);
};
#endif /* defined(__Game__Bullet__) */
