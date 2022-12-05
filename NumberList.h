//specification header file for the NumberList class header
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

//class for the linked list
class NumberList
{
private:
	//declare a structure for the list
	struct ListNode
	{
		double value;		   //The value in this node
		struct ListNode *next; //To point to the next node
	};
	ListNode *head; //List head pointer
public:
	//constructor
	NumberList(); 
	//destructor
	~NumberList();
	//Linked list operations
	void appendNode(int);	  //append a node to the end of the list
	void destroyLinkedList(); //destroy the list
	int lastNode();			  //to find the last node's value of the list
	bool search(int);		  //to search value
	void show_map();		  //to print out the diagram of the map
	void displayList() const; //to display the linked list (for programmer checking purpose)
};
#endif
