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
int dealerAI();
void player_info_display();



int main() {

    //Insert the instructions printer right here

    //Initial player information to be gathered from 45->57
    int numPlayers;
    cout << "How many players: ";
    cin >> numPlayers;
    player * listPlayersPtr = new player[numPlayers]; //list of players
    string playerName;
    for(int i = 0; i < numPlayers; i++)
    {
        cout << "Enter name of player: ";
        cin >> playerName;
        listPlayersPtr[i].setName(playerName);
        cout << "Thank you, " << listPlayersPtr[i].getName() << endl;
    }


    //Game starts
    int amount_of_die_rolled;
    int playerScore;
    int dealerScore;
    die dice;
    for(int round = 1; round <= 3; round++) {
        cout << "Round " << round << ":" << endl;
        cout << "Hit enter when ready to start the next round: " << endl;
        cin.ignore();
        cin.get();


        //The players enter their bets and then role the dice 73->89
        for (int player = 0; player < numPlayers; player++) {
            cout << "Player: " << listPlayersPtr[player].getName() << endl;
            cout << "Cash: $" << listPlayersPtr[player].getCash() << endl;
            listPlayersPtr[player].setBet();

                for (; listPlayersPtr[player].turn < 4; listPlayersPtr[player].turn++)
                {
                    amount_of_die_rolled = listPlayersPtr[player].chooseDie();
                    if (amount_of_die_rolled == 0) //This means if the player chooses to not role then their turn is over
                    {
                        listPlayersPtr[player].turn = 4;
                        continue;
                    }
                    dice.roleDie(amount_of_die_rolled);
                    playerScore = dice.getDieRole();
                    listPlayersPtr[player].total_score += playerScore;
                    dice.dieFacePrinter();
                    cout << "You rolled " << dice.getDieRole() << endl;
                    cout << "Your total score is " << listPlayersPtr[player].total_score << endl << endl;
                }
        }

        //AI dealer get its own score
        dealerScore = dealerAI();
        cout << "The dealer rolled a " << dealerScore << endl;

        //Comparison of AI to all players
        for (int player = 0; player < numPlayers; player++)
        {
            if(listPlayersPtr[player].total_score > dealerScore)
            {
                listPlayersPtr[player].updateCash(listPlayersPtr[player].getBet()); //Adds the players bet to cash if their score is better than the dealers
                cout << listPlayersPtr[player].getName();
                cout << ", you have won $" << listPlayersPtr[player].getBet() << endl;
                cout << "Your total cash is now $" << listPlayersPtr[player].getCash() << endl;
            }
            else if(listPlayersPtr[player].total_score < dealerScore)
            {
                listPlayersPtr[player].updateCash((0 - listPlayersPtr[player].getBet())); //Makes the bet negative to take away the cash
                cout << listPlayersPtr[player].getName();
                cout << ", you have lost $" << listPlayersPtr[player].getBet() << endl;
                cout << "Your total cash is now $" << listPlayersPtr[player].getCash() << endl;
            }
            else //This would mean the scores are equal
            {
                cout << listPlayersPtr[player].getName();
                cout << ", you and the dealer tied, therefore no money exchanges hands." << endl;
            }
        }
        cout << "That is the end of round " << round << endl;
    }





    cout << "ALL FINISHED";
    return 0;
}











int dealerAI() //Add the AI visual output
{
    die squares;
    int score = 0;
    for(int roles = 1; roles < 4; roles++)
    {
        if(score < 10) //This number can be changed to better suit the AI depending on the win to loss ratio
        {
            squares.roleDie(2);
            score += squares.getDieRole();
        }
        else
        {
            squares.roleDie(1);
            score += squares.getDieRole();
        }
    }
    if(score > 21)
        score = 0;
    return score;
}













