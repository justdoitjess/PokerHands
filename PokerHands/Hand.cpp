#include "Hand.h"
#include "PokerHandRules.h"
#include <algorithm>
#include <iostream>

using namespace std;

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
   return card1.getCardValue() > card2.getCardValue();
}

void Hand::SortHandOfCards()
{
   std::sort(this->theHand.begin(), this->theHand.end(), Hand::CompareCards);
}

PokerParameters::HANDRANKS Hand::GetHandRank()
{
   return this->theRank;
}

void Hand::PrintHandRank()
{
   cout << "Rank of Hand: ";
   cout << PokerParameters::getTextForRankEnum(this->theRank);
   cout << "\n";
}

Card Hand::getRankingHighCard()
{
   return this->rankingHighCard;
}

void Hand::SetRankingCards()
{
   switch (this->theRank)
   {
   case PokerParameters::HANDRANKS::HIGHCARD:
      this->rankingHighCard = this->theHand[0];
      this->nonRankingHighCard = this->theHand[1];

   case PokerParameters::HANDRANKS::ONEPAIR:
      if (this->theHand[0].getCardValue() == this->theHand[1].getCardValue())
      {
         this->rankingHighCard = this->theHand[0];
         this->nonRankingHighCard = this->theHand[2];
      }
      else if (this->theHand[1].getCardValue() == this->theHand[2].getCardValue())
      {
         this->rankingHighCard = this->theHand[1];
         this->nonRankingHighCard = this->theHand[0];
      }
      else
      {
         this->rankingHighCard = this->theHand[3];
         this->nonRankingHighCard = this->theHand[0];
      }

   case PokerParameters::HANDRANKS::TWOPAIR:
      if (this->theHand[0].getCardValue() != this->theHand[1].getCardValue())
      {
         this->rankingHighCard = this->theHand[1];
         this->secondRankingHighCard = this->theHand[3];
         this->nonRankingHighCard = this->theHand[0];
      }
      else if (this->theHand[2].getCardValue() != this->theHand[3].getCardValue())
      {
         this->rankingHighCard = this->theHand[0];
         this->secondRankingHighCard = this->theHand[3];
         this->nonRankingHighCard = this->theHand[2];
      }
      else
      {
         this->rankingHighCard = this->theHand[0];
         this->secondRankingHighCard = this->theHand[2];
         this->nonRankingHighCard = this->theHand[4];
      }

   case PokerParameters::HANDRANKS::THREEOFAKIND:
      this->rankingHighCard = this->theHand[2];
      if (this->theHand[2].getCardValue() == this->theHand[1].getCardValue())
      {
         this->nonRankingHighCard = this->theHand[3];
      }
      else
      {
         this->nonRankingHighCard = this->theHand[1];
      }

   case PokerParameters::HANDRANKS::FULLHOUSE:
      if (this->theHand[0].getCardValue() == this->theHand[1].getCardValue()
         &&
         this->theHand[1].getCardValue() == this->theHand[2].getCardValue())
      {
         this->rankingHighCard = this->theHand[0];
         this->secondRankingHighCard = this->theHand[3];
      }
      else
      {
         this->rankingHighCard = this->theHand[2];
         this->secondRankingHighCard = this->theHand[0];
      }

   case PokerParameters::HANDRANKS::FOUROFAKIND:
      if (this->theHand[0].getCardValue() == this->theHand[1].getCardValue())
      {
         this->rankingHighCard = this->theHand[0];
         this->nonRankingHighCard = this->theHand[4];
      }
      else
      {
         this->rankingHighCard = this->theHand[1];
         this->nonRankingHighCard = this->theHand[0];
      }

   case PokerParameters::HANDRANKS::STRAIGHT:
   case PokerParameters::HANDRANKS::FLUSH:
   case PokerParameters::HANDRANKS::STRAIGHTFLUSH:
      this->rankingHighCard = this->theHand[0];
      this->nonRankingHighCard = this->theHand[1];
   }
}

Card Hand::getNonRankingHighCard()
{
   return this->nonRankingHighCard;
}

Card Hand::getSecondRankingHighCard()
{
   return this->secondRankingHighCard;
}

