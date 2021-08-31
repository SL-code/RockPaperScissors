#include "ai.h"

extern size_t ColorID;

AI::AI(){
        hand = Hand::Rock;
}

void AI::generate_hand(const std::string difficulty, const Hand user_hand)
{
    if(difficulty == "Normal")
    {
        srand(time(0));
        int rand_num = rand() % 3;
        if(rand_num == 0)
        {
            set_hand(Hand::Rock);
        }
        else if(rand_num == 1)
        {
            set_hand(Hand::Paper);
        }
        else if(rand_num == 2)
        {
            set_hand(Hand::Scissors);
        }
    }
    else if(difficulty == "Impossible")
    {
        if(user_hand == Hand::Rock)
        {
            hand = Hand::Paper;
            return;
        }
        else if(user_hand == Hand::Paper)
        {
            hand = Hand::Scissors;
            return;

        }
        else
        {
            hand = Hand::Rock;
            return;

        }
    }
}


Hand AI::get_hand()
{
    return hand;
}

void AI::set_hand(Hand new_hand)
{
    hand = new_hand;
}
