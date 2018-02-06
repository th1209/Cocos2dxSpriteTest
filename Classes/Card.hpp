//
//  Card.hpp
//  Cocos2dxSpriteTest
//
//  Created by Hata on 2018/02/02.
//

#ifndef Card_hpp
#define Card_hpp

#include "cocos2d.h"

class Card : public cocos2d::CCSprite
{
public:
    enum Suit
    {
        club,
        dia,
        heart,
        spade,
    };
    static std::vector<Suit> getSuits();
    static std::vector<int> getNumbers();

    static Card* createWithNumAndSuit(int num, Card::Suit suit);
    // このデストラクタは必ず必要.
    // https://stackoverflow.com/questions/15265106/c-a-missing-vtable-error
    virtual ~Card();

    bool isTouched(cocos2d::CCPoint touchPoint);
    int getTag();

protected:
    int m_number;
    Suit m_suit;

    virtual bool initWithNumAndSuit(int num, Card::Suit suit);
};

#endif /* Card_hpp */
