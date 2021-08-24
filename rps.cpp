#include <rps.h>





int main()
{
#ifdef NCURSES
  initscr();
  start_color();
#endif
  unsigned long long ColorID = 1;
  std::string difficulty{"Normal"};
  char* choise = new char[1] ;
  Hand user_hand{Hand::Rock};
  bool user_wants_to_play{true};

  Color(Print("Let's play a game of rock, paper, scissor!\n"), COLOR_WHITE, COLOR_BLACK, ColorID);
  Color(Print("Select a difficulty:\n"), COLOR_WHITE, COLOR_BLACK, ColorID);
  Color(Print("> 1) Normal (default)\n"), COLOR_GREEN, COLOR_BLACK, ColorID);
  Color(Print("  2) Impossible        "), COLOR_RED, COLOR_BLACK, ColorID);
  GetInput(choise);

  std::string choise_str{choise};
  difficulty = choise_str == "1" ? "Normal" : "Imposible";
#ifdef NCURSES
  clear();
#endif
  while(user_wants_to_play)
  {
    if(difficulty == "Normal")
    {
      chose_hand(user_hand);
      play_normal_difficulty(user_hand, user_wants_to_play);
    }
    else
    {
      chose_hand(user_hand);
      play_imposible_difficulty(user_hand, user_wants_to_play);
    }
  }
#ifdef NCURSES
  endwin();
#endif
}
