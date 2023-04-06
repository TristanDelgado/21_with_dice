//
// Created by conno on 4/5/2023.
//

#include <iostream>
#include <string>

using namespace std;

#ifndef INC_21_GAME_PLAYER_H
#define INC_21_GAME_PLAYER_H

class player
{
private:
    string name;
    int cash = 50;
    int bet;
    int amount_of_die_to_role;
    bool lost = false;
public:
    int turn = 1;
    bool blackjack = false;
    int total_score = 0;
    void get_bet()
    {
        bool passed = false;
        while(!passed)
        {
            cout << "Place your bet: ";
            cin >> bet;
            if(bet <= 0 || bet > cash)
                cout << "Error. Bet must be greater than 0 and less that your cash";
            else
                passed = true;
        }
    }
    int get_cash()
    {
        return cash;
    }
    void update_cash(int money)
    {
        cash += money;
        if(cash <= 0)
            lost = true;
    }

    int choose_die()
    {
        bool passed = false;
        while(!passed)
        {
            cout << "Would you like to role 0, 1 or 2 die?\n";
            cout << "Answer: ";
            cin >> amount_of_die_to_role;
            if(amount_of_die_to_role < 0 || amount_of_die_to_role > 3)
                cout << "Error. Must input 1, 2, or 3. Try again:\n";
            else
                passed = true;
        }
        return amount_of_die_to_role;
    }


    bool player_status() const
    {
        if(lost)
            return true;
        else
            return false;
    }

    void set_name()
    {
        cout << "Enter player's name: ";
        cin >> name;
    }

    string get_name()
    {
        return name;
    }
};

#endif //INC_21_GAME_PLAYER_H
