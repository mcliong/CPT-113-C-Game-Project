#include <iostream>
#include <cstdlib> // rand and srand
#include <iomanip> //IO Manipulators
#include <ctime>   // For the time function
#include <string>

//include all the header files and implementation files
#include "NumberList.h"
#include "DynamicQueue.h"
#include "FateCardStack.h"
using namespace std;

//function prototype of each function
void printheader(string);
void rule();
void tittle();
void useFateCard();
void play(DynamicQueue, NumberList, NumberList, NumberList, string &, string &, string &, string &, string &, string &);
void menu(DynamicQueue, NumberList, NumberList, NumberList, string, string, string, string, string, string);
void enterToContinue();

//function main
int main()
{
    //declaration of all the variables and objects
    NumberList map, grp1, grp2;
    string name = "", name_grp1 = "", name_grp2 = "", m1_grp1 = "", m2_grp1 = "", m1_grp2 = "", m2_grp2 = "";
    int random, ran_num;
    double diff;
    const int QUEUE_SIZE = 4;
    bool status = true;
    DynamicQueue queue;

    //Get the system time
    unsigned seed = time(0);
    //Seed the random number generator
    srand(seed);

    map.appendNode(3);
    while (status)
    {
        //assigned produced random number to the variable
        int ran_num = rand();
        //to manipulate the random number so that its range will be in 1 until 25
        random = 1 + (ran_num % 25);
        //create a random set of correct blocks that fulfill all the condition for this game
        diff = (random - map.lastNode());
        if (!map.search(random) && (diff == -1 || diff == 1 || diff == 5))
        {
            int last = map.lastNode();
            if (last % 5 == 0 && diff == 1)
            {
                status = true;
            }
            else if (last % 5 == 1 && diff == -1)
            {
                status = true;
            }
            else
            {
                map.appendNode(random);
                //To ensure it stop when it reached our end point (22)
                if (random == 22)
                    status = false;
            }
        }
    }

    //The starting point
    grp1.appendNode(3);
    grp2.appendNode(3);

    //map.show_map;//for us to check the correct path
    //map.displayList();

    //to call the function that print the art design of the game title
    tittle();
    //menu function that provide several options for the user
    menu(queue, map, grp1, grp2, name_grp1, name_grp2, m1_grp1, m2_grp1, m1_grp2, m2_grp2);

    return 0;
}

//function to show the tittle of the game
void tittle()
{
    cout << " ___   _  _______  ___   _______  _______  ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ __" << endl;
    cout << "|   | | ||   _   ||   | |       ||       | ___|___|___|___|___|___|___|___|___|___|___|___|___|__" << endl;
    cout << "|   |_| ||  |_|  ||   | |_     _||   _   | _|___|___|___|___|___|___|___|___|___|___|___|___|___|" << endl;
    cout << "|      _||       ||   |   |   |  |  | |  | ___|___|___|___|___|___|___|___|___|___|___|___|___|__" << endl;
    cout << "|     |_ |       ||   |   |   |  |  |_|  | _|___|___|___|___|___|___|___|___|___|___|___|___|___|" << endl;
    cout << "|    _  ||   _   ||   |   |   |  |       | ___|___|___|___|___|___|___|___|___|___|___|___|___|__" << endl;
    cout << "|___| |_||__| |__||___|   |___|  |_______| _|___|___|___|___|___|___|___|___|___|___|___|___|___|" << endl;
    cout << " ___   __    _  __   __  ___   _______  ___   _______  ___      _______  _|___|___|___|___|___|__" << endl;
    cout << "|   | |  |  | ||  | |  ||   | |       ||   | |  _    ||   |    |       | ___|___|___|___|___|___|" << endl;
    cout << "|   | |   |_| ||  |_|  ||   | |  _____||   | | |_|   ||   |    |    ___| _|___|___|___|___|___|__" << endl;
    cout << "|   | |       ||       ||   | | |_____ |   | |       ||   |    |   |___  ___|___|___|___|___|___|" << endl;
    cout << "|   | |  _    ||       ||   | |_____  ||   | |  _   | |   |___ |    ___| _|___|___|___|___|___|__" << endl;
    cout << "|   | | | |   | |     | |   |  _____| ||   | | |_|   ||       ||   |___  ___|___|___|___|___|___|" << endl;
    cout << "|___| |_|  |__|  |___|  |___| |_______||___| |_______||_______||_______| _|___|___|___|___|___|  " << endl;
    cout << " __   __  _______  _______  _______  _ ___ ___ ___ ___ ___ ___ ___ ___ _____|___|___|___|        " << endl;
    cout << "|  |_|  ||   _   ||       ||       | _|___|___|___|___|___|___|___|___|___|___|                  " << endl;
    cout << "|       ||  |_|  ||____   ||    ___| ___|___|___|___|___|___|___|___|___|___|                  __" << endl;
    cout << "|       ||       | ____|  ||   |___  _|___|___|___|___|___|___|___|___|                   ___ |_" << endl;
    cout << "|       ||       || ______||    ___| ___|___|___|___|___|___|___|_             ___      _|___|___" << endl;
    cout << "| ||_|| ||   _   || |_____ |   |___  _|___|___|___|___|___|___|___|         __|___|    |___|_ _|_" << endl;
    cout << "|_|   |_||__| |__||_______||_______| ___|___|___|___|___|___|___|          |___|___|     |___|___|" << endl;
    cout << "" << endl;
}

