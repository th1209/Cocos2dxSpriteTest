//
//  ParticleGenerator.cpp
//  Cocos2dxSpriteTest
//
//  Created by Hata on 2018/01/29.
//

#include "ParticleGenerator.hpp"
#include "cocos2d.h"

using namespace cocos2d;

bool ParticleGenerator::init()
{
    srand((unsigned)time(NULL));

    m_plistMap[boxelRed]    = "particle_boxel_red.plist";
    m_plistMap[boxelGreen]  = "particle_boxel_green.plist";
    m_plistMap[boxelBlue]   = "particle_boxel_blue.plist";
    m_plistMap[boxelOrange] = "particle_boxel_orange.plist";

    return true;
}

void ParticleGenerator::generate(const float x, const float y, ParticleType pType)
{
    char* plistName = getPlistFileName(pType);
    CCParticleSystemQuad* pParticle = CCParticleSystemQuad::create(plistName);
    pParticle->setAutoRemoveOnFinish(true);
    pParticle->resetSystem();
    pParticle->setPosition(x, y);
    addChild(pParticle);
}

void ParticleGenerator::generate(const cocos2d::CCPoint& point, ParticleType pType)
{
    generate(point.x, point.y, pType);
}

void ParticleGenerator::generateRandomly(const float x, const float y)
{
    generate(x, y, (ParticleType)(rand() % particleCount));
}

void ParticleGenerator::generateRandomly(const cocos2d::CCPoint& point)
{
    generate(point.x, point.y, (ParticleType)(rand() % particleCount));
}

char* ParticleGenerator::getPlistFileName(ParticleType pType)
{
    CCAssert(m_plistMap.find(pType) != m_plistMap.end(), "pType is invalid.");
    return m_plistMap[pType];
}
