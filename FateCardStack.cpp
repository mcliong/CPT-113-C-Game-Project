//specification file for FateCardStack.cpp
#include "FateCardStack.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Constructor for the Stack which done the initialization
FateCard::FateCard()
{
	stacktop = nullptr; //initialize the top of stack into nullptr
	shuffle();			//shuffle the card and stack up for further usage
}

//Destructor for the Stack which will delete all the stack if stack is not empty
FateCard::~FateCard()
{
	StackNode *temp; //create a temporary stack

	while (stacktop != nullptr) //when the stacktop is not nullptr (empty stack),
	{							//continue the loop to delete the stack until the stack is empty
		temp = stacktop->next;
		stacktop = stacktop->next;
		delete temp;
	}
}

//push operantion is used to insert a value into the stack
void FateCard::push(int num)
{

	StackNode *newNode = nullptr; //set a stack pointer that point to null to store the value
								  //that going to put into the stack
	newNode = new StackNode;
	newNode->value = num;

	if (isEmptyStack()) // if the stack is empty
	{					//set the number as the first top of the stack
		stacktop = newNode;
		newNode->next = nullptr;
	}
	else //else, put the new number onto the previous stack
	{
		newNode->next = stacktop;
		stacktop = newNode;
	}
}

//pop operation is used to take a value out from the stack
void FateCard::pop(int &num)
{
	StackNode *temp = nullptr; //set a stack pointer to save the value that going to take out

	if (isEmptyStack()) //if the stack is empty, tell the user about that
	{
		cout << "But....\nThe Fate card are finish redeemed." << endl;
		cout << "Hence, start from now there'll be no more Fate Round~\nGood Luck for your final rush!!!" << endl;
		num = 100; //100 is the value that going to take out if the stack is empty
	}
	else //else, take out the value and assign it to num
	{
		num = stacktop->value;
		temp = stacktop->next;
		delete stacktop;
		stacktop = temp;
		cout << "Your Fate card is :" << endl;
	}

	cardfunction(num); //after take out a value from the stack, send it into cardfunction operation
	cout << endl;	   //to show how the value(card) works
}

//isEmptySatck returns true if the stack is empty, else false
bool FateCard::isEmptyStack()
{
	bool status;

	//check whether the stack is empty or not via check the existance of stacktop
	if (!stacktop)
		status = true;
	else
		status = false;
	return status;
}

//shuffle operations will shuffle 16 cards randomly and set it as a stack
void FateCard::shuffle()
{
	int seed = time(0); //set up the seed using time(0)to get a completely
	srand(seed);		//random number for random stacking

	bool condition = true; //set up variables
	int counter = 0;
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;

	while (condition) //set up a while loop to take a random number between
	{				  //1 to 6 (as there's 6 type of cards)
		int num = rand();
		if (num <= 6 && num >= 1)
		{
			if (num == 1)
			{				 //when the random number is x( 1<= x <= 7),
				if (c1 != 4) //and the counter of number x still not fulfull the needs
				{
					push(num); //insert the x into the stack,
					c1 += 1;   //update the counter for number x (until the quantity needs)
					counter++; //update the counter of the total number of cards
				}			   //(only 16 cards will inserted into stack)
			}
			else if (num == 2)
			{
				if (c2 != 2)
				{
					c2 += 1;
					push(num);
					counter++;
				}
			}
			else if (num == 3)
			{
				if (c3 != 2)
				{
					c3 += 1;
					push(num);
					counter++;
				}
			}
			else if (num == 4)
			{
				if (c4 != 4)
				{
					c4 += 1;
					push(num);
					counter++;
				}
			}
			else if (num == 5)
			{
				if (c5 != 1)
				{
					c5 += 1;
					push(num);
					counter++;
				}
			}
			else if (num == 6)
			{
				if (c6 != 3)
				{
					c6 += 1;
					push(num);
					counter++;
				}
			}
		}

		if (counter == 16)				//when the counter of total number of card reach 16
			condition = false;			//set the condition to false and stop the loop
	}
}

//cardfunction is a operation to show the user what the number(card)'s function
int FateCard::cardfunction(int num)
{
	switch (num)						//switch to the respective number(card) to show their function 
	{
	case 1:
		cout << " _____ " << endl;
		cout << "|A _  |" << endl;
		cout << "| ( ) |		Card No.1" << endl;
		cout << "|(_'_)|		Card function:" << endl;
		cout << "|  |  |			Empty" << endl;
		cout << "|____V|" << endl;
		break;
	case 2:
		cout << " _____ " << endl;
		cout << "|2    |" << endl;
		cout << "|  &  |		Card No.2" << endl;
		cout << "|     |		Card function:" << endl;
		cout << "|  &  |			You have a chance skip yourself one turn " << endl;
		cout << "|____Z|" << endl;
		break;
	case 3:
		cout << " _____ " << endl;
		cout << "|3    |" << endl;
		cout << "| & & |		Card No.3" << endl;
		cout << "|     |		Card function:" << endl;
		cout << "|  &  |			You have a chance to skip your opponent one turn" << endl;
		cout << "|____E|" << endl;
		break;
	case 4:
		cout << " _____ " << endl;
		cout << "|4    |" << endl;
		cout << "| & & |		Card No.4" << endl;
		cout << "|     |		Card function:" << endl;
		cout << "| & & |			You have another chance to walk one turn" << endl;
		cout << "|____h|" << endl;
		break;
	case 5:
		cout << " _____ " << endl;
		cout << "|5    |" << endl;
		cout << "| & & |		Card No.5" << endl;
		cout << "|  &  |		Card function:" << endl;
		cout << "| & & |			You have a chance to force your opponent jump back to the begining" << endl;
		cout << "|____Z|" << endl;
		break;
	case 6:
		cout << " _____ " << endl;
		cout << "|6    |" << endl;
		cout << "| & & | 		Card No.6" << endl;
		cout << "| & & |		Card function:" << endl;
		cout << "| & & |			You have a chance to get a free answer" << endl;
		cout << "|____9|" << endl;
		break;

	case 100:		//if the stack is empty, the number will change into 100 and show nothing				
		break;
	
	default:		//if the number sent are not 1 to 6 or 100, then bug happened
		cout << "bug";
		break;
	}
	return num;		//return the number(card) 
}
