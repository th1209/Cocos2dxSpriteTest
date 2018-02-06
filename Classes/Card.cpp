//
//  Card.cpp
//  Cocos2dxSpriteTest
//
//  Created by Hata on 2018/02/02.
//

#include "Card.hpp"

using namespace std;
using namespace cocos2d;

const int CARD_NUM_MIN = 1;
const int CARD_NUM_MAX = 13;

// 他のオブジェクトと番号が被らないようにするための番号.
const int CARD_TAG_NUMBER = 100000;

vector<Card::Suit> Card::getSuits()
{
    vector<Card::Suit> suits;
    suits.push_back(club);
    suits.push_back(dia);
    suits.push_back(heart);
    suits.push_back(spade);

    return suits;
}

vector<int> Card::getNumbers()
{
    vector<int> numbers;
    for (int i = CARD_NUM_MIN; i <= CARD_NUM_MAX; ++i)
    {
        numbers.push_back(i);
    }

    return numbers;
}

Card* Card::createWithNumAndSuit(int num, Suit suit)
{
    Card* pCard = new Card();
    if (pCard && pCard->initWithNumAndSuit(num, suit))
    {
        pCard->autorelease();
        return pCard;
    }
    else
    {
        CC_SAFE_DELETE(pCard);
        return NULL;
    }
}

Card::~Card()
{
    
}

bool Card::initWithNumAndSuit(int num, Suit suit)
{
    m_number = num;
    m_suit = suit;

    CCAssert(num >= CARD_NUM_MIN && num <= CARD_NUM_MAX, "invalid number.");
    
    map<Suit, string> suitMap;
    suitMap[club]  = "c";
    suitMap[dia]   = "d";
    suitMap[heart] = "h";
    suitMap[spade] = "s";
    
    char buffer[256];
    CCAssert(sprintf(buffer, "%02d", num) > 0, "failed to sprintf.");
    
    string fileName = suitMap[suit] + buffer + ".png";
    CCAssert(CCSprite::initWithSpriteFrameName(fileName.c_str()), "failed to initWithFile");

    return true;
}

bool Card::isTouched(cocos2d::CCPoint touchPoint)
{
    CCPoint pos = this->getPosition();
    int w = this->getContentSize().width;
    int h = this->getContentSize().height;
    CCRect rect = CCRectMake(pos.x - (w/2), pos.y - (h/2), w, h);
    return rect.containsPoint(touchPoint);
}

int Card::getTag()
{
    return CARD_TAG_NUMBER + m_number * 100 + (int)m_suit;
}