//function to show the rules of the game
void rule()
{
    string rules = "RULES";
    printheader(rules);

    cout << "Definition:"<<endl;
    cout << "Kaito Invisible Maze is a game that seek for the correct tile (block) in the maze that randomly set \nby the system." << endl;
    cout << "This game challenged the player's memory on the correct tile and the strategy to race faster to the \nending point.";
    cout << "Besides it also aquire the player's calculation skills to help them select the tile quicker.\n"<<endl;

    enterToContinue();
    cin.ignore();

    cout << "\nThe starting point and the ending point of the maze are set as 3(starting point) and 22(ending point). " << endl;
   	cout << "Example: "<<endl;
    cout << "\n    ending point		This is the name of block:	   Example of Correct block:\n        v" << endl;
    cout << "      @ * @ @ @ 		     21 22 23 24 25			   @ * @ @ @" << endl;
    cout << "      @ @ @ @ @			     16 17 18 19 20			   @ * * * *" << endl;
    cout << "      @ @ @ @ @			     11 12 13 14 15			   @ @ @ * *" << endl;
    cout << "      @ @ @ @ @			     06 07 08 09 10			   @ @ * * @" << endl;
    cout << "      @ @ * @ @			     01 02 03 04 05			   @ @ * @ @" << endl;
    cout << "          ^\n    begining point \n" << endl;
    cout << "The sample answer for the example shown are:"<<endl;
	cout << "Answer 1 (Without short-cut):"<<endl;
    cout << "head -> 3 (no need to be inserted) -> 8 -> 9 -> 14 -> 15 -> 20 -> 19 -> 18 -> 17 -> 22(end need to be inserted)"<<endl;
    cout << "\nAnswer 2 (Used short-cut) :"<<endl;
    cout << "\nhead -> 3 (no need to be inserted) -> 8 -> 9 -> 14 -> 19 -> 18 -> 17 -> 22(end need to be inserted)\n"<<endl;

    enterToContinue();

	cout << "Rules:"<<endl;
    cout << "1. The first group that reached the end point will be the winner of this game." << endl;
    cout << "2. There will be two groups, each with two members. Each group member need to take turn to \n   play in sequential order." << endl;
    cout << "3. When reached the member's turn, member are given a chance to choose the next step. \n";
    cout << "4. Player are allow to walk one step to left, right or up a tile in each round. " << endl;
    cout << "5. In order to talk to the tile selected, player need to insert the respective number\n   of the block by calculating."<<endl;
    cout << "6. If the step chosen is the correct block set by the system, the player can continue \n   continue choosing the next path in the next round.(sometime, short-cut are available) "<<endl;
    cout << "7. However, if the step chosen is a trap, the map of that group will return to its begining \n   state and  members of that group need to race to the ending point again from zero. " << endl;
    cout << "8. Some special power effects will be given for each members to choose in the specific time.\n   Use them wisely to help your group win the game!!!\n";

    string done_rule = "Good Luck & All The Best!!!";
    printheader(done_rule);
}

