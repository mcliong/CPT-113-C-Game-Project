//Specific file for Stack Class
#ifndef FATECARDSTACK_H
#define FATECARDSTACK_H

//class for Stack
class FateCard
{
private:
    //declare a structure for stack
    struct StackNode
    {
        int value;              //int to store value
        StackNode *next;        //pointer to the next value
    };
    StackNode *stacktop;        //pointer to the top of the stack

public:
    FateCard();                 //contructor
    ~FateCard();                //destructor

    //stack operations
    void push(int num);         //stack up a value
    void pop(int &num);         //take the top value out from the stack
    bool isEmptyStack();        //to check is the stack empty
    void shuffle();             //to shuffle the card
    int cardfunction(int);      //to show the choosen card's function
};
#endif
