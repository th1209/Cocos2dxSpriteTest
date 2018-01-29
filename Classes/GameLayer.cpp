//
//  GameLayer.cpp
//  Cocos2dxSpriteTest
///Users/Hata/projects/cocos2d-x-2.2.6/projects/Cocos2dxSpriteTest/Classes/GameLayer.cpp
//  Created by Hata on 2018/01/24.
//

#include "GameLayer.hpp"
#include "ParticleGenerator.hpp"

const char* CARDS_PLIST = "cards.plist";
const char* CARDS_PNG = "cards.png";

using namespace cocos2d;

bool GameLayer::init()
{
    m_touching = false;

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

void GameLayer::onEnter()
{
    CCNode::onEnter();

    ParticleGenerator* pParticleGenerator = ParticleGenerator::create();
    pParticleGenerator->setTag(tagParticleGenerator);
    addChild(pParticleGenerator);

    // タッチを有効化する.
    setTouchEnabled(true);
    setTouchMode(kCCTouchesOneByOne);
}

void GameLayer::onExit()
{
    CCNode::onExit();

    setTouchEnabled(false);
}

bool GameLayer::ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent)
{
    if (m_touching)
        return false;

    ParticleGenerator* pParticleGenerator = (ParticleGenerator*)getChildByTag(tagParticleGenerator);
    pParticleGenerator->generateRandomly(convertTouchToNodeSpace(pTouch));

    m_touching = true;
    return true;
}

void GameLayer::ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent)
{
    m_touching = false;
}