//function to show the Fate Card round
void useFateCard()
{
    enterToContinue();
    cout << "\n\n--      &      .  *  .	  " << endl;
    cout << "      :     *  ( .*) *	" << endl;
    cout << "     .:.  .(* ) .*  ) .	" << endl;
    cout << "    .:M:.   (.*( * )    . .       . .       . .    .       . .   " << endl;
    cout << "      *        /.   * 	.+'|=|`+. .+'|=|`+. .+'|=|`+.=|`+. .+'|=|`+." << endl;
    cout << "  .::.^.::..../ 	|  | `+.| |  | |  | |.+' |  | `+.| |  | `+.|" << endl;
    cout << ".::::.::'''' 		|  |=|`.  |  |=|  |      |  |      |  |=|`. 	" << endl;
    cout << " :: :::::		|  | `.|  |  | |  |      |  |      |  | `.| " << endl;
    cout << "    :::::		|  |      |  | |  |      |  |      |  |    .		" << endl;
    cout << "    :::::		|  |      |  | |  |      |  |      |  | .+'|		" << endl;
    cout << "   .:::::.		`+.|      `+.| |..|      |.+'      `+.|=|.+'" << endl;
    cout << "   :::::::  			" << endl;
    cout << " jgs`':::'' 			*It's Fate Card Round !!! *'" << endl;

    string round = "FATE CARD ROUND";
    printheader(round);
    cout << "In fate round, players can decide whether to use the given fate card or not~" << endl;
    enterToContinue();
}

