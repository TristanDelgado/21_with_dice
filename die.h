#include <cstdlib>
#include <ctime>

#ifndef DICE_ROLE_DIE_H
#define DICE_ROLE_DIE_H

class die
{
private:
    int one_die = 0;
    int two_die = 0;

public:
    void role_one_die()
    {
        srand(time(nullptr));
        one_die = (rand() % 6 + 1);
    }
    void role_two_die()
    {
        srand(time(nullptr));
        one_die = (rand() % 6 + 1);
        two_die = (rand() % 6 + 1);
    }
    int getdierole()
    {
        int total;
        total = one_die + two_die;
        one_die = 0;
        two_die = 0;
        return total;
    }
};


#endif //DICE_ROLE_DIE_H
