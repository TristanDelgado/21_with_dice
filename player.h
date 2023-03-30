#include <iostream>
#include <string>

using namespace std;

#ifndef DICE_ROLE_PLAYER_H
#define DICE_ROLE_PLAYER_H

class player
{
private:
    string name;
    int cash = 50;
    int bet;
    int amount_of_die_to_role;
    bool lost = false;
public:
    int turn;
    int total;
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

    void choose_die()
    {
        bool passed = false;
        while(!passed)
        {
            cout << "Would you like to role 0, 1 or 2 die?\n";
            cin >> amount_of_die_to_role;
            if(amount_of_die_to_role < 0 || amount_of_die_to_role > 3)
                cout << "Error. Must input 1, 2, or 3. Try again:\n";
            else
                passed = true;
        }

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

#endif //DICE_ROLE_PLAYER_H
