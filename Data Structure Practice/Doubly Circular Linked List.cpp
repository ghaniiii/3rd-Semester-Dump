#include<iostream>

using namespace std;

struct Node{
	
	int number;
	Node *next;
	Node *prev;
		
};

class DCLL{
	private:
		Node *head;
		Node *temp;
		Node *temp1;
		
	public:
		DCLL(){
			head = NULL;
			temp = NULL;
			temp1 = NULL;
		}
		
		void add(){
			
			int key;
			
			if(head == NULL){
				head = new Node;
				head->next = head;
				head->prev = head;
				
				cout<<"Enter The Value In The First Node : ";
				cin>>head->number;
				
				return;
				
			}
			
			cout<<"Enter The Key After Which You Want To Add The Number : ";
			cin>>key;
			
			
			if(head->number == key && head->next == head){
				
				temp = new Node;
				
				head->next = temp;
				head->prev = temp;
				
				temp->prev = head;
				temp->next = head;
				
				cout<<"Enter The Number That You Want To Enter Into The Node : ";
				cin>>temp->number;
				
				return;
				
			}
			
			temp = head;
			
			while(temp->next != head){
				if(temp->number == key){
					temp1 = new Node;
					
					temp1->next = temp->next;
					temp1->prev = temp;
					
					temp->next->prev = temp1;
					
					cout<<"Enter The Number That You Want To Enter Into The Node : ";
					cin>>temp1->number;
					
					temp->next = temp1;
					
					return;
				}
				temp = temp->next;
			}
			
			if(temp->number  == key){
					temp1 = new Node;
					
					temp1->next = temp->next;
					temp1->prev = temp;
					
					cout<<"Enter The Number That You Want To Enter Into The Node : ";
					cin>>temp1->number;
					
					temp->next->prev = temp1;
					
					temp->next = temp1;
					
					return;
			}
			
			
		}
		
		
		void del(){
			
			int key;
			
			if(head == NULL){
				cout<<"No Nodes Added Till Now To Delete "<<endl;
				
				return;
			}
			
			cout<<"Enter The Value That You Want To Delete : ";
			cin>>key;
			
			
			
			temp = head;
			
			
			while(head->number == key && head->next != head){
				
				if(head->next == head){
					delete head;
					head = NULL;
				}
				
				temp1 = head;
				
				head = head->next;
				
				head->prev->prev->next = head;
				
				head->prev = head->prev->prev;
				
				
				
				delete temp1;	
				
			}
			
			if(head->number == key && head->next == head){
				delete head;
				head = NULL;
				
				return;
			}
			
			
			temp = head;
			
			do{
				
				if(temp->number == key){
					temp1 = temp;
					
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					
					temp = temp->prev;
					
					delete temp1;
					
				}
				
				temp = temp->next;
				
			}
			while(temp != head);
			
			
			
		}
			
		void display(){
			if(head == NULL){
				cout<<"No Nodes Added Till Now To Print"<<endl;
				
				return;
			}
			
			temp = head;
			
			do{
				cout<<temp->number<<endl;
				
				temp = temp->next;
			}
			while(temp != head);
			

		}
};



int main(){
	DCLL A;
	int option;
	
	do{
		
		cout<<"1. Add A Node"<<endl;
		cout<<"2. Delete A Node"<<endl;
		cout<<"3. To Print All Nodes"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			A.add();
		}
		else if(option == 2){
			A.del();
		}
		else if(option == 3){
			A.display();
		}
		
	}
	while(option <= 3 );
}