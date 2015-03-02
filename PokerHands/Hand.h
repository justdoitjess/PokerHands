#ifndef Hand_h
#define Hand_h
#include "Card.h"
#include <vector>

class Hand
{
public:
   Hand(Card card1, Card card2, Card card3, Card card4, Card card5);
   Hand(std::vector<Card> handOfCards);
   ~Hand();

   void AddCardToHand(Card cardToAdd);
   std::vector<Card> GetHand();

   void EvaluateRank();
   PokerParameters::HANDRANKS GetHandRank();

   Card getRankingHighCard();
   void SetRankingHighCard(Card highCard);

   Card getNonRankingHighCard();
   void SetNonRankingHighCard(Card highCard);

   void DisplayHand();

private:
   bool CompareCards(Card &card1, Card &card2);
   void SortHandOfCards();

   std::vector<Card> theHand;
   PokerParameters::HANDRANKS theRank = PokerParameters::HANDRANKS::NORANK;
   Card rankingHighCard;
   Card nonRankingHighCard;

   //Poker Rules to Implement
   bool isAOnePair();
   bool isATwoPair( );
   bool isAThreeOfAKind( );
   bool isAStraight( );
   bool isAFlush( );
   bool isAFullHouse( );
   bool isAFourOfAKind( );
   bool isAStraightFlush( );
};

#endif