//specification file for the DynamicQueue class header
#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H
#include <iostream>
using namespace std;

//class for the queue
class DynamicQueue
{
private:
    //declare a structure for the queue
    struct QueueNode
    {
        string name;            //string in a node
        struct QueueNode *next; //pointer to the next node
    };
    QueueNode *front; //the front of the queue
    QueueNode *rear;  //the rear of the queue
    int numItems;     //number of items in the queue
public:
    DynamicQueue();  //constructor
    ~DynamicQueue(); //destructor

    //queue operations
    void enqueue(string);   //insert into queue
    void dequeue(string &); //remove from queue
    bool isEmpty() const;   //to check whether the queue is empty or not
    void clear();           //to clear the queue
};

#endif
