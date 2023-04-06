//
// Created by conno on 4/5/2023.
//

#include <cstdlib>
#include <ctime>
#include <random>

#ifndef INC_21_GAME_DICE_H
#define INC_21_GAME_DICE_H

class die
{
private:
    int die_total = 0;

public:
    void role_die(int num_of_die)
    {
        die_total = 0;
        for(int i = 0; i < num_of_die; i++)
        {
            srand(time(nullptr));
            die_total += rand() % 6 + 1;
        }
    }
    int get_die_role()
    {
        return die_total;
    }
};

#endif //INC_21_GAME_DICE_H
