#include "GameBoard.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameBoard::createScene()
{
    auto scene = Scene::create();
    auto layer = GameBoard::create();
    scene->addChild(layer);
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameBoard::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    auto winSize = glview->getDesignResolutionSize();

    auto back=Sprite::create("")

    return true;
}


void GameBoard::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}