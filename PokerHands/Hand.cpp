#include "Hand.h"
#include "PokerHandRules.h"
#include <algorithm>
#include <iostream>

Hand::Hand(Card card1, Card card2, Card card3, Card card4, Card card5)
{
   AddCardToHand(card1);
   AddCardToHand(card2);
   AddCardToHand(card3);
   AddCardToHand(card4);
   AddCardToHand(card5);

   this->EvaluateRank();
}

Hand::Hand(std::vector<Card> handOfCards) : theHand(handOfCards)
{
   this->EvaluateRank();
}

Hand::~Hand()
{

}

void Hand::AddCardToHand(Card cardToAdd)
{
   this->theHand.push_back(cardToAdd);
}

std::vector<Card> Hand::GetHand()
{
   return this->theHand;
}

bool Hand::CompareCards(Card &card1, Card &card2)
{
   return card1.getCardValue() < card2.getCardValue();
}

void Hand::SortHandOfCards()
{
//   std::sort(this->theHand.begin(), this->theHand.end(), Hand::CompareCards);
}

PokerParameters::HANDRANKS Hand::GetHandRank()
{
   return this->theRank;
}

Card Hand::getRankingHighCard()
{
   return this->rankingHighCard;
}

void Hand::SetRankingHighCard(Card highCard)
{
   this->rankingHighCard = highCard;
}

Card Hand::getNonRankingHighCard()
{
   return this->nonRankingHighCard;
}

void Hand::SetNonRankingHighCard(Card highCard)
{
   this->nonRankingHighCard = highCard;
}

void Hand::DisplayHand()
{
   //print each card
   for (int i = 0; i < 5; i++)
   {
      this->theHand[i].PrintCard();
   }
   std::cout << "\n";
}

//Poker Rules
bool Hand::isAOnePair( )
{
   //c0 == c1 or c1 == c2 or c2 == c3 or c3 == c4
   if (this->GetHand()[0].getCardValue() == this->GetHand()[1].getCardValue() ||
      this->GetHand()[1].getCardValue() == this->GetHand()[2].getCardValue() ||
      this->GetHand()[2].getCardValue() == this->GetHand()[3].getCardValue() ||
      this->GetHand()[3].getCardValue() == this->GetHand()[4].getCardValue())
   {
      return true;
   }
   else
      return false;
}

bool Hand::isATwoPair( )
{
   //c1 == c2 and c3 == c4, or 
   //c2 == c3 and c4 == c5, or
   //c1 == c2 and c4 == c5 
   return false;
}

bool Hand::isAThreeOfAKind( )
{
   //c1 == c2 and c2 == c3 and c4 != c5, or
   //c2 == c3 and c3 == c4 and c1 != c5, or
   //c3 == c4 and c4 == c5 and c1 != c2
   return false;
}

bool Hand::isAStraight( )
{
   //c1 == c2-1 and 
   //c2 == c3-1 and 
   //c3 == c4-1 and
   //c4 == c5-1
   return false;
}

bool Hand::isAFlush( )
{
   // c1 suit == c2 suit and
   // c2 suit == c3 suit and
   // c3 suit == c4 suit and 
   // c4 suit == c5 suit and 
   return false;
}

bool Hand::isAFullHouse( )
{
   // c1 == c2 and c2 == c3 and 
   // c4 == c5 
   //or
   //c1 == c2 and
   //c3 == c4 and c4 == c5
   //and
   //!isAFourOfAKind
   return false;
}

bool Hand::isAFourOfAKind( )
{
   //c1 == c2 and
   //c2 == c3 and 
   //c3 == c4 and 
   //or
   //c2 == c3 and
   //c3 == c4 and
   //c4 == c5
   return false;
}

bool Hand::isAStraightFlush( )
{
   //isAFlush and isAStraight
   return false;
}

void Hand::EvaluateRank()
{
   //sort hand
   this->SortHandOfCards();
   //call rules and assign rank
   if (Hand::isAStraightFlush())
   {
      this->theRank = PokerParameters::HANDRANKS::STRAIGHTFLUSH;
   }
   else if (Hand::isAFourOfAKind())
   {
      this->theRank = PokerParameters::HANDRANKS::FOUROFAKIND;
   }
   else if (Hand::isAFullHouse())
   {
      this->theRank = PokerParameters::HANDRANKS::FULLHOUSE;
   }
   else if (Hand::isAFlush())
   {
      this->theRank = PokerParameters::HANDRANKS::FLUSH;
   }
   else if (Hand::isAStraight())
   {
      this->theRank = PokerParameters::HANDRANKS::STRAIGHT;
   }
   else if (Hand::isAThreeOfAKind())
   {
      this->theRank = PokerParameters::HANDRANKS::THREEOFAKIND;
   }
   else if (this->isATwoPair())
   {
      this->theRank = PokerParameters::HANDRANKS::TWOPAIR;
   }
   else if (this->isAOnePair())
   {
      this->theRank = PokerParameters::HANDRANKS::ONEPAIR;
   }
   else
      this->theRank = PokerParameters::HANDRANKS::HIGHCARD;
} //end EvaluateRank