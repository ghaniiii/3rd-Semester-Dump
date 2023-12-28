#include<iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Node{

	int number;
	Node *next;
	
};

class CRL{
	Node *head;
	Node *temp;
	Node *temp1;
	Node *Fprint;
	
	public:
		CRL(){
			
			head = NULL;
			temp = NULL;
			temp1 = NULL;
			Fprint = NULL;
			
		}
		
		bool insertValues(){
			
			bool inserted = false;
			
			int key;
			
			if(head == NULL){
				head = new Node;
				
				head->next = head;
				
				cout<<"Enter The Number In The First Node : ";
				cin>>head->number;
				
				inserted = true;
				
				return inserted;
				
			}
			
			cout<<"Enter The Key To Find The Number: ";
			cin>>key;
			
			
			
			if(head->number == key && head->next == head){
				
				temp = new Node;
				head->next = temp;
				temp->next = head;
				
				cout<<"Enter The Value In The Node : ";
				cin>>temp->number;
				
				inserted = true;
				
				return inserted;
			}
			
			temp = head;
			
			while(temp->next != head){
				if(temp->number == key){
					temp1 = new Node;
					temp1->next = temp->next;
					cout<<"Enter The Number In The new Node : ";
					cin>>temp1->number;
					
					temp->next = temp1;
					
					inserted = true;
					
					return inserted;
				}
				
				temp = temp->next;
			}
			
			if(temp->number == key){
				
				temp1 = new Node;
				
				cout<<"Enter The Number In The new Node : ";
				cin>>temp1->number;
				
				temp1->next = temp->next;
				
				
				
				temp->next = temp1;
				
				
				
				inserted = true;
				
				return inserted;
			}
			
			return inserted;
			
		}
		
		
		void startRound(){
			
			if(head == NULL){
				cout<<"No Nodes Added To Start Add 10 Nodes First : "<<endl;
				return;
			}
			
			
			
			int toStart = rand()%6;
			
			temp = head;
			
			cout<<"The Node That It Will Start The Game From Is : "<<toStart<<endl<<endl;
			
			cout<<"Head Value : "<<head->number<<endl;;
			
			for(int i=1; i< toStart ;i++){
				temp = temp->next;
			}
			
			char option;
			int number = 3;
			
			do{
				
				
				for(int i=1;i<= number; i++){
					temp = temp->next;
				}
				
				
				
				temp1 = temp->next;
				
				temp->next = temp1->next;
				
				
				cout<<"Number Deleted Is : "<<temp1->number<<endl<<endl;
				
				if(temp1 == head){
					head = head->next;
				}
				
				delete temp1;
				temp1 = NULL;
				
				print();
				
				if(head->next == head){
					cout<<"The Winner is : "<<head->number<<endl;
					return;
				}
				
				
			
				cout<<"Do You Want To Play Another Round ?? : ";
				cin>>option;
				
				
				
			}
			while(option == 'y');
			
				
			
			
		}
		
		
		void print(){
			
			Fprint = head;
			int i=1;
			
			while(Fprint->next != head){
				cout<<i<<") "<<Fprint->number<<endl;
				
				Fprint = Fprint->next;
				i++;
			}
			
			cout<<i<<") "<<Fprint->number<<endl;
			
			
		}
};


int main(){
	CRL A;
	int option;
	int counter = 0;
	
	srand(time(NULL));
	
	do{
		
		cout<<"1. Enter Value"<<endl;
		cout<<"2. Start Game"<<endl;
		cout<<"3. Print"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			if(A.insertValues()){
				counter++;	
			}
			
		}
		else if(option == 2){
			if(counter >= 10){
				A.startRound();
			}
			else{
				cout<<"You Need Atleast 10 Values To Start The Game"<<endl<<endl;
			}
		}
		else if(option == 3){
			A.print();
		}
		
		
	}
	while(option != 4);
}