//
//  World.h
//  Game
//
//  Created by Mr.Chen on 14-6-5.
//
//

#ifndef __Game__World__
#define __Game__World__

#include <iostream>
#include "cocos2d.h"
#include "Map.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
typedef enum
{
    tag_Score=1,
    tag_KillCount,
} Tag;
class World : public cocos2d::Layer
{
public:
    
    int num;
    Vector<Sprite*> arrayEnemy;
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(World);
    static World* getWorldScene();
    Player* getPlayer();
    Vector<Sprite*> getEnemyArray();
    void createBullet(float time);
    void winGame();
    void lostGame();
    void backMenu(Ref* ref);
    void createEnemy(float time);
    
    
};
#endif /* defined(__Game__World__) */