//function to play the game
void play(DynamicQueue Queue, NumberList Map, NumberList Grp1, NumberList Grp2, string &Name_grp1, string &Name_grp2, string &M1_grp1, string &M2_grp1, string &M1_grp2, string &M2_grp2)
{
    //declaration of object that only used in play() function
    FateCard FC;

    //informing grouping session
    string start = "GAME START - Grouping Session";
    printheader(start);
    cin.ignore();
    
    //Group up the players and get the player's nickname
    cout << "Group 1:" << endl;
    cout << "Please enter the group name : ";
    getline(cin, Name_grp1);
    cout << "Please enter the first member's name: ";
    getline(cin, M1_grp1);
    cout << "Please enter the second member's name: ";
    getline(cin, M2_grp1);
    cout << "\nGroup 2:" << endl;
    cout << "Please enter the group name : ";
    getline(cin, Name_grp2);
    cout << "Please enter the first member's name: ";
    getline(cin, M1_grp2);
    cout << "Please enter the second member's name: ";
    getline(cin, M2_grp2);
    cout << endl;

    //enqueue the players into queue list
    Queue.enqueue(M1_grp1);
    Queue.enqueue(M1_grp2);
    Queue.enqueue(M2_grp1);
    Queue.enqueue(M2_grp2);

    //Show the game start
    start = "GAME START!!!";
    printheader(start);

    //declaration of variables 
    string name, rply;
    int choice, turn = 1, diff, membercounter = 1, last, card, fateround = 1, fatecount = 1;
    bool compareGrp1 = false, compareGrp2 = false, ans, resultGrp1 = false, resultGrp2, condition = true;
    bool skip1 = false, skip2 = false, sskip1 = false, sskip2 = false;
    bool g1card5 = false, g2card5=false, empty = false;

    //while no winner is found, the loop will keep looping
    do
    {
        //check the turn and allow the respective group member to make a move
        //First, Group 1's turn
        if (turn % 2 == 1)              
        {
            //when reached group 1 turn, group 1 will take the move, 
            //so we dequeue a person and enqueue him back to the queue for looping round by round
            enterToContinue();
            Queue.dequeue(name);
            Queue.enqueue(name);


            //check whether the current round need to be skipped (fate card by opponents)
            if (skip2)
            {
                turn++;             //increase the turn counter
                skip2 = false;      //set the "round skipping false" back to false
                cout << "Group " << Name_grp1 << "'s turn had been skipped due to the fate card used by your opponents! ;(" << endl;
                
            }

            //check whether the current round need to be skipped (fate card used by own group)
            else if (sskip1)
            {
                turn++;
                sskip1 = false;     
                cout << "You had skipped youeself a turn using Fate Card 2~" << endl;
            }

            //if no skipping encountered, proceed with the move
            else
            {
                //show group 1 turn to inform the player make some move
                cout << "Current state: Group " << Name_grp1 << "'s turn \n\n";

                //show the group 1's current map (with correct tile inserted)
                Grp1.show_map();
                cout << endl;

                //if opponents used card 5, tell player their map had reseted due to the fate card
                if (g2card5)
                {
                    g2card5 = false;          //set the card 5 checker back to false
                    cout << "Your opponents had sent you back to the begining in last Fate Round ;(" << endl;
                }

                //tell the player did they choosed a correct path last round
                else if (resultGrp1 && turn > 1)
                    cout << "Your group choosed a correct tile in last round.\n\n";

                else if (!resultGrp1 && turn > 1)
                    cout << "Your group choosed a wrong tile last round...\nYou have been returned to the starting point again.\n\n";

                //tell the player to make the next move
                cout << "Please key in the next step! Your end point will be at 22.\n";
                cout << "Group " << Name_grp1 << "'s member " << membercounter << endl
                     << name << "'s choice : ";
                cin >> choice;
                
                //increase the turn counter
                turn++;
                
                //calculate and check whether the move made by user is valid
                diff = (choice - Grp1.lastNode());
                last = Grp1.lastNode();

                //Validation to make sure the move is only one step to the left, right or up without repeated answer
                while (Grp1.search(choice) || (diff != -1 && diff != 1 && diff != 5))
                {
                    cout << "You had entered an invalid tile. Please key in the next step again: ";
                    cin >> choice;
                    diff = (choice - Grp1.lastNode());
                }
                
                //Validation to make sure the tile on the right most column can't make move to left most column and vice versa 
                //(as the different is still 1) 
                while ((last % 5 == 0 && diff == 1) || (last % 5 == 1 && diff == -1))
                {
                    cout << "You had entered an invalid tile. Please key in the next step again: ";
                    cin >> choice;
                    diff = (choice - Grp1.lastNode());
                }

                //check is the choice by player is correct
                ans = Map.search(choice);

                //if the player selected a correct choice, save the group's choice and and update the result checker
                if (ans)
                {
                    Grp1.appendNode(choice);        //save group's choice
                    resultGrp1 = true;              //update the group's result checker = true
                    if (choice == 22)
                        compareGrp1 = true;         //check did the group reached the endding point
                }

                //if the player selected an incorrect choice, reset the player's answer and update the result checker
                else
                {
                    Grp1.destroyLinkedList();       //destroy the group's answer (linked list)
                    Grp1.appendNode(3);             //append the beginning point to the linked list
                    resultGrp1 = false;             //update the group's result checker = false
                }
            }

            //tell the player their turn is ended
            cout << "\n#######################################  Group 1 Turn End  #######################################"
                 << endl;
        }

        //Then, Group 2's turn   
        else if (turn % 2 == 0)        
        {
            //the algorithm is same like group 1, just different in variables
            //so comment will not accompanied

            enterToContinue();
            Queue.dequeue(name);
            Queue.enqueue(name);

            if (skip1)
            {
                turn++;
                skip1 = false;
                cout << "Group " << Name_grp2 << "'s turn had been skipped due to the fate card used by you opponents! ;(" << endl;
            }

            else if (sskip2)
            {
                turn++;
                sskip2 = false;
                cout << "You had skipped youeself a turn using Fate Card 2~" << endl;
            }

            else
            {
                cout << "Current state: Group " << Name_grp2 << "'s turn \n\n";
                Grp2.show_map();
                cout << endl;

                if (g1card5)
                {
                    g1card5 = false;
                    cout << "Your opponents had sent you back to the begining in last Fate Round ;(" << endl;
                }
                else if (resultGrp2 && turn > 2)
                    cout << "Your group choosed a correct tile in last round.\n\n"; 
                else if (!resultGrp2 && turn > 2)
                    cout << "Your group choosed a wrong tile last round...\nYou have been returned to the starting point again.\n\n";

                cout << "Please key in the next step! Your end point will be at 22.\n";
                cout << "Group " << Name_grp2 << "'s member " << membercounter << endl
                     << name << "'s choice : ";
                cin >> choice;

                turn++;

                diff = (choice - Grp2.lastNode());
                last = Grp2.lastNode();

                while (Grp2.search(choice) || (diff != -1 && diff != 1 && diff != 5))
                {
                    cout << "You had entered an invalid tile. Please key in the next step again: ";
                    cin >> choice;
                    diff = (choice - Grp2.lastNode());
                }

                while ((last % 5 == 0 && diff == 1) || (last % 5 == 1 && diff == -1))
                {
                    cout << "You had entered an invalid tile. Please key in the next step again: ";
                    cin >> choice;
                    diff = (choice - Grp2.lastNode());
                }

                ans = Map.search(choice);

                if (ans)
                {
                    Grp2.appendNode(choice);
                    resultGrp2 = true;
                    if (choice == 22)
                        compareGrp2 = true;
                }
                else
                {
                    Grp2.destroyLinkedList();
                    Grp2.appendNode(3);
                    resultGrp2 = false;
                }
            }

            cout << "\n#######################################  Group 2 Turn End  #######################################"
                 << endl;

            //Only different part compare to algorithm in group1
            //update member counter to allow system determine the who are the making the move next round
            if (membercounter == 1)
                membercounter++;
            else if (membercounter == 2)
                membercounter--;

            //update the fatecount counter that used to determine fate card round
            fatecount++;
        }


        //Round checker 
        if ((fateround % 2) == 0)    
        {   
            //if the fateround is divisible by 2, it means one round is ended and next round is not a Fate Card round
            
            if (!compareGrp1 && !compareGrp2)       //and if the game not yet end, 
            {                                       //tell the user that a round is ended
                string round = "ONE ROUND IS ENDED~";
                printheader(round);
            }
        }

        //Fate Card Round
        if (((fateround % 4) == 0) && !empty)
        {
            //if the fateround is divisible by 4, which mean it is a complete round after 4 players make a move and
            //the fate card stack are still available (not empty stack)
            //run Fate Card Round

            if (!compareGrp1 && !compareGrp2)           //if there's still no winner, proceed
            {
                //reset the condition to true, so that the fate card drawing can proceed
                condition = true;
                cin.ignore();

                //check is the stack empty
                if (FC.isEmptyStack())
                {
                    if (!empty)
                    {
                        useFateCard();                  //this condition is the last time fate round encountered, 
                        FC.pop(card);                   //comment in the stack pop operation will tell the players the card are empty

                        empty = true;                   //update the empty variable that allow the fate card round so that the fate card round will
                                                        //no longer proceed

                        string round = "FATE CARD ROUND ENDED";
                        printheader(round);             //tell user the fate card round is ended
                    }
                }

                //if card stack is still available, proceed card drawing
                else if (!(FC.isEmptyStack()))
                {
                    useFateCard();          //inform player now is fate card round

                    //card drawing for group 1
                    cout << "This is the card for Group " << Name_grp1 << ":\n"
                         << endl;
                    FC.pop(card);   //draw a card from stack

                    // ask the group are them going to use the card drawed
                    cout << "Do you want to use the card? (Y/N)  ";
                    cin >> rply;
                    cout << endl;

                    //since every time entering fate card round the condition will reset to correct
                    //the card drawing process will proceed until the card stack is empty
                    while (condition)
                    {
                        //validation if Group1 use the card
                        if (rply == "y" || rply == "Y" || rply == "yes" || rply == "Yes")
                        {
                            //tells the player what is the drawed card's function
                            if (card == 1)
                            {
                                cout << "You used Fate Card 1.\nBut there's nothing happen..." << endl;
                                condition = false;      //after explanation by every card, set the condition to false to stop the validation loop
                            }
                            else if (card == 2)
                            {
                                cout << "You used Fate Card 2." << endl;
                                sskip1 = true;          //set the skip checker to true so that in next round the player's turn will be skipped 
                                condition = false;
                            }
                            else if (card == 3)
                            {
                                cout << "You used Fate Card 3." << endl;
                                skip1 = true;           //set the skip checker to true so that in next round the opponent's turn will be skipped 
                                condition = false;
                            }
                            else if (card == 4)
                            {
                                cout << "You used Fate Card 4." << endl;

                                //fate card 4 allow players to make another move
                                //hence, show user the map so that they can make a new move according to their previous answer
                                Grp1.show_map();

                                //show correctness of group's previous choice  //same in the group's turn algorithm
                                if (resultGrp1 && turn > 1)
                                cout << "Your group choosed a correct tile in last round.\n\n";
                                else if (!resultGrp1 && turn > 1)
                                cout << "Your group choosed a wrong tile last round...\nYou have been returned to the starting point again.\n\n";

                                cout << "\nPlease key in the next step! Your end point will be at 22.\n";
                                cout << "Group " << Name_grp1 << "'s choice : ";
                                cin >> choice;
                               
                                diff = (choice - Grp1.lastNode());
                                last = Grp1.lastNode();

                                while (Grp1.search(choice) || (diff != -1 && diff != 1 && diff != 5))
                                {
                                    cout << "You had entered an invalid tile. Please key in the next step again: ";
                                    cin >> choice;
                                    diff = (choice - Grp1.lastNode());
                                }

                                while ((last % 5 == 0 && diff == 1) || (last % 5 == 1 && diff == -1))
                                {
                                    cout << "You had entered an invalid tile. Please key in the next step again: ";
                                    cin >> choice;
                                    diff = (choice - Grp1.lastNode());
                                }

                                ans = Map.search(choice);

                                if (ans)
                                {
                                    Grp1.appendNode(choice);
                                    resultGrp1 = true;
                                    if (choice == 22)
                                        compareGrp1 = true;
                                }
                                else
                                {
                                    Grp1.destroyLinkedList();
                                    Grp1.appendNode(3);
                                    resultGrp1 = false;
                                }

                                //after finish the move, set the condition to false so that the validation loop will stop
                                condition = false;
                            }

                            else if (card == 5)
                            {
                                cout << "You used Fate Card 5." << endl;

                                                                //card 5 will reset opponent's answer
                                Grp2.destroyLinkedList();       //hence, destroy the Group2's ans (linked list)
                                Grp2.appendNode(3);             //set the begining point to group 2 after list destroyed

                                g1card5 = true;                   //set the card5 checker to true so that the next round group 2 will be informed
                                resultGrp2 = false;             
                                condition = false;
                            }

                            else if (card == 6)
                            {
                                //card 6's function is to show a free answer to the players
                                cout << "You used Fate Card 6.\n"
                                     << endl;

                                //set up a random number to show a random correct tile
                                int seed = time(0);
                                srand(seed);
                                int rand_num = rand();

                                //validation of random number as the number need to be between 1 to 25
                                do
                                {
                                    rand_num = (1 + (rand() % 25));
                                } while (!Map.search(rand_num) || Grp1.search(rand_num) || rand_num == 22);
                                
                                //show players the map
                                int count = 21;
                                for (int i = 5; i > 0; i--)
                                {
                                    for (int j = 5; j > 0; j--)
                                    {
                                        bool ans = Grp1.search(count);
                                        if (count == rand_num)
                                        {
                                            //the char '#' show one of the correct tile that haven't explored by player
                                            cout << " # ";
                                        }
                                        else if (ans || count == 22)
                                        {
                                            //the char '*' show that the particular block which represent by number is in the linked list
                                            cout << " * ";
                                        }
                                        else
                                            //the char '@' show that the particular block is not in the linked list and represented the trap in the game
                                            cout << " @ ";
                                        count++;
                                    }
                                    cout << endl;
                                    count -= 10;
                                }
                                
                                //inform players that # symbol is the tips showed
                                cout << "\nThe # symbol showed one of the correct tile! Please remember it as it will disappear after Fate Round~\nGood Luck!!!" << endl;

                                condition = false;
                            }
                        }

                        //condition if player didnt used the card
                        else if (rply == "n" || rply == "N" || rply == "no" || rply == "No")
                        {
                            cout << "You didn't used the Fate Card.\n";
                            condition = false;      //end the loop
                        }

                        //validation if player insert a wrong ans
                        else
                        {
                            cout << "You had inserted an invalid comment. Please try again.";
                            cin >> rply;
                        }
                        cin.ignore();
                    }   //Group 1 Fate Card round end
                    

                    enterToContinue();
                    condition = true;       //reset the condition to true for group 2 validation loop
                    cout << endl;

                    if (card == 100)        //to stop the drawing process if card stack is empty 
                    {
                        condition = false;
                    }

                    //Group 2's turn for card drawing       //the algorithm is same as drawing process in group 1
                    cout << "\nThis is the card for Group " << Name_grp2 << ":\n"
                         << endl;
                    FC.pop(card);

                    cout << endl;

                    cout << "Do you want to use the card? (Y/N)  ";
                    cin >> rply;

                    while (condition)
                    {
                        if (rply == "y" || rply == "Y" || rply == "yes" || rply == "Yes")
                        {
                            if (card == 1)
                            {
                                cout << "You used Fate Card 1.\nBut there's nothing happen..." << endl;
                                condition = false;
                            }
                            
                            else if (card == 2)
                            {
                                cout << "You used Fate Card 2." << endl;
                                sskip2 = true;
                                condition = false;
                            }

                            else if (card == 3)
                            {
                                cout << "You used Fate Card 3." << endl;
                                skip2 = true;
                                condition = false;
                            }

                            else if (card == 4)
                            {
                                cout << "You used Fate Card 4." << endl;

                                Grp2.show_map();

                                if (resultGrp2 && turn > 2)
                                cout << "Your group choosed a correct tile in last round.\n\n";
                                else if (!resultGrp2 && turn > 2)
                                cout << "Your group choosed a wrong tile last round...\nYou have been returned to the starting point again.\n\n";

                                cout << "\nPlease key in the next step! Your end point will be at 22.\n";
                                cout << "Group " << Name_grp2 << "'s choice : ";
                                cin >> choice;

                                diff = (choice - Grp2.lastNode());
                                last = Grp2.lastNode();

                                while (Grp2.search(choice) || (diff != -1 && diff != 1 && diff != 5))
                                {
                                    cout << "You had entered an invalid tile. Please key in the next step again: ";
                                    cin >> choice;
                                    diff = (choice - Grp2.lastNode());
                                }

                                while ((last % 5 == 0 && diff == 1) || (last % 5 == 1 && diff == -1))
                                {
                                    cout << "You had entered an invalid tile. Please key in the next step again: ";
                                    cin >> choice;
                                    diff = (choice - Grp2.lastNode());
                                }

                                ans = Map.search(choice);

                                if (ans)
                                {
                                    Grp2.appendNode(choice);
                                    resultGrp2 = true;
                                    if (choice == 22)
                                        compareGrp2 = true;
                                }
                                else
                                {
                                    Grp2.destroyLinkedList();
                                    Grp2.appendNode(3);
                                    resultGrp2 = false;
                                }
                                condition = false;
                            }

                            else if (card == 5)
                            {
                                cout << "You used Fate Card 5." << endl;
                                Grp1.destroyLinkedList();
                                Grp1.appendNode(3);
                                g2card5 = true;
                                resultGrp1 = false;
                                cout << "Your opponents now are sent back to the begining tile! ;P" << endl;
                                condition = false;
                            }

                            else if (card == 6)
                            {
                                cout << "You used Fate Card 6.\n"
                                     << endl;
                                int seed = time(0);
                                srand(seed);
                                int rand_num = rand();

                                do
                                {
                                    rand_num = (1 + (rand() % 25));
                                } while (!Map.search(rand_num) || Grp2.search(rand_num) || rand_num == 22);

                                int count = 21;
                                for (int i = 5; i > 0; i--)
                                {
                                    for (int j = 5; j > 0; j--)
                                    {
                                        bool ans = Grp2.search(count);
                                        if (count == rand_num)
                                        {
                                            cout << " # ";
                                        }
                                        else if (ans || count == 22)
                                        {
                                            cout << " * ";
                                        }
                                        else
                                            cout << " @ ";
                                        count++;
                                    }
                                    cout << endl;
                                    count -= 10;
                                }

                                cout << "\nThe # symbol showed one of the correct tile! Please remember it as it will disappear after Fate Round~\nGood Luck!!!" << endl;
                                condition = false;
                            }
                        }

                        else if (rply == "n" || rply == "N" || rply == "no" || rply == "No")
                        {
                            cout << "You didn't used the Fate Card." << endl;
                            condition = false;
                        }

                        else
                        {
                            cout << "You had inserted an invalid comment. Please try again.";
                            cin >> rply;
                        }
                    }
                    //After 2 group drawing, inform user fate card round ended
                    string round = "FATE CARD ROUND ENDED";
                    printheader(round);
                }
            }
        }
        
        //increase the fate card round counter
        fateround++;
        cin.ignore();

    } while (!compareGrp1 && !compareGrp2);     //continue until a winner is exist

    //condition for winner informing
    string finish;

    //Condition for informing Group 1 victory and show the path they taken
    if (compareGrp1)
    {
        enterToContinue();
        finish = "CONGRATULATION!!! THE WINNER OF THIS GAME IS GROUP 1";
        printheader(finish);
        cout << "Group " << Name_grp1 << " had won the game!!!!!\n\n";
        cout << "This is the path taken by Group " << Name_grp1 << ":" << endl;
        Grp1.show_map();
    }

    //condition for informing Group 2 victory and show the path they taken
    else if (compareGrp2)
    {
        enterToContinue();
        finish = "CONGRATULATION!!! THE WINNER OF THIS GAME IS GROUP 2";
        printheader(finish);
        cout << "Group " << Name_grp2 << " had won the game!!!!!\n\n";
        cout << "This is the path taken by Group " << Name_grp2 << ":" << endl;
        Grp2.show_map();
    }

    //show players the real answer generated by the system
    cout << "\nThe solution of this game (All the correct block shown.): \n\n";
    Map.show_map();

    cout << "\nDid your group discover any shortcut? XD\n";
    enterToContinue();

    //inform players a game is finished
    finish = "GAME ENDED";
    printheader(finish);
}

