#ifndef Card_h
#define Card_h

#include "PokerParameters.h"

class Card
{
public:
   Card();
   Card(int cardval, PokerParameters::CARDSUITS cardtype);
   ~Card();

   void setCardValue(int val);
   int getCardValue();

   void setCardSuit(PokerParameters::CARDSUITS type);
   PokerParameters::CARDSUITS getCardSuit();

   void PrintCard();

private:
   int value = 0;
   PokerParameters::CARDSUITS suit = PokerParameters::CARDSUITS::NOSUIT;
};

#endif