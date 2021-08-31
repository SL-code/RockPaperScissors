#pragma once
#include "hand.h"


class User
{
public:
    void select_difficulty(std::string& difficulty);
    bool wants_to_play();
    void set_playing_state(const bool& preference);
    void select_hand();
    Hand get_hand();

private:
        Hand hand{Hand::Rock};
        bool still_playing{true};
};







