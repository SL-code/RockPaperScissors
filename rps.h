#pragma once
#include <iostream>
#include <string>
#include <ncurses.h>
#include <memory>

unsigned long long ColorID2 = 1;
#ifdef NCURSES
  #define Print(message) printw(message)
#else
  #define Print(message) std::cout << message
#endif


#ifdef NCURSES
  #define GetInput(user_response) getstr(user_response)
#else
  #define GetInput(user_response) std::cin >> user_response
#endif


#ifdef NCURSES
  #define Color(CppStatement, ForeColor, BackColor, PairID) init_pair(PairID, ForeColor, BackColor);\
    attron(COLOR_PAIR(PairID));\
    CppStatement;\
    attroff(COLOR_PAIR(PairID));\
    refresh();\
    PairID++;
#else
  #define Color(CppStatement, ForeColor, BackColor, PairID) CppStatement
#endif





enum class Hand
{
  Rock, Paper, Scissors,
};

void print_hand(Hand hand)
{
  if(hand == Hand::Rock)
  {
    Color(Print("Rock"), COLOR_BLUE, COLOR_BLACK, ColorID2);
    return;
  }
  if(hand == Hand::Paper)
  {
    Color(Print("Paper"), COLOR_MAGENTA, COLOR_BLACK, ColorID2);
    return;
  }
  if(hand == Hand::Scissors)
  {
    Color(Print("Scissors"), COLOR_CYAN, COLOR_BLACK, ColorID2);
    return;
  }
}

bool compare_hands(Hand h1, Hand h2)
{
  if(h1 == Hand::Rock && h2 == Hand::Scissors)
    return true;
  else if(h1 == Hand::Paper && h2 == Hand::Rock)
    return true;
  else if (h1 == Hand::Scissors && h2 == Hand::Paper)
    return true;
  else
    return false;
}


void show_winner(const char* result, Hand user_hand, Hand generated_hand, bool& wants_to_play)
{
  Print("You chose: ");
  print_hand(user_hand);
  Print("\n");

  Print("I   chose: ");
  print_hand(generated_hand);
  Print("\n");

  if(result == "It is a tie!\n")
  {
    Color(Print(result), COLOR_YELLOW, COLOR_BLACK, ColorID2);
  }
  else if(result == "You have won! Congrats!\n")
  {
    Color(Print(result), COLOR_GREEN, COLOR_BLACK, ColorID2);
  }
  else
  {
    Color(Print(result), COLOR_RED, COLOR_BLACK, ColorID2);
  }


  Print("Do you want to play another game? [y/n] ");

#ifdef NCURSES
  refresh();
#endif

  char* play_response = new char[1];
  GetInput(play_response);
  std::string response{play_response};
  if(response == "n")
  {
    wants_to_play = false;
  }

#ifdef NCURSES
  clear();
  move(0, 0);
#endif
}


void compare_show_winnner(Hand user_hand, Hand generated_hand, bool& wants_to_play)
{
  if(user_hand == generated_hand)
  {
    show_winner("It is a tie!\n", user_hand, generated_hand, wants_to_play);
  }
  else if(compare_hands(user_hand, generated_hand))
  {
    show_winner("You have won! Congrats!\n", user_hand, generated_hand, wants_to_play);
  }
  else
  {
    show_winner("I have won!\n", user_hand, generated_hand, wants_to_play);
  }
}


void play_normal_difficulty(Hand user_hand, bool& wants_to_play)
{
  //Randomly generate a hand
  Hand generated_hand;
  int rand_num = rand() % 3;
  if(rand_num == 0)
    generated_hand = Hand::Rock;
  if(rand_num == 1)
    generated_hand = Hand::Paper;
  if(rand_num == 2)
    generated_hand = Hand::Scissors;

  //Compare hands, show winner, ask to continue
  compare_show_winnner(user_hand, generated_hand, wants_to_play);
}



void play_imposible_difficulty(Hand user_hand, bool& wants_to_play)
{
  //Pick a hand to beat the user
  Hand generated_hand;
  if(user_hand == Hand::Rock)
    generated_hand = Hand::Paper;
  else if(user_hand == Hand::Paper)
    generated_hand = Hand::Scissors;
  else
    generated_hand = Hand::Rock;

  //Compare hands, show winner, ask to continue
  compare_show_winnner(user_hand, generated_hand, wants_to_play);
}


void chose_hand(Hand& user_hand)
{
  char* input_choise = new char[1];
  Print("Pick your \"weapon\"\n");
  Color(Print("1) Rock\n"), COLOR_BLUE, COLOR_BLACK, ColorID2);
  Color(Print("2) Paper\n"), COLOR_MAGENTA, COLOR_BLACK, ColorID2);
  Color(Print("3) Scissors\n"), COLOR_CYAN, COLOR_BLACK, ColorID2);
  GetInput(input_choise);
  std::string choise{input_choise};
  if(choise == "1" || choise == "Rock")
    user_hand = Hand::Rock;
  if(choise == "2" || choise == "Paper")
    user_hand = Hand::Paper;
  if(choise == "3" || choise == "Scissors")
    user_hand = Hand::Scissors;
}
