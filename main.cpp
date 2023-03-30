#include <iostream>
#include "die.h"
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
 * if player gets 21 that is blackjack and they get paid 2:1
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
 * the end goal is to make it so their can be several players playing at once, each making thier own bet,
 * and it plays just like blackjack
 */

void player_info_display();


int main() {
    {
        cout << "Here are the rules for the game:\n";
        cout << "1. The goal is to beat the computer, closest to 21, like blackjack\n";
        cout << "however some of the rules are difference. You will be using dice instead \n";
        cout << "of cards. You get three roles. On each role you can role one or two dice.\n";
        cout << "You also bet before each round. Your starting cash is $50. The computer also roles\n";
        cout << "three times attempting to get as close to 21 as possible. My the odds be ever in your favor\n";
    }

    int num_players;
    cout << "How many players: ";
    cin >> num_players;
    player * list_players_ptr = new player[num_players];
    for(int i = 0; i < num_players; i++)
    {
        list_players_ptr[i].set_name();
        cout << "Thank you, " << list_players_ptr[i].get_name();
    }


    for(int round = 1; round <= 10; round++)
    {
        cout << "round " << round << endl;
        cout << "Hit enter when ready to start the next round";
        cin.get();
        for(int player = 0; player < num_players; player++)
        {
            cout << "Player: " << list_players_ptr[player].get_name();
            cout << "Cash: " << list_players_ptr[player].get_cash();
        }
    }


    cout << "ALL FINISHED";


    return 0;
}
