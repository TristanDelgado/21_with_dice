#include <iostream>
#include "dice.h"
#include "player.h"
using namespace std;
/*
 * Order of gameplay:
 * At start tell instructions
 * give player money
 *
 * Now game starts:
 * Ask player for bet
 * ----should display how much the player has
 * Ask player first role
 * -----should display the total of the player after each die role
 * Ask player for second role
 * Ask player for third role
 * if player gets 21 that is blackjack ,and they get paid 2:1
 *
 * Now computer roles
 *
 * Now the end values are compared and the player wins or loses their money
 * The computer then clears the screen and starts a new game
 * the goal is to make it 10 rounds and make as much money as possible
 * starting with 50$
 *
 *
 * every die role should physically show on the screen the die
 * the end goal is to make it so their can be several players playing at once, each making their own bet,
 * and it plays just like blackjack
 */

void player_info_display();


int main() {
    /*{
        cout << "Here are the rules for the game:\n";
        cout << "1. The goal is to beat the computer, closest to 21, like blackjack\n";
        cout << "however some of the rules are difference. You will be using dice instead \n";
        cout << "of cards. You get three roles. On each role you can role one or two dice.\n";
        cout << "You also bet before each round. Your starting cash is $50. The computer also roles\n";
        cout << "three times attempting to get as close to 21 as possible. My the odds be ever in your favor\n";
    }*/

    int num_players;
    cout << "How many players: ";
    cin >> num_players;
    player * list_players_ptr = new player[num_players];
    for(int i = 0; i < num_players; i++)
    {
        list_players_ptr[i].set_name();
        cout << "Thank you," << list_players_ptr[i].get_name() << endl;
    }

    int amount_of_die_rolled;
    int score;
    die dice;
    for(int round = 1; round <= 10; round++)
    {
        cout << "Round " << round << ":" << endl;
        cout << "Hit enter when ready to start the next round: " << endl;
        cin.ignore();
        cin.get();
        for(int player = 0; player < num_players; player++)
        {
            cout << "Player: " << list_players_ptr[player].get_name() << endl;
            cout << "Cash: $" << list_players_ptr[player].get_cash() << endl;
            list_players_ptr[player].get_bet();
            for(;list_players_ptr[player].turn < 4;list_players_ptr[player].turn++)
            {
                amount_of_die_rolled = list_players_ptr[player].choose_die();
                dice.role_die(amount_of_die_rolled);
                score = dice.get_die_role();
                if(score == 0) //This means if the player chooses to not role then their turn is over
                    exit;      //this will exit the loop and move on to the next person
                list_players_ptr[player].total_score += score;
                cout << "You rolled a(n) " << dice.get_die_role() << endl;
                cout << "Your total score is " << list_players_ptr[player].total_score << endl;
            } //todo pretty much works for input and getting the dice role, however the algorithm for the computer's role
            //todo needs to be created
            //todo bug test a lot of the steps

        }
    }


    cout << "ALL FINISHED";


    return 0;
}