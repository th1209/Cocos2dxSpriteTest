//
//  ParticleGenerator.hpp
//  Cocos2dxSpriteTest
//
//  Created by Hata on 2018/01/29.
//

#ifndef ParticleGenerator_hpp
#define ParticleGenerator_hpp

#include "cocos2d.h"

class ParticleGenerator : public cocos2d::CCNode
{
public:
    enum ParticleType{
        boxelRed,
        boxelGreen,
        boxelBlue,
        boxelOrange,
        particleCount,
    };

    virtual bool init();
    CREATE_FUNC(ParticleGenerator);

    void generate(const float x, const float y, ParticleType pType);
    void generate(const cocos2d::CCPoint& point, ParticleType pType);
    void generateRandomly(const float x, const float y);
    void generateRandomly(const cocos2d::CCPoint& point);

private:
    std::map<ParticleType, char*> m_plistMap;
    char* getPlistFileName(ParticleType pType);
};

#endif /* ParticleGenerator_hpp */
