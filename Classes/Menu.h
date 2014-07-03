//
//  Menu.h
//  Game
//
//  Created by Mr.Chen on 14-6-5.
//
//

#ifndef __Game__Menu__
#define __Game__Menu__

#include <iostream>
#include "cocos2d.h"
#include "Map.h"
#include "World.h"
#include "Score.h"
#include "About.h"

class GameMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameMenu);
    
    void playGame(Ref* ref);
    void scoreGame(Ref* ref);
    void aboutGame(Ref* ref);
};
#endif /* defined(__Game__Menu__) */
