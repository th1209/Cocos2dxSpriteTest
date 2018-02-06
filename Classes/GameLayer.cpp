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
const float CARD_MOVE_POS_X = 800.0f;
const float CARD_MOVE_POS_Y = 150.0f;

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

    // カード画像の表示.
    initCards();

    // その他メニュー等.
    showToTitleLayerButton();
    return true;
}

void GameLayer::initCards()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSprite* pTmpCard = CCSprite::createWithSpriteFrameName("c01.png");
    
    float xOffset = pTmpCard->getContentSize().width * 1.1f;
    float yOffset = pTmpCard->getContentSize().height * 0.3f;
    
    float xBase = winSize.width  * 0.5f - xOffset * 3;
    float yBase = winSize.height * 0.82f;
    
    int xCardNum = 5;
    int yCardNum = 7;
    int cardMax = xCardNum * yCardNum;
    int curIndex = 0;

    std::vector<Card::Suit> suits = Card::getSuits();
    std::vector<int> numbers      = Card::getNumbers();

    std::vector<Card::Suit>::iterator suitIt = suits.begin();
    while (suitIt != suits.end())
    {
        std::vector<int>::iterator numberIt = numbers.begin();
        while (numberIt != numbers.end())
        {
            Card* pCard = Card::createWithNumAndSuit((*numberIt), (*suitIt));
            CCPoint position = ccp(xBase + (xOffset + 0.5) * (int)(curIndex / 5), yBase - (yOffset + 0.5) * (int)(curIndex % 5));
            pCard->setPosition(position);
            int cardTag = pCard->getTag();
            addChild(pCard, zCard, cardTag);
            m_cardTags.push_back(cardTag);
            
            curIndex++;
            if (curIndex == cardMax)
            {
                return;
            }

            numberIt++;
        }
        suitIt++;
    }
    
    return;
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

    CCPoint touchPoint = convertTouchToNodeSpace(pTouch);
    CCMoveTo* pMoveTo = CCMoveTo::create(CARD_MOVE_SPEED, ccp(CARD_MOVE_POS_X, CARD_MOVE_POS_Y));
    std::vector<Card*> cards = getCards();
    std::vector<Card*>::iterator it = cards.begin();
    while (it != cards.end())
    {
        if ((*it)->isTouched(touchPoint))
        {
            (*it)->runAction(pMoveTo);
            break;
        }
        it++;
    }

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
    node->setPosition(*pos);
}

std::vector<Card*> GameLayer::getCards()
{
    std::vector<Card*> cards;
    std::vector<int>::iterator it = m_cardTags.begin();
    while (it != m_cardTags.end())
    {
        Card* pCard = (Card*)getChildByTag(*it);
        cards.push_back(pCard);
        it++;
    }
    return cards;
}
