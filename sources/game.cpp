#include "game.h"



Game::Game()
{
#ifdef NCURSES
    initscr();
    start_color();
#endif
    this->user.select_difficulty(difficulty);
    this->play();
}

Game::~Game()
{
#ifdef NCURSES
    endwin();
#endif
}

void Game::play()
{
    while(this->user.wants_to_play())
    {
        this->user.select_hand();
        this->ai.generate_hand(difficulty, user.get_hand());
        this->compare_hands();
        this->print_result();
        this->next_round();
    }
}

void Game::compare_hands()
{
    if(     this->user.get_hand() == Hand::Rock && this->ai.get_hand() == Hand::Rock)
        game_state = State::Tie;
    else if(this->user.get_hand() == Hand::Rock && this->ai.get_hand() == Hand::Paper)
        game_state = State::AIWon;
    else if(this->user.get_hand() == Hand::Rock && this->ai.get_hand() == Hand::Scissors)
        game_state = State::PlayerWon;
    else if(this->user.get_hand() == Hand::Paper && this->ai.get_hand() == Hand::Rock)
        game_state = State::PlayerWon;
    else if(this->user.get_hand() == Hand::Paper && this->ai.get_hand() == Hand::Paper)
        game_state = State::Tie;
    else if(this->user.get_hand() == Hand::Paper && this->ai.get_hand() == Hand::Scissors)
        game_state = State::AIWon;
    else if(this->user.get_hand() == Hand::Scissors && this->ai.get_hand() == Hand::Rock)
        game_state = State::AIWon;
    else if(this->user.get_hand() == Hand::Scissors && this->ai.get_hand() == Hand::Paper)
        game_state = State::PlayerWon;
    else if(this->user.get_hand() == Hand::Scissors && this->ai.get_hand() == Hand::Scissors)
        game_state = State::Tie;
}


void Game::print_result()
{
    Print("You chose: ");
    print_hand(this->user.get_hand());
    Print("\n");
    Print("I   chose: ");
    print_hand(this->ai.get_hand());
    Print("\n");


    switch(game_state)
    {
        case State::PlayerWon:
        {
            Color(Print("You have won! Congrats!\n"), COLOR_GREEN, COLOR_BLACK, ColorID); return;
        }
        case State::AIWon:
        {
            Color(Print("The AI has won!\n"), COLOR_RED, COLOR_BLACK, ColorID); return;

        }
        case State::Tie:
        {
            Color(Print("It is a tie!\n"), COLOR_YELLOW, COLOR_BLACK, ColorID); return;

        }
    };
}

void Game::next_round()
{
    Print("Do you want to play another game? [y/n] ");
#ifdef NCURSES
    refresh();
#endif
    char* play_response = new char[3];
    GetInput(play_response);
    std::string response{play_response};
    if(response == "n" || response == "no")
    {
        this->user.set_playing_state(false);;
    }

#ifdef NCURSES
    clear();
    move(0, 0);
#endif
}
