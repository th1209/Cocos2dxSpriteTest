//
//  GameLayer.hpp
//  Cocos2dxSpriteTest
//
//  Created by Hata on 2018/01/24.
//

#ifndef GameLayer_h
#define GameLayer_h

#include "cocos2d.h"
#include "Card.hpp"

class GameLayer : public cocos2d::CCLayer
{
public:
    // 初期化処理.
    virtual bool init();

    // 自インスタンス生成.
    CREATE_FUNC(GameLayer);

    // 自Layer & Scene作成用メソッド.
    static cocos2d::CCScene* createScene();

    // シーン切替時に呼ばれる処理.
    virtual void onEnter();
    virtual void onExit();
    
    
    bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
    
    void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);

    void moveSprite(CCNode* node, void* moveTo);

private:
    void toTitleLayerCallback(cocos2d::CCObject *pSender);
    void showToTitleLayerButton();
    void initCards();
    std::vector<Card*> getCards();

    enum childTag
    {
        tagParticleGenerator
    };

    enum childZOrder
    {
        zBackground,
        zCard,
    };

    bool m_touching;
    cocos2d::CCPoint m_cardMovePoint;
    std::vector<const char*> m_cardPngArray;
    std::vector<int> m_cardTags;
};

#endif /* GameLayer_hpp */
