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
    int cash;
    int bet;
    int amount_of_die_to_role;
    bool lost = false;
public:


    int turn;
    bool blackjack;
    int total_score;

    //Constructors====================================
    player()
    {
        cash = 50;
        lost = false;
        blackjack = false;
        total_score = 0;
        turn = 1;
    }







    //Accessors========================================
    int getCash()
    {return cash;}

    bool player_status() const
    {
        if(lost)
            return true;
        else
            return false;
    }

    string getName()
    {
        return name;
    }

    int getBet()
    {return bet;}




    //Mutators========================================
    void setName(string n)
    {name = n;}

    void updateCash(int money)
    {
        cash += money;
        if(cash <= 0)
            lost = true;
    }


    void setBet()
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



    int chooseDie()
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






};

#endif //INC_21_GAME_PLAYER_H
