//Jessica Hatch
//Poker Hands Assignment

#include "PokerHandRules.h"

#include <libconfig.h++>
#include <iostream>


using namespace std;
using namespace libconfig;

int main()
{
   std::vector<Hand> myHands;
   //read in hands
   //adding a comment
   Config cfg;

   cfg.readFile("POKERHANDS");

   const Setting & root = cfg.getRoot();

   int retrievedData = root["Hand"];


   const Setting &hands = root["inventory"]["hands"];
   int countHand = hands.getLength();

   for (int i = 0; i < countHand; ++i)
   {
      int val;
      string suitstr;
      PokerParameters::CARDSUITS suit;


      const Setting &hand = hands[i];

      const Setting &card1 = hand["card1"];
      card1.lookupValue("suit", suitstr);
      card1.lookupValue("val", val);
      suit = PokerParameters::stringToEnum(suitstr);
      Card cd1(val, suit);

      const Setting &card2 = hand["card2"];
      card2.lookupValue("suit", suitstr);
      card2.lookupValue("val", val);
      suit = PokerParameters::stringToEnum(suitstr);
      Card cd2(val, suit);

      const Setting &card3 = hand["card3"];
      card3.lookupValue("suit", suitstr);
      card3.lookupValue("val", val);
      suit = PokerParameters::stringToEnum(suitstr);
      Card cd3(val, suit);

      const Setting &card4 = hand["card4"];
      card4.lookupValue("suit", suitstr);
      card4.lookupValue("val", val);
      suit = PokerParameters::stringToEnum(suitstr);
      Card cd4(val, suit);

      const Setting &card5 = hand["card5"];
      card5.lookupValue("suit", suitstr);
      card5.lookupValue("val", val);
      suit = PokerParameters::stringToEnum(suitstr);
      Card cd5(val, suit);

      //create a hand from the 5 cards and
      //add hand to the list of hands to analyze.
      Hand currentHand(cd1, cd2, cd3, cd4, cd5);
      myHands.push_back(currentHand);
   }
   //evaluate hands
   
   //print outcome
   for (int i = 0; i < myHands.size(); i++)
   {
      myHands[i].DisplayHand();
   }

   return 0;

}//end main