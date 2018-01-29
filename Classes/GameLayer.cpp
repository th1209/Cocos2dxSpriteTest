//
//  GameLayer.cpp
//  Cocos2dxSpriteTest
///Users/Hata/projects/cocos2d-x-2.2.6/projects/Cocos2dxSpriteTest/Classes/GameLayer.cpp
//  Created by Hata on 2018/01/24.
//

#include "GameLayer.hpp"

const char* CARDS_PLIST = "cards.plist";
const char* CARDS_PNG = "cards.png";

using namespace cocos2d;

bool GameLayer::init()
{
    // スプライトアトラスをキャッシュしておく.
    CCSpriteFrameCache* pCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    pCache->addSpriteFramesWithFile(CARDS_PLIST, CARDS_PNG);

    // 試しに表示.
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSprite* pTestCard = CCSprite::createWithSpriteFrameName("c01.png");
    pTestCard->setPosition(ccp(winSize.width / 2, winSize.height / 2));
    addChild(pTestCard);

    return true;
}

cocos2d::CCScene* GameLayer::createScene()
{
    CCScene* pScene = CCScene::create();
    GameLayer* pLayer = GameLayer::create();
    pScene->addChild(pLayer);
    return pScene;
}
