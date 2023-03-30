#include <iostream>
#include "die.h"
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



int main() {
    {
        cout << "Here are the rules for the game:\n";
        cout << "1. The goal is to beat the computer, closest to 21, like blackjack\n";
        cout << "however some of the rules are difference. You will be using dice instead \n";
        cout << "of cards. You get three roles. On each role you can role one or two dice.\n";
        cout << "You also bet before each round. Your starting cash is $50. The computer also roles\n";
        cout << "three times attempting to get as close to 21 as possible. My the odds be ever in your favor\n";
    }

    cout << "How many players "


    cout << "ALL FINISHED";


    return 0;
}
