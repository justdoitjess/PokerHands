//********************************************************************
// Poker Hands Assignment
// Author: Jessica Hatch
// Date: March 2, 2015
// Class: Object Oriented Programming in C++
// Purpose: This program ranks and displays poker hands.
// Input: input of txt file holding poker hands (*libconfig implementation 
// was started but not completed.
// Output: A display of poker hands with rank
//********************************************************************
#include "PokerHandRules.h"


#include <iostream>
#include <iomanip>
#include <cstdlib>
//#include <libconfig.h++>
#include <conio.h> // for _getch()
#include <vector>
#include <fstream> //for file read/write


using namespace std;

int main()
{
   string fileNameInput  =
      "C:/Users/Jessica/Documents/OOProgramming/PokerHands/HandsToAnalyze.txt";
   bool endOfFile = false; //flag to deal with end of file

   //explain that you're going to read in text file consiting 
   //of poker hands and you're going to rank and dispay the hand
   //rank is as follows:
   //Straight Flush, Four of A Kind, Full House, Flush, Straight, 
   //Three of a Kind, Two Pair, One Pair, High Card
   cout << "Hello! Let's Learn How to Play Poker\n";
   cout << "Make sure all hands \nare written in a text file separated by commas.";
   cout << "\nName it HandsToAnalyze.txt\n";
   cout << "\nI will analyze each hand listed, \nprint the hand, \nprint the rank of the hand,";
   cout << "\nand Compare the hands 2 at a time.\n\n";
   cout << endl;

   //vector of all hands read
   std::vector<Hand> myHands;
   std::vector<Card> allCards;

   //read in file line by line
   ifstream infile(fileNameInput);
   while (infile.good())
   {
      std::vector<Card> currentCards;
      std::vector<int> cardValues;
      std::vector<PokerParameters::CARDSUITS> cardSuits;
      //read in 5 cards to make up first hand to compare
      for (int i = 0; i < 5; i++)
      {
         std::string cardValStr;
         std::string cardSuitStr;

         //get value of card
         getline(infile, cardValStr, ',');
         cardValues.insert(cardValues.begin(), atoi(cardValStr.c_str()));

         //get suit of card
         getline(infile, cardSuitStr, ',');
         cardSuits.insert(cardSuits.begin(), PokerParameters::stringToEnum(cardSuitStr));
      }//end read in 5 cards for loop

      //make 5 cards
      Card cd1(cardValues[0], cardSuits[0]);
      Card cd2(cardValues[1], cardSuits[1]);
      Card cd3(cardValues[2], cardSuits[2]);
      Card cd4(cardValues[3], cardSuits[3]);
      Card cd5(cardValues[4], cardSuits[4]);

      //make first hand
      Hand hand1(cd1, cd2, cd3, cd4, cd5);

      //read in 5 cards to make up second hand to compare
      for (int i = 0; i < 5; i++)
      {
         std::string cardValStr;
         std::string cardSuitStr;

         //get value of card
         getline(infile, cardValStr, ',');
         cardValues.insert(cardValues.begin(), atoi(cardValStr.c_str()));

         //get suit of card
         getline(infile, cardSuitStr, ',');
         cardSuits.insert(cardSuits.begin(), PokerParameters::stringToEnum(cardSuitStr));
      }//end read in 5 cards for loop

      //make 5 cards
      Card cd6(cardValues[0], cardSuits[0]);
      Card cd7(cardValues[1], cardSuits[1]);
      Card cd8(cardValues[2], cardSuits[2]);
      Card cd9(cardValues[3], cardSuits[3]);
      Card cd10(cardValues[4], cardSuits[4]);

      //make second hand
      Hand hand2(cd6, cd7, cd8, cd9, cd10);

      //don't compare empty hands
      if (0 != hand1.GetHand()[0].getCardValue())
      {
         //compare 2 hands and determine winner
         std::string outcome;
         bool hand1BeatsHand2 = PokerHandRules::Hand1DefeatsHand2(hand1, hand2);
         bool hand1TiesHand2 = PokerHandRules::Hand1TiesHand2(hand1, hand2);
         if (hand1BeatsHand2)
         {
            outcome = "defeats\n\n";
         }
         else if (hand1TiesHand2)
         {
            outcome = "ties\n\n";
         }
         else
         {
            outcome = "is defeated by\n\n";
         }

         //print outcome
         cout << "\n\nFirst Hand: ";
         hand1.DisplayHand();
         hand1.PrintHandRank();
         cout << "\n";

         cout << outcome;

         cout << "Second Hand";
         hand2.DisplayHand();
         hand2.PrintHandRank();
         cout << "\n";
      }
   }
   _getch();
   return 0;

}//end main