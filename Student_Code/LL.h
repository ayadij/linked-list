#pragma once
#include <iostream>
//#include <sstream>
//#include <string>
#include "LinkedListInterface.h"

using namespace std;
template<typename T>


class LL : public LinkedListInterface<T>
{
private:



	//define node structure
	struct Node
	{
		T data;
		Node* next;

		//default constructor
		Node();

		//data containing construtor
		Node(T data, Node* next) : data(data), next(next) {};

		//deconstructor
		~Node(){}; //make virutal?

	};

	Node* head;
	int sizecount;


	//search through the linked list for duplicates...returns true if found, false if not
	bool uvalue(T value)
	{
		bool uvalue = true;
		Node* temp = head;
		while (uvalue == true && temp != NULL){
			if(value == temp->data){
				uvalue = false;
			} else {
				temp = temp->next;
			}
		}
		temp = NULL;
		return uvalue;
	}

	//bool emptylist(T value){}



public:

	LL();
	~LL() //make virtual??
	{
		clear();
	};





	/*	insertHead
		A node with the given value should be inserted at the beginning of the list.
		Do not allow duplicate values in the list. */
	void insertHead(T value) //PART1
	{
		//if list is empty, creates a node at the beginning of the list
		if (head == NULL){
			head = new Node(value);
			sizecount++;
			return;
		} else {
			return;
		}

		//check for a unique value
		//if(unique){};
		bool duplicate = false;
		Node * temp = head;
		while (duplicate == false && temp != NULL){
			if (value == temp->data){
				duplicate = true;
			}
			temp = temp->next;
		}
		temp = NULL;



	}





	/*	insertTail
		A node with the given value should be inserted at the end of the list.
		Do not allow duplicate values in the list.*/
	void insertTail(T value) //PART1
	{
		//if list is empty, creates a node at the beginning of the list
		if (head == NULL){
			head = new Node(value);
			sizecount++;
			return;
		} else {
			return;
		}

		//check for unique value
		//bool unique = uniquevalue(value);

		//if unique value, insert a new head;
		//if(unique) {}



	}



	/*	insertAfter
		A node with the given value should be inserted immediately after the
		node whose value is equal to insertionNode.
		A node should only be added if the node whose value is equal to
		insertionNode is in the list. Do not allow duplicate values in the list. */
	void insertAfter(T value, T insertionNode) //PART1
	{

		//check for unique value
		//bool unique = uniquevalue(value);
		//bool exists = !uniquevalue(insertionNode);



		//insert a vlaue after if it exists and if it is unique
		//if(unique && exists){}




	}



	/*	remove
		The node with the given value should be removed from the list.
		The list may or may not include a node with the given value. */
	void remove(T value) //PART2
	{


	}



	/*	clear
		Remove all nodes from the list.*/
	void clear()
	{
		if (head == NULL){
			return;
		}

		Node* temp = head;
		Node* curr;

		while (temp->next != NULL){ //shiiiiit did i mix up my temp and curr? nah im good
			curr = temp;
			temp = temp-> next;
			delete curr;
		}

		delete temp;
		temp = NULL;
		curr = NULL;
		head = NULL;
		sizecount = 0;

	}

	/*	at
		Returns the value of the node at the given index. The list begins at
		index 0.
		If the given index is out of range of the list, throw an out of range exception.*/
	T at(int index)
	{
		if(index >= size() || index < 0){
			return NULL;
		} else {
			Node<T>* n = head
		}
	}

	/*	size
		Returns the number of nodes in the list. */
	int size()
	{
		Node<T>* n = head;
		int i = 0;
		while (n != NULL){
			n = n->next;
			i++;
		}
		return i;
	}

};












template<typename T>
class Node
{

public:

	T data;
	Node<T>* next;

	//constructor
	Node(T value, Node<T>* n = NULL){
		data = value;
		next = n;
	}


	T getData(){
		return data;
	}

	void setData(T newdata){
		data = newdata;
	}

	Node<T>* getNext(){
		return next;
	}

	void setNext(Node<T>* n){
		next = n;
	}


};









































#pragma once
#include "LinkedListInterface.h"
#include <stdexcept>
#include <iostream>
using namespace std;
template<class T>
class List:public LinkedListInterface<T>
{
	struct Node
	{
		T value;
		Node* next;
	};
	//int count;
	Node* head;
	Node* tail;
public:
	List():head(NULL),tail(NULL){}
	~List()
	{
		clear();
	}

	T getTail()
	{
		return tail->value;
	}

	T getHead()
	{
		return head->value;
	}

	void insertHead(T value)
	{
		if(check_for_duplicate(value))
		{
			return;
		}
		Node* n=new Node();
		n->value=value;

		if(head==NULL)		//is the list empty?
		{
			head=n;
			tail=n;
			n->next=NULL;
		}
		else
		{
			n->next=head;
			head=n;
		}
		//print();
	}
	void print()
	{
		Node* n=head;
		int icount=0;
		while(icount<size())
		{
			cout<<n->value<<", ";
			n=n->next;
			icount++;
		}
		cout<<endl;
	}
	void insertTail(T value)
	{
		if(check_for_duplicate(value))
		{
			return;
		}
		Node* n=new Node();
		n->value=value;
		if(tail==NULL)
		{
			head=n;
		}
		else
		{
			tail->next=n;
		}
		n->next=NULL;
		tail=n;
	}

	void insertAfter(T value, T insertionNode)
	{
		if(check_for_duplicate(value))
		{
			return;
		}
		Node* inode=head;
		while(inode!=NULL)
		{
			if(inode->value==insertionNode)
			{
				Node* n=new Node();
				n->value=value;
				if(inode==tail)
				{
					tail=n;
					n->next=NULL;
					inode->next=n;
				}
				else
				{
					n->next=inode->next;
					inode->next=n;
				}
			}
			inode=inode->next;
		}

	}
	void remove(T value)
	{
		if(check_for_duplicate(value))
		{
			Node* current=head;
			Node* prev;
			while(current->value!=value)
			{
				prev=current;
				current=current->next;
			}
			if(current==head)
			{
				head=current->next;
				delete current;
				if(size()==0)
				{
					head=NULL;
					tail=NULL;
				}
				return;
			}
			else if(current==tail)
			{
				tail=prev;
				prev->next=NULL;
				delete current;
				if(size()==0)
				{
					head=NULL;
					tail=NULL;
				}
				return;
			}
			else
			{
				prev->next=current->next;
				delete current;
				if(size()==0)
				{
					head=NULL;
					tail=NULL;
				}
				return;
			}

		}
		else return;

	}

	void clear()
	{
		while(size()>0)
		{
			Node* n=head;
			//T value=n->value;
			head=head->next;
			//count--;
			delete n;
		}
		head=NULL;
		tail=NULL;
	}

	T at(int index)
	{
		Node* n=head;
		int icount=0;
		if(index<0||index>size()-1)
		{
			throw out_of_range("OUT OF RANGE");
		}
		else
		{
			while(icount<index)
			{
				n=n->next;
				icount++;
			}
			return n->value;
		}
	}

	bool check_for_duplicate(T value)
	{
		Node* n=head;
		while(n!=NULL)
		{
			if(n->value==value)
			{
				return true;
			}
			n=n->next;
		}
		return false;
	}
	int size()
	{
		int listcount=0;
		Node* n=head;
		if(head==NULL)
		{
			return 0;
		}
		while(n!=NULL)
		{
			listcount++;
			n=n->next;
		}
		return listcount;
	}
};













