#include "NumberList.h"
#include <iostream>
using namespace std;

//Constructor
NumberList::NumberList()
{
	head = nullptr; 
}

//function to append a node to the end of the list
void NumberList::appendNode(int num)
{
    ListNode *newNode; //to point to a new node
    ListNode *nodePtr; //to move through the list
	
    //allocate a new node and store num there
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    //if there is no node in the list which means head point to nullptr
    //make newNode the first node
    if (!head)
        head = newNode;
    //otherwise, insert newNode at the end of the list
    else
    {
        //initialize nodePtr to the head of the lsit
        nodePtr = head;
        //to find the last node in the list
        while (nodePtr->next)
            nodePtr = nodePtr->next;
        //to insert newNode as the last node of the list
        nodePtr->next = newNode;
    }
}

//function to destroy the list
void NumberList::destroyLinkedList()
{
    ListNode *nodePtr;  //to traverse the list
    ListNode *nextNode; //to point to the next node

    //position nodePtr at the head of the list
    nodePtr = head;

    //while nodePtr is not at the end of the list
    while (nodePtr != nullptr)
    {
        //save a pointer to the next node
        nextNode = nodePtr->next;
        //delete the current node
        delete nodePtr;
        //position nodePtr at the next node
        nodePtr = nextNode;
    }

    head = nullptr;
}

//function to find the last node's value of the list
int NumberList::lastNode()
{
    ListNode *nodePtr; //to move through the list
    nodePtr = head;    //position nodePtr at the head of the list
    //while the next node which point by nodePtr is not nullptr
    while (nodePtr->next != nullptr)
        //nodePtr move to its next node
        nodePtr = nodePtr->next;
    //return the value of the nodePtr when the next node pointed by nodePtr is nullptr
    return nodePtr->value;
}

//function to determine whether the particular value is in the list or not
bool NumberList::search(int num)
{
    //initialize found to false
    bool found = false;
    ListNode *nodePtr; //to move through the list
    nodePtr = head;    //position nodePtr at the head of the list
                       //while the next node pointed by nodePtr is not nullptr and the value is not found
    while (nodePtr != nullptr && !found)
    {
        //if nodePtr value equal to the num
        if (nodePtr->value == num)
        {
            //change found equal to true
            found = true;
            //return the variable found
            return found;
        }
        else
            //otherwise, move nodePtr to its next node
            nodePtr = nodePtr->next;
    }
    //return the variable found
    return found;
}

//function to display the list
void NumberList::displayList() const
{
    ListNode *nodePtr; //to move throught the list
    nodePtr = head;    //position nodePtr at the head of the lsit

    //start to print the list
    cout << "head -> ";
    //while nodePtr not equal to nullptr
    while (nodePtr)
    {
        //print nodePtr value
        cout << nodePtr->value << " -> ";
        //move nodePtr to its next node
        nodePtr = nodePtr->next;
    }
    //the end of the list point to null so print null
    cout << "null" << endl;
}

//function to print out the diagram of the map
void NumberList::show_map()
{
    //make sure the printed diagram of map fulfill all the condition
    int count = 21;
    for (int i = 5; i > 0; i--)
    {
        for (int j = 5; j > 0; j--)
        {
            bool ans = search(count);
            if (ans || count == 22)
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
}

//destructor to destroy the list
NumberList::~NumberList()
{
    ListNode *nodePtr;  //to traverse the list
    ListNode *nextNode; //to point to the next node

    //position nodePtr at the head of the list
    nodePtr = head;

    //while nodePtr is not at the end of the list
    while (nodePtr != nullptr)
    {
        //save a pointer to the next node
        nextNode = nodePtr->next;
        //delete the current node
        delete nodePtr;
        //position nodePtr at the next node
        nodePtr = nextNode;
    }
}