void Hand::DisplayHand()
{
   cout << "  ";
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
   //c0 == c1 and c2 == c3, or c1 == c2 and c3 == c4, or c0 == c1 and c3 == c4 
   if ( ( this->GetHand()[0].getCardValue() == this->GetHand()[1].getCardValue() &&
          this->GetHand()[2].getCardValue() == this->GetHand()[3].getCardValue() ) ||
        ( this->GetHand()[1].getCardValue() == this->GetHand()[2].getCardValue() &&
        this->GetHand()[3].getCardValue() == this->GetHand()[4].getCardValue() ) ||
        (this->GetHand()[0].getCardValue() == this->GetHand()[1].getCardValue() &&
        this->GetHand()[3].getCardValue() == this->GetHand()[4].getCardValue()) )
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Hand::isAThreeOfAKind( )
{
   //c0 == c1 and c1 == c2 and c3 != c4, or
   //c1 == c2 and c2 == c3 and c0 != c4, or
   //c2 == c3 and c3 == c4 and c0 != c1
   if ((this->GetHand()[0].getCardValue() == this->GetHand()[1].getCardValue() &&
      this->GetHand()[1].getCardValue() == this->GetHand()[2].getCardValue() &&
      this->GetHand()[3].getCardValue() != this->GetHand()[4].getCardValue()) ||
      (this->GetHand()[1].getCardValue() == this->GetHand()[2].getCardValue() &&
      this->GetHand()[2].getCardValue() == this->GetHand()[3].getCardValue() &&
      this->GetHand()[0].getCardValue() != this->GetHand()[4].getCardValue()) ||
      (this->GetHand()[2].getCardValue() == this->GetHand()[3].getCardValue() &&
      this->GetHand()[3].getCardValue() == this->GetHand()[4].getCardValue() &&
      this->GetHand()[0].getCardValue() != this->GetHand()[1].getCardValue()))
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Hand::isAStraight( )
{
   //c0 == c1+1 and 
   //c1 == c2+1 and 
   //c2 == c3+1 and
   //c3 == c4+1
   if (this->GetHand()[0].getCardValue() == this->GetHand()[1].getCardValue() + 1 &&
      this->GetHand()[1].getCardValue() == this->GetHand()[2].getCardValue() + 1 &&
      this->GetHand()[2].getCardValue() == this->GetHand()[3].getCardValue() + 1 &&
      this->GetHand()[3].getCardValue() == this->GetHand()[4].getCardValue() + 1)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Hand::isAFlush( )
{
   // c0 suit == c1 suit and
   // c1 suit == c2 suit and
   // c2 suit == c3 suit and 
   // c3 suit == c4 suit and 
   if (this->GetHand()[0].getCardSuit() == this->GetHand()[1].getCardSuit() &&
      this->GetHand()[1].getCardSuit() == this->GetHand()[2].getCardSuit() &&
      this->GetHand()[2].getCardSuit() == this->GetHand()[3].getCardSuit() &&
      this->GetHand()[3].getCardSuit() == this->GetHand()[4].getCardSuit())
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Hand::isAFullHouse( )
{
   // c0 == c1 and c1 == c2 and 
   // c3 == c4 
//or
   //c0 == c1 and
   //c2 == c3 and c3 == c4
//and
   //!isAFourOfAKind
   if ((this->GetHand()[0].getCardValue() == this->GetHand()[1].getCardValue() &&
        this->GetHand()[1].getCardValue() == this->GetHand()[2].getCardValue() &&
        this->GetHand()[3].getCardValue() == this->GetHand()[4].getCardValue()) ||
       (this->GetHand()[0].getCardValue() == this->GetHand()[1].getCardValue() &&
        this->GetHand()[2].getCardValue() == this->GetHand()[3].getCardValue() &&
        this->GetHand()[3].getCardValue() == this->GetHand()[4].getCardValue()) &&
       !(this->isAFourOfAKind()))
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Hand::isAFourOfAKind( )
{
   //c0 == c1 and
   //c1 == c2 and 
   //c2 == c3 and 
//or
   //c1 == c2 and
   //c2 == c3 and
   //c3 == c4
   if ((this->GetHand()[0].getCardValue() == this->GetHand()[1].getCardValue() &&
        this->GetHand()[1].getCardValue() == this->GetHand()[2].getCardValue() &&
        this->GetHand()[2].getCardValue() == this->GetHand()[3].getCardValue()) ||
       (this->GetHand()[1].getCardValue() == this->GetHand()[2].getCardValue() &&
        this->GetHand()[2].getCardValue() == this->GetHand()[3].getCardValue() &&
        this->GetHand()[3].getCardValue() == this->GetHand()[4].getCardValue()))
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Hand::isAStraightFlush( )
{
   //isAFlush and isAStraight
   if (this->isAFlush() && this->isAStraight())
   {
      return true;
   }
   else
   {
      return false;
   }
}

void Hand::EvaluateRank()
{
   //sort hand
   this->SortHandOfCards();
   //call rules and assign rank
   if (this->isAStraightFlush())
   {
      this->theRank = PokerParameters::HANDRANKS::STRAIGHTFLUSH;
   }
   else if (this->isAFourOfAKind())
   {
      this->theRank = PokerParameters::HANDRANKS::FOUROFAKIND;
   }
   else if (this->isAFullHouse())
   {
      this->theRank = PokerParameters::HANDRANKS::FULLHOUSE;
   }
   else if (this->isAFlush())
   {
      this->theRank = PokerParameters::HANDRANKS::FLUSH;
   }
   else if (this->isAStraight())
   {
      this->theRank = PokerParameters::HANDRANKS::STRAIGHT;
   }
   else if (this->isAThreeOfAKind())
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
   this->SetRankingCards();
} //end EvaluateRank