#ifndef PokerHandRules_h
#define PokerHandRules_h
#include "Hand.h"

#pragma once
#include "Hand.h"

namespace PokerHandRules
{

   static bool Hand1DefeatsHand2(Hand &hand1, Hand &hand2);
   static bool Hand1TiesHand2(Hand &hand1, Hand &hand2);
   
}; //end namespace PokerHandRules


static bool PokerHandRules::Hand1DefeatsHand2(Hand &hand1, Hand &hand2)
{
   //evaluate rank of 1 and 2
   hand1.EvaluateRank();
   hand2.EvaluateRank();

   //compare ranks
   if (hand1.GetHandRank() > hand2.GetHandRank())
   {
      return true;
   }
   //compare ranking high card
   else if (hand1.getRankingHighCard().getCardValue() > hand2.getRankingHighCard().getCardValue())
   {
      return true;
   }
   else
   {
      //compare second ranking high card or non ranking high card depending on rank
      switch (hand1.GetHandRank())
      {
      case  PokerParameters::HANDRANKS::TWOPAIR:
         if ((hand1.getSecondRankingHighCard().getCardValue() >
            hand2.getSecondRankingHighCard().getCardValue()) ||
            hand1.getNonRankingHighCard().getCardValue() >
            hand2.getNonRankingHighCard().getCardValue())
         {
            return true;
         }
         else
         {
            return false;
         }
      case PokerParameters::HANDRANKS::FULLHOUSE:
         if (hand1.getSecondRankingHighCard().getCardValue() >
            hand2.getSecondRankingHighCard().getCardValue())
         {
            return true;
         }
         else
         {
            return false;
         }

      case PokerParameters::HANDRANKS::HIGHCARD:
      case PokerParameters::HANDRANKS::ONEPAIR:
      case PokerParameters::HANDRANKS::THREEOFAKIND:
      case PokerParameters::HANDRANKS::FLUSH:
      case PokerParameters::HANDRANKS::FOUROFAKIND:
         if (hand1.getNonRankingHighCard().getCardValue() > hand2.getNonRankingHighCard().getCardValue())
         {
            return true;
         }
         else
         {
            return false;
         }
      case PokerParameters::HANDRANKS::STRAIGHT:
      case PokerParameters::HANDRANKS::STRAIGHTFLUSH:
         return false;

      }
   }
}
static bool PokerHandRules::Hand1TiesHand2(Hand &hand1, Hand &hand2)
{
   //check for defeat
   if (Hand1DefeatsHand2(hand1, hand2))
   {
      return false;
   }
   else if (hand1.GetHandRank() != hand2.GetHandRank())
   {
      return false;
   }
   else if (hand1.getRankingHighCard().getCardValue() == hand2.getRankingHighCard().getCardValue())
   {
      //compare second ranking high card or non ranking high card depending on rank
      switch (hand1.GetHandRank())
      {
      case  PokerParameters::HANDRANKS::TWOPAIR:
         if ((hand1.getSecondRankingHighCard().getCardValue() ==
            hand2.getSecondRankingHighCard().getCardValue()) &&
            (hand1.getNonRankingHighCard().getCardValue() ==
            hand2.getNonRankingHighCard().getCardValue()))
         {
            return true;
         }
         else
         {
            return false;
         }
      case PokerParameters::HANDRANKS::FULLHOUSE:
         if (hand1.getSecondRankingHighCard().getCardValue() ==
            hand2.getSecondRankingHighCard().getCardValue())
         {
            return true;
         }
         else
         {
            return false;
         }

      case PokerParameters::HANDRANKS::HIGHCARD:
      case PokerParameters::HANDRANKS::ONEPAIR:
      case PokerParameters::HANDRANKS::THREEOFAKIND:
      case PokerParameters::HANDRANKS::FLUSH:
      case PokerParameters::HANDRANKS::FOUROFAKIND:
         if (hand1.getNonRankingHighCard().getCardValue() == hand2.getNonRankingHighCard().getCardValue())
         {
            return true;
         }
         else
         {
            return false;
         }
      case PokerParameters::HANDRANKS::STRAIGHT:
      case PokerParameters::HANDRANKS::STRAIGHTFLUSH:
         return true;
      }
   }
   else
   {
      return false;
   }
}
#endif