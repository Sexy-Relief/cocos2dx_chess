#pragma once
#include "cocos2d.h"

//StartScene is just a layer
class StartScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);

    void onClickStart(Ref* object);
};