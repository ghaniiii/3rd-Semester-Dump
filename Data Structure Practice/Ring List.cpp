#include<iostream>
#include<string.h>

using namespace std;

struct Node{
	int info;
	Node *next;	
};


class RL{
	private:
		Node *temp;
		Node *temp1;
		Node *head;

	public:
		RL(){
			temp = NULL;
			temp1 = NULL;
			head = NULL;
		}
		
		void add(){
			
			char choice;
			int key;
			
			if(head == NULL){
				head = new Node;
				head->next = head;
				
				cout<<"Enter The Info In The First Node : ";
				cin>>head->info;
				
				return;
			}
			
			cout<<"Do You Need A Key ? : ";
			cin>>choice;
			
			if(choice == 'y'){
				
				cout<<"Enter The Number That You Want To Add After : ";
				cin>>key;
				
				temp = head;
				
				
				while(temp->next != head){
					if(temp->info == key){
						temp1 = new Node;
						
						cout<<"Enter The Info In The New Node : ";
						cin>>temp1->info;
						
						temp1->next = temp->next;
						
						temp->next = temp1;
						
						temp = temp1;
						
						return;
					}
					
					temp = temp->next;
					
					if(temp->info == key){
						
						temp1 = new Node;
						
						cout<<"Enter The Info In The New Node : ";
						cin>>temp1->info;
						
						temp1->next = temp->next;
						
						temp->next = temp1;
						
						temp = temp1;
						
						return;
					}
				}
				
				temp = head;
				
				if(head->next == head && head->info == key){
					
					temp = new Node;
					
					cout<<"Enter The Value in The Node : ";
					cin>>temp->info;
					
					head->next = temp;
					
					temp->next = head;
					
					return;
					
				}
				
				
				
			}
			else{
				
				temp = head;
				
				if(head->next == head){
				
					temp1 = new Node;
					
					cout<<"Enter The Info In The New Node : ";
					cin>>temp1->info;
					
					temp->next = temp1;
					
					temp1->next = temp;
					
					return;
					
				}
				
				temp = head;
				
				while(temp->next != head){
				
				
					
					temp = temp->next;
					
					if(temp->next == head){
						temp1 = new Node;
						
						cout<<"Enter Info In The New Node : ";
						cin>>temp1->info;
						
						temp->next = temp1;
						
						temp1->next = head;
						
						temp = temp1;
						
						return;
					}
				
					
					
				}
			}
			
		}
		
		void print(){
			
			temp = head;
			
			if(head == NULL){
				cout<<"No Nodes Entered Till Now "<<endl<<endl;
				return;
			}
			
			do{
				cout<<temp->info<<" ";
				
				temp = temp->next;
				
				
			}while(temp != head);
			
		}
		
		void del(){
	
			int ToFind;

			cout<<"Enter The Number That You Want To Delete : ";
			cin>>ToFind;
			
			temp  = head;
			
			if(head == NULL){
				cout<<"No Nodes Added Till Now "<<endl<<endl;
				return;
			}
			
			if(head->next == head && head->info == ToFind){
				delete head;
				head = NULL;
				
				return;
			}
			
			
			
			temp = head;
			
	        while(temp->next != head){
	        	if(temp->next->info == ToFind){
	        		
	        		temp1 = temp->next;
	        		
	        		temp->next = temp->next->next;
	        		
	        		delete temp1;
	        		
	        		return;
	        		
				}
				else{
					temp = temp->next;
				}
				
				
				if(temp->next->info == ToFind && temp->next == head){
					
					temp1 = temp->next;
	        		
	        		temp->next = temp->next->next;
	        		
	        		head = temp;
	        		
	        		delete temp1;
	        		
	        		return;
	        		
	        		if(head->info == ToFind){
	        			
	        			
						delete head;
						
						head = NULL;
						
						return;
					
					}
						
				}
				
				
				
				
			}
			
				
				
				
		}
	
	
	};
	
	
	
int main(){
	RL A;
	int option;
	
	
	do{
		cout<<"1. Add"<<endl;
		cout<<"2. Print"<<endl;
		cout<<"3. Delete"<<endl;
		
		cout<<"Enter Your Option : ";
		cin>>option;
		
		
		if(option == 1){
			A.add();
		}
		else if(option == 2){
			A.print();
		}
		else if(option == 3){
			A.del();
		}
		
		cout<<endl<<endl;
		
	}while(option <= 3);
}




