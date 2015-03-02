#ifndef PokerParameters_h
#define PokerParameters_h
#include <string>

class PokerParameters
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
      if (str.compare("DIAMONDS") == 0)
      {
         return CARDSUITS::DIAMONDS;
      }
      else if (str.compare("CLUBS"))
      {
         return CARDSUITS::CLUBS;
      }
      else if (str.compare("HEARTS"))
      {
         return CARDSUITS::HEARTS;
      }
      else if (str.compare("SPADES"))
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
private:
};

#endif