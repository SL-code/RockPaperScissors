#pragma once
#include "hand.h"
#include <random>
#include <stdlib.h>

class AI
{
public:
    AI();
    void generate_hand(const std::string, const Hand);
    Hand get_hand();
    void set_hand(Hand);

private:
    Hand hand{Hand::Rock};


};


