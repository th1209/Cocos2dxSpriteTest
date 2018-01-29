//
//  GameLayer.hpp
//  Cocos2dxSpriteTest
//
//  Created by Hata on 2018/01/24.
//

#ifndef GameLayer_h
#define GameLayer_h

extern const char* CARDS_PLIST;
extern const char* CARDS_PNG;

#include "cocos2d.h"

class GameLayer : public cocos2d::CCLayer
{
public:
    // 初期化処理.
    virtual bool init();

    // 自インスタンス生成.
    CREATE_FUNC(GameLayer);

    // 自Layer & Scene作成用メソッド.
    static cocos2d::CCScene* createScene();
};

#endif /* GameLayer_hpp */
