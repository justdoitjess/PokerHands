#include "Card.h"
#include <iostream>
#include <string>
#include <sstream>

Card::Card()
{

}
Card::Card(int cardval, PokerParameters::CARDSUITS cardtype) : value(cardval), suit(cardtype)
{
}

Card::~Card()
{

}

int Card::getCardValue()
{
   return value;
}

void Card::setCardValue(int val)
{
   this->value = val;
}

PokerParameters::CARDSUITS Card::getCardSuit()
{
   return suit;
}

void Card::setCardSuit(PokerParameters::CARDSUITS type)
{
   this->suit = type;
}

void Card::PrintCard()
{
   int valToPrint = this->value;
   std::string strValToPrint;
   if (valToPrint > 10)
   {
      switch (valToPrint)
      {
      case 11:
         strValToPrint = "J";
         break;
      case 12:
         strValToPrint = "Q";
         break;
      case 13:
         strValToPrint = "K";
         break;
      case 14:
         strValToPrint = "A";
         break;
      default:
         strValToPrint = "";
         break;
      }
   }
   std::string suitToPrint = "ERR";

   switch (this->suit)
   {
   case PokerParameters::CARDSUITS::SPADES:
      suitToPrint = "\x06";
      break;
   case PokerParameters::CARDSUITS::CLUBS:
      suitToPrint = "\x05";
      break;
   case PokerParameters::CARDSUITS::DIAMONDS:
      suitToPrint = "\x04";
      break;
   case PokerParameters::CARDSUITS::HEARTS:
      suitToPrint = "\x03";
      break;
   default:
      suitToPrint = "ERR";
   }
   if (!strValToPrint.empty())
   {
      std::cout << strValToPrint << suitToPrint << " ";
   }
   else
   {
      std::cout << valToPrint << suitToPrint << " ";
   }
}