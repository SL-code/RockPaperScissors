#include "hand.h"
extern size_t ColorID;

void print_hand(Hand hand)
{
  if(hand == Hand::Rock)
  {
    Color(Print("Rock"), COLOR_BLUE, COLOR_BLACK, ColorID);
    return;
  }
  if(hand == Hand::Paper)
  {
    Color(Print("Paper"), COLOR_MAGENTA, COLOR_BLACK, ColorID);
    return;
  }
  if(hand == Hand::Scissors)
  {
    Color(Print("Scissors"), COLOR_CYAN, COLOR_BLACK, ColorID);
    return;
  }
}
