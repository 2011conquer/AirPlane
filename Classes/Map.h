//
//  Map.h
//  Game
//
//  Created by Mr.Chen on 14-6-5.
//
//

#ifndef __Game__Map__
#define __Game__Map__

#include <iostream>
#include "cocos2d.h"
class GameMap : public cocos2d::Layer
{
public:
    
    static GameMap* create(char* mapName);
    
    virtual bool initWithMap(char* mapName);
    
    void update(float time);
    
};
#endif /* defined(__Game__Map__) */
