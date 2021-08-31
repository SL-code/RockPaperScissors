#include "user.h"

extern unsigned long long ColorID;


void User::select_difficulty(std::string& difficulty)
{
    Color(Print("Let's play a game of rock, paper, scissor!\n"), COLOR_WHITE, COLOR_BLACK, ColorID);
    Color(Print("Select a difficulty:\n"), COLOR_WHITE, COLOR_BLACK, ColorID);
    Color(Print("> 1) Normal (default)\n"), COLOR_GREEN, COLOR_BLACK, ColorID);
    Color(Print("  2) Impossible        "), COLOR_RED, COLOR_BLACK, ColorID);
    char* choise = new char[1] ;
    GetInput(choise);
    std::string choise_str{choise};
    difficulty = choise_str == "1" ? "Normal" : "Impossible";
#ifdef NCURSES
    clear();
#endif
}

bool User::wants_to_play()
{
    return still_playing;
}

void User::set_playing_state(const bool& preference)
{
    still_playing = preference;
}

Hand User::get_hand()
{
    return hand;
}

void User::select_hand()
{
    char* input_choise = new char[10];
    Print("Pick your \"weapon\"\n");
    Color(Print("1) Rock\n"), COLOR_BLUE, COLOR_BLACK, ColorID);
    Color(Print("2) Paper\n"), COLOR_MAGENTA, COLOR_BLACK, ColorID);
    Color(Print("3) Scissors\n"), COLOR_CYAN, COLOR_BLACK, ColorID);
    GetInput(input_choise);
    std::string choise{input_choise};
    if(choise == "1" || choise == "Rock")
        hand = Hand::Rock;
    if(choise == "2" || choise == "Paper")
        hand = Hand::Paper;
    if(choise == "3" || choise == "Scissors")
        hand = Hand::Scissors;
}

