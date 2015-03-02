//Jessica Hatch
//Poker Hands Assignment

#include "PokerHandRules.h"


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <libconfig.h++>


using namespace std;
using namespace libconfig;

int main()
{
   std::vector<Hand> myHands;
   //read in hands

   Config cfg;

   // Read the file. If there is an error, report it and exit.
   try
   {
      cfg.readFile("POKERHANDS.cfg");
   }
   catch (const FileIOException &fioex)
   {
      std::cerr << "I/O error while reading file." << std::endl;
      return(EXIT_FAILURE);
   }
   catch (const ParseException &pex)
   {
      std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
         << " - " << pex.getError() << std::endl;
      return(EXIT_FAILURE);
   }

   const Setting& root = cfg.getRoot();

   // Output a list of all books in the inventory.
   try
   {
      const Setting &hands = root["inventory"]["hands"];
      int count = hands.getLength();

      for (int i = 0; i < count; ++i)
      {
         const Setting &hand = hands[i];

         // Only output the record if all of the expected fields are present.
         string suitstr1;
         string suitstr2;
         string suitstr3;
         string suitstr4;
         string suitstr5;
         int val1;
         int val2;
         int val3;
         int val4;
         int val5;

         if (!(hand.lookupValue("card1.suit", suitstr1)
            && hand.lookupValue("card1.val", val1)
            && hand.lookupValue("card2.suit", suitstr2)
            && hand.lookupValue("card2.val", val2)
            && hand.lookupValue("card3.suit", suitstr3)
            && hand.lookupValue("card3.val", val3)
            && hand.lookupValue("card4.suit", suitstr4)
            && hand.lookupValue("card4.val", val4)
            && hand.lookupValue("card5.suit", suitstr5)
            && hand.lookupValue("card5.val", val5)))
            continue;

           //convert suit string to enum
            PokerParameters::CARDSUITS suit1 = PokerParameters::stringToEnum(suitstr1);
            PokerParameters::CARDSUITS suit2 = PokerParameters::stringToEnum(suitstr2);
            PokerParameters::CARDSUITS suit3 = PokerParameters::stringToEnum(suitstr3);
            PokerParameters::CARDSUITS suit4 = PokerParameters::stringToEnum(suitstr4);
            PokerParameters::CARDSUITS suit5 = PokerParameters::stringToEnum(suitstr5);
            //create cards
            Card cd1(val1, suit1);
            Card cd2(val2, suit2);
            Card cd3(val3, suit3);
            Card cd4(val4, suit4);
            Card cd5(val5, suit5);

            //create a hand from the 5 cards and
            //add hand to the list of hands to analyze.
            Hand currentHand(cd1, cd2, cd3, cd4, cd5);
            myHands.push_back(currentHand);
      }
   }
   catch (const SettingNotFoundException &nfex)
   {
      // Ignore.
   }

   //evaluate hands
   
   //print outcome
   for (int i = 0; i < myHands.size(); i++)
   {
      myHands[i].DisplayHand();
   }

   return 0;

}//end main