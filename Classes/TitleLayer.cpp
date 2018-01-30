//
//  TitleLayer.cpp
//  Cocos2dxSpriteTest
//
//  Created by Hata on 2018/01/30.
//

#include "TitleLayer.hpp"
#include "GameLayer.hpp"

using namespace cocos2d;

bool TitleLayer::init()
{
    CCSprite* pBackground = CCSprite::create("background.png");
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    pBackground->setPosition(ccp(winSize.width / 2, winSize.height / 2));
    addChild(pBackground);

    showToGameLayerButton();

    return true;
}

CCScene* TitleLayer::createScene()
{
    CCScene* pScene = CCScene::create();
    TitleLayer* pLayer = TitleLayer::create();
    pScene->addChild(pLayer);
    return pScene;
}

void TitleLayer::toGameLayerCallback(cocos2d::CCObject *pSender)
{
    CCScene* scene = GameLayer::createScene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionFadeTR::create(2.0f, scene));
}

void TitleLayer::showToGameLayerButton()
{
    CCMenuItemLabel * pToGameLayerLabel = CCMenuItemFont::create("ゲームシーンへ", this, menu_selector(TitleLayer::toGameLayerCallback));
    CCMenu* pMenu = CCMenu::create(pToGameLayerLabel, NULL);

    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    pMenu->setPosition(ccp(winSize.width * 0.5, winSize.height * 0.3));
    addChild(pMenu);
}
