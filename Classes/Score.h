//
//  Score.h
//  Game
//
//  Created by Mr.Chen on 14-6-5.
//
//

#ifndef __Game__Score__
#define __Game__Score__

#include <iostream>
#include "cocos2d.h"

class Score : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(Score);
    void backMenu(Ref* ref);
};

#endif /* defined(__Game__Score__) */
