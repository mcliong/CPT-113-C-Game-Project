//specification file for DynamicQueue.cpp
#include <iostream>
#include "DynamicQueue.h"
using namespace std;

//consturctor for the queue which done the initialization
DynamicQueue::DynamicQueue()
{
    front = nullptr; //initialize front to nullptr
    rear = nullptr;  //initialize rear to nullptr
    numItems = 0;    //initialize numItems to nullptr
}

//destructor for the queue which call clear function to clear the queue
DynamicQueue::~DynamicQueue()
{
    clear(); //call clear function
}

//enqueue function to insert item at the rear of the queue
void DynamicQueue::enqueue(string item)
{
    QueueNode *newNode = nullptr;
    //create a new node
    newNode = new QueueNode;
    //store the new item
    newNode->name = item;

    //adjust front and rear as necessary
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    //update numItmes
    numItems++;
}

//dequeue function to remove the name at the front of the queue and copies it into item
void DynamicQueue::dequeue(string &item)
{
    QueueNode *temp = nullptr;
    if (isEmpty())
        cout << "The queue is empty.\n";
    else
    {
        //save the front node name in item
        item = front->name;
        //remove the front node and delete it
        temp = front;
        front = front->next;
        delete temp;
        //update numItems
        numItems--;
    }
}

//isEmpty returns true if the queue is empty, else false
bool DynamicQueue::isEmpty() const
{
    bool status;
    //check whether the queue is empty or not via the numItems
    if (numItems > 0)
        status = false;
    else
        status = true;
    return status;
}

//function clear dequeues all the elements in the queue
void DynamicQueue::clear()
{
    //dummy varaible for dequeue
    string name;
    while (!isEmpty())
        dequeue(name);
}

