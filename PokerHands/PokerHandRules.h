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
   bool hand1HigherRank =
      hand1.GetHandRank() >
      hand2.GetHandRank();

   //compare ranking high card
   bool hand1HigherRankingCard = 
      hand1.getRankingHighCard().getCardValue() > 
      hand2.getRankingHighCard().getCardValue();

   //compare non ranking high card
   bool hand1HighNonRankingCard = 
      hand1.getNonRankingHighCard().getCardValue() > 
      hand2.getNonRankingHighCard().getCardValue();

   if (hand1HigherRank || 
         hand1HigherRankingCard || 
         hand1HighNonRankingCard)
   {
      return true;
   }
   else
   {
      return false;
   }
}
static bool PokerHandRules::Hand1TiesHand2(Hand &hand1, Hand &hand2)
{
   //check for defeat
   if (Hand1DefeatsHand2(hand1, hand2))
   {
      return false;
   }

   //compare ranks
   bool ranksMatch = (hand1.GetHandRank() == hand2.GetHandRank());

   //compare ranking high card
   bool rankingCardMatch = (
      hand1.getRankingHighCard().getCardValue() ==
      hand2.getRankingHighCard().getCardValue());
   
   //compare non ranking high card
   bool nonRankingCardMatch = (
      hand1.getNonRankingHighCard().getCardValue() == 
      hand2.getNonRankingHighCard().getCardValue());

   if (ranksMatch && rankingCardMatch && nonRankingCardMatch)
   {
      return true;
   }
   else
   {
      return false;
   }
}

#endif