//function to show the menu interface
void menu(DynamicQueue Queue, NumberList Map, NumberList Grp1, NumberList Grp2, string Name_grp1, string Name_grp2, string M1_grp1, string M2_grp1, string M1_grp2, string M2_grp2)
{
    //defination of variables
    char c;
    string d;

    //do while loop to allow looping the menu when players didn't select exit game
    do
    {
        //print the header of menu
        string menu_h = "MENU";
        printheader(menu_h);

        //show players the selection
        cout << "Welcome to Kaito Invisible Maze!\n";
        cout << "Please select one of the option below: \n";
        cout << "1. Rules\n";
        cout << "2. Start Game\n";
        cout << "3. Exit\n";
        cout << "Your choice: ";
        cin >> c;

        //validation for the player's selection
        while (c != '1' && c != '2' && c != '3')
        {
            cout << "Please select enter a correct option!\n";
            cout << "Your choice: ";
            cin >> c;
        }

        //if the selection is correct, bring players to the specific function 
        switch (c)
        {

        //to rules interface   
        case '1':
            rule();     
            break;

        //to start the game
        case '2':       
            play(Queue, Map, Grp1, Grp2, Name_grp1, Name_grp2, M1_grp1, M2_grp1, M1_grp2, M2_grp2);     
            break;

        //to quit the game
        case '3':
            string exit = "YOU HAD EXIT THE GAME. WISH TO SEE YOU NEXT TIME";                
            printheader(exit);
            break;
        }

        //after finished a function, ask the players are them want to back to the menu
        if (c != '3')
        {
            cout << "\nDo you wish to return to menu?(y/n)";
            cout << "Your choice: ";
            cin >> d;

            //validation of selection
            while (d != "y" && d != "Y" && d != "yes" && d != "Yes" && d != "n" && d != "N" && d != "no" && d != "No")
            {
                cout << "Please enter a correct character. (y/n)\t\t";
                cout << "Your choice: ";
                cin >> d;
            }

            //exit the game if the player want to
            if (d == "n" || d == "N" || d == "no" || d == "No")
            {
                string exit = "YOU HAD EXIT THE GAME. WISH TO SEE YOU NEXT TIME";
                printheader(exit);
            }
        }
        
    } while (c != '3' && !(d == "n" || d == "N" || d == "no" || d == "No"));    //if the selection wasn't exit, loop menu again
}

//function to ask player press enter to continue the next step  //Neatness purpose
void enterToContinue()
{
    cout << ">>>\t\t\t\t\t\t\t\t\tPress enter to continue..." << endl;
    cin.get();
}

//function to print a header of something                       //Neatness purpose
void printheader(string title)
{
    cout << "\n\n**************************************************************************************************\n";
    cout << "|\t" << left << setw(89) << title;
    cout << "|\n**************************************************************************************************\n";
}
