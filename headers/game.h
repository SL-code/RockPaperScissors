#pragma once
#include "hand.h"
#include "user.h"
#include "ai.h"

extern size_t ColorID;

class Game: public User, public AI{
public:
    Game();
    ~Game();

private:
    void play();

    void compare_hands();

    void print_result();

    void next_round();

private:
    User user{};
    AI ai{};
    std::string difficulty{"Normal"};

    enum class State{
        PlayerWon, AIWon, Tie
    };
    State game_state{State::Tie};

};
