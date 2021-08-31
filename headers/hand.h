#pragma once

#include <iostream>
#include <string>
#include <ncurses.h>

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

void print_hand(Hand hand);
