//
//  TitleLayer.hpp
//  Cocos2dxSpriteTest
//
//  Created by Hata on 2018/01/30.
//

#ifndef TitleLayer_hpp
#define TitleLayer_hpp

#include "cocos2d.h"

class TitleLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    CREATE_FUNC(TitleLayer);
    static cocos2d::CCScene* createScene();
private:
    void toGameLayerCallback(cocos2d::CCObject *pSender);
    void showToGameLayerButton();
};

#endif /* TitleLayer_hpp */
