//
//  GameLayer.cpp
//  Cocos2dxSpriteTest
///Users/Hata/projects/cocos2d-x-2.2.6/projects/Cocos2dxSpriteTest/Classes/GameLayer.cpp
//  Created by Hata on 2018/01/24.
//

#include "GameLayer.hpp"
#include "TitleLayer.hpp"
#include "Card.hpp"
#include "ParticleGenerator.hpp"

const float CARD_MOVE_SPEED = 0.5f;
const char* BACKGROUND_PNG = "background.png";
const char* CARDS_PLIST = "cards.plist";
const char* CARDS_PNG = "cards.png";


using namespace cocos2d;

bool GameLayer::init()
{
    m_touching = false;

    m_cardPngArray.push_back("c01.png");
    m_cardPngArray.push_back("c02.png");
    m_cardPngArray.push_back("c03.png");
    m_cardPngArray.push_back("c04.png");
    m_cardPngArray.push_back("c05.png");
    m_cardPngArray.push_back("c06.png");
    m_cardPngArray.push_back("c07.png");
    m_cardPngArray.push_back("c08.png");
    m_cardPngArray.push_back("c09.png");
    m_cardPngArray.push_back("c10.png");
    m_cardPngArray.push_back("c11.png");
    m_cardPngArray.push_back("c12.png");
    m_cardPngArray.push_back("c13.png");
    m_cardPngArray.push_back("d01.png");
    m_cardPngArray.push_back("d02.png");
    m_cardPngArray.push_back("d03.png");
    m_cardPngArray.push_back("d04.png");
    m_cardPngArray.push_back("d05.png");
    m_cardPngArray.push_back("d06.png");
    m_cardPngArray.push_back("d07.png");
    m_cardPngArray.push_back("d08.png");
    m_cardPngArray.push_back("d09.png");
    m_cardPngArray.push_back("d10.png");
    m_cardPngArray.push_back("d11.png");
    m_cardPngArray.push_back("d12.png");
    m_cardPngArray.push_back("d13.png");
    m_cardPngArray.push_back("h01.png");
    m_cardPngArray.push_back("h02.png");
    m_cardPngArray.push_back("h03.png");
    m_cardPngArray.push_back("h04.png");
    m_cardPngArray.push_back("h05.png");
    m_cardPngArray.push_back("h06.png");
    m_cardPngArray.push_back("h07.png");
    m_cardPngArray.push_back("h08.png");
    m_cardPngArray.push_back("h09.png");
    m_cardPngArray.push_back("h10.png");
    m_cardPngArray.push_back("h11.png");
    m_cardPngArray.push_back("h12.png");
    m_cardPngArray.push_back("h13.png");
    m_cardPngArray.push_back("s01.png");
    m_cardPngArray.push_back("s02.png");
    m_cardPngArray.push_back("s03.png");
    m_cardPngArray.push_back("s04.png");
    m_cardPngArray.push_back("s05.png");
    m_cardPngArray.push_back("s06.png");
    m_cardPngArray.push_back("s07.png");
    m_cardPngArray.push_back("s08.png");
    m_cardPngArray.push_back("s09.png");
    m_cardPngArray.push_back("s10.png");
    m_cardPngArray.push_back("s11.png");
    m_cardPngArray.push_back("s12.png");
    m_cardPngArray.push_back("s13.png");

    // スプライトアトラスをキャッシュしておく.
    CCSpriteFrameCache* pCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    pCache->addSpriteFramesWithFile(CARDS_PLIST, CARDS_PNG);

    CCSize winSize = CCDirector::sharedDirector()->getWinSize();

    // 背景画像の表示.
    CCSprite* pBackground = CCSprite::create(BACKGROUND_PNG);
    pBackground->setPosition(ccp(winSize.width / 2, winSize.height / 2));
    addChild(pBackground, zBackground);

//    // 以下、トランプ全体表示用のtmpコード.
//    CCSprite* pTmpCard = CCSprite::createWithSpriteFrameName("c01.png");
//
//    float xOffset = pTmpCard->getContentSize().width * 1.1f;
//    float yOffset = pTmpCard->getContentSize().height * 0.3f;
//
//    float xBase = winSize.width  * 0.5f - xOffset * 3;
//    float yBase = winSize.height * 0.82f;
//
//    int xCardNum = 5;
//    int yCardNum = 7;
//
//    int curIndex = 0;
//    for (int y = 0; y < yCardNum; y++) {
//        for (int x = 0; x < xCardNum; x++) {
//            // TODO 本番コードでは、委譲で保持するか・タグ採番するかして管理すること.
//            CCSprite* pCard = CCSprite::createWithSpriteFrameName(m_cardPngArray[curIndex]);
//            CCPoint position = ccp(xBase + (xOffset + 0.5) * y, yBase - (yOffset + 0.5) * x);
//            pCard->setPosition(position);
//            addChild(pCard, zCard);
//            curIndex++;
//        }
//    }
    
    Card* pCard = Card::createWithNumAndSuit(13, Card::spade);
    pCard->setPosition(ccp(winSize.width / 2, winSize.height / 2));
    addChild(pCard, 5, 100);

    // その他メニュー等.
    showToTitleLayerButton();
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

    // カード1枚をタッチした箇所に動かす.
    CCPoint movePoint = convertTouchToNodeSpace(pTouch);
    CCMoveTo* pMoveTo = CCMoveTo::create(CARD_MOVE_SPEED, movePoint);
    Card* pCard = (Card*)getChildByTag(100);
    pCard->runAction(pMoveTo);

    // カード1枚をタッチした箇所に動かす(CCCallFuncNDを使う場合).
//    m_cardMovePoint = convertTouchToNodeSpace(pTouch);
//    CCCallFuncND* pMoveFunc = CCCallFuncND::create(this, callfuncND_selector(GameLayer::moveSprite), (void*)&m_cardMovePoint);
//    Card* pCard = (Card*)getChildByTag(100);
//    pCard->runAction(pMoveFunc);

    m_touching = true;
    return true;
}

void GameLayer::ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent)
{
    m_touching = false;
}

void GameLayer::toTitleLayerCallback(cocos2d::CCObject *pSender)
{
    CCScene* scene = TitleLayer::createScene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionFadeBL::create(2.0f, scene));
}

void GameLayer::showToTitleLayerButton()
{
    CCMenuItemLabel * pToTitleLayerLabel = CCMenuItemFont::create("タイトルシーンへ", this, menu_selector(GameLayer::toTitleLayerCallback));
    CCMenu* pMenu = CCMenu::create(pToTitleLayerLabel, NULL);
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    pMenu->setPosition(ccp(winSize.width * 0.85f, winSize.height * 0.2f));
    addChild(pMenu);
}

void GameLayer::moveSprite(CCNode* node, void* moveTo)
{
    CCPoint* pos = static_cast<CCPoint*>(moveTo);
    CCLog("%s :2 x:%f y:%f",__PRETTY_FUNCTION__, pos->x, pos->y);
    node->setPosition(*pos);
}
