//
// Created by conno on 4/5/2023.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>

using namespace std;

#ifndef INC_21_GAME_DICE_H
#define INC_21_GAME_DICE_H

class die
{
private:
    int die_total = 0;

    std::vector <int> numbers;

public:
    void roleDie(int num_of_die)
    {
        die_total = 0;
        numbers.clear();
        int temp_die;
        for(int i = 0; i < num_of_die; i++)
        {
            srand(time(nullptr));
            temp_die = rand() % 6 + 1;
            die_total += temp_die;
            numbers.push_back(temp_die);
        }
    }
    int getDieRole()
    {
        return die_total;
    }

    //The following function prints the die faces
    void dieFacePrinter()
    {
        for(int i = 0; i < numbers.size(); i++)
        {
            if(numbers[i] == 1)
                cout << "############\n"
                        "*          *\n"
                        "*    00    *\n"
                        "*          *\n"
                        "############";
            if(numbers[i] == 2)
                cout << "############\n"
                        "* 00       *\n"
                        "*          *\n"
                        "*       00 *\n"
                        "############";
            if(numbers[i] == 3)
                cout << "############\n"
                        "* 00       *\n"
                        "*    00    *\n"
                        "*       00 *\n"
                        "############";
            if(numbers[i] == 4)
                cout << "############\n"
                        "* 00    00 *\n"
                        "*          *\n"
                        "* 00    00 *\n"
                        "############";
            if(numbers[i] == 5)
                cout << "############\n"
                        "* 00    00 *\n"
                        "*    00    *\n"
                        "* 00    00 *\n"
                        "############";
            if(numbers[i] == 6)
                cout << "############\n"
                        "* 00    00 *\n"
                        "* 00    00 *\n"
                        "* 00    00 *\n"
                        "############";
            cout << endl;
        }

    }
};

#endif //INC_21_GAME_DICE_H
