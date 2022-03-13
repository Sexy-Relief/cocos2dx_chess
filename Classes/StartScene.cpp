#include "StartScene.h"
#include "GameBoard.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* StartScene::createScene()
{
    auto scene = Scene::create();
    auto layer = StartScene::create();
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
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    auto director = Director::getInstance();
    auto visibleSize = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();

    auto glview = director->getOpenGLView();
    //glview->setDesignResolutionSize(1280, 720, ResolutionPolicy::NO_BORDER);
    auto winSize = glview->getDesignResolutionSize();

    auto back = Sprite::create("back_black.png");
    back->setPosition(Point(winSize.width / 2, winSize.height / 2));
    this->addChild(back);

    auto title = Sprite::create("title.png");
    title->setAnchorPoint(Point(0.5f, 1));
    title->setPosition(Point(winSize.width/2, winSize.height - 50));
    this->addChild(title);

    auto main_knight = Sprite::create("main_knight.png");
    main_knight->setPosition(Point(winSize.width / 2, winSize.height / 2));
    this->addChild(main_knight);

    //auto button1 = MenuItemImage::create("title_button.jpg", "title_button_on.jpg", "title_button_dis.jpg", [&](Ref* sender) {exit(-1);});
    //button1->setEnabled(false);
    auto button1 = MenuItemImage::create("title_button.jpg", "title_button_on.jpg", "title_button_dis.jpg", CC_CALLBACK_1(StartScene::onClickStart,this));
    button1->setPosition(Point(winSize.width / 2, 80));

    auto menu = Menu::create(button1, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    auto to = title->getPosition();
    auto from = Point(to.x, to.y + 100);
    title->setPosition(from);

    //auto action = Sequence::create(MoveTo::create(0.5f, to), RotateTo::create(0.5f, 720), NULL);
    auto action = Spawn::create(MoveTo::create(0.5f, to), RotateTo::create(0.5f, 720), NULL);
    title->runAction(action);
    return true;
}


void StartScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void StartScene::onClickStart(Ref* object) {
    log("onClickStart");
    auto Scene = TransitionFlipX::create(0.5f,GameBoard::createScene());
    Director::getInstance()->replaceScene(Scene);
}