#include<iostream>
#include<string.h>

struct Node{
	int val;
	Node * next;
	
	Node(){
		next = NULL;
	}
};

class CLL{
	public:
	
	Node *head;
	Node *temp;
	Node *temp2;
	int number;
	
	CLL(){
		head = NULL;
		temp = NULL;
		temp2 = NULL;
	}
	
	void add(){
		if(head == NULL){
			head = new Node;
			head->info = number;
			head->next = head;
			return;
		}
		
		temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		
		temp2 = new Node;
		temp2->val = number;
		
		temp2->next = temp->next;
		temp->next = temp2;
		
		
	}
		
};