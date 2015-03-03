#ifndef PokerParameters_h
#define PokerParameters_h
#include <string>

struct PokerParameters
{
public:
   enum class CARDSUITS
   {
      NOSUIT,
      HEARTS,
      DIAMONDS,
      CLUBS,
      SPADES
   };
   static CARDSUITS stringToEnum(std::string str)
   {
      if (str.compare("D") == 0)
      {
         return CARDSUITS::DIAMONDS;
      }
      else if (str.compare("C") == 0)
      {
         return CARDSUITS::CLUBS;
      }
      else if (str.compare("H") == 0)
      {
         return CARDSUITS::HEARTS;
      }
      else if (str.compare("S") == 0)
      {
         return CARDSUITS::SPADES;
      }
      else
      {
         return CARDSUITS::NOSUIT;
      }

   };
   enum class HANDRANKS
   {
      NORANK,
      HIGHCARD,
      ONEPAIR,
      TWOPAIR,
      THREEOFAKIND,
      STRAIGHT,
      FLUSH,
      FULLHOUSE,
      FOUROFAKIND,
      STRAIGHTFLUSH
   };

   static const char * getTextForRankEnum(PokerParameters::HANDRANKS enumVal)
   {
      switch (enumVal)
      {
      case HANDRANKS::NORANK:
         return " NO RANK ";
      case HANDRANKS::HIGHCARD:
         return " HIGH CARD ";
      case HANDRANKS::ONEPAIR:
         return " ONE PAIR ";
      case HANDRANKS::TWOPAIR:
         return  " TWO PAIR ";
      case HANDRANKS::THREEOFAKIND:
         return " THREE OF A KIND ";
      case HANDRANKS::STRAIGHT:
         return  " STRAIGHT ";
      case HANDRANKS::FLUSH:
         return " FLUSH ";
      case HANDRANKS::FULLHOUSE:
         return " FULL HOUSE ";
      case HANDRANKS::FOUROFAKIND:
         return " FOUR OF A KIND ";
      case HANDRANKS::STRAIGHTFLUSH:
         return " STRAIGHT FLUSH ";
      default:
         return " Not in Enum Range ";
      }
   };
private:
};

#endif