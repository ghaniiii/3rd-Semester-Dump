#include<iostream>
#include<string.h>

using namespace std;

struct Node{
	int info;
	Node *next;
	Node *prev;	
};


class DLL{
	private:
		Node *temp;
		Node *temp1;
		Node *head;
		
	public:
		DLL(){
			temp = NULL;
			temp1 = NULL;
			head = NULL;
		}
		
		void add(){
			
			int key;
			char choice;
			
			if(head == NULL){
				cout<<"This Is The First Node Of The List "<<endl<<endl;
				
				head = new Node;
				
			 	head->prev = NULL;
			 	
			 	head->next = NULL;
			 	
			 	cout<<"Enter The Info In The First Node : ";
			 	cin>>head->info;
			 	
			 	return;
			}
			
				cout<<"Do You Need A Key To Add After That ? : ";
				cin>>choice;
				
				if(choice == 'y'){
					
					cout<<"Enter A Key To Add After That Number : ";
					cin>>key;
					
					temp = head;
					
					while(temp != NULL){
						
						if(temp->info == key){
							temp1 = new Node;
							
							cout<<"Enter The Number In the New Node : ";
							cin>>temp1->info;
							
							temp1->next = temp->next;
							temp->next = temp1;
							
							if(temp1->next != NULL){
								temp1->next->prev = temp1;
							}
							
							temp1->prev = temp;
							
							temp = temp->next;
							
						}
						
						
						temp = temp->next;
					}
					
				}
				else{
					
					temp = head;
					
					while(temp != NULL){
						
						if(temp->next == NULL){
							temp1 = new Node;
							
							cout<<"Enter The info In The New Node : ";
							cin>>temp1->info;
							
							temp1->next = NULL;
							
							temp->next = temp1;
							
							temp1->prev = temp;
							
							temp = temp->next;
							
						}
						
						temp = temp->next;
						
					}
					
				}
			
				
				
			
		}
		
		
		void print(){
			if(head == NULL){
				cout<<"No Nodes Added Yet "<<endl<<endl;
				return;
			}
			
			temp = head;
			
			cout<<endl<<endl;
			
			while(temp != NULL){
				
				cout<<temp->info<<"  ";
				
				
				temp = temp->next;
			}
			
			cout<<endl<<endl;
		}
		
		
		void del(){
			
			int todelete;
			
			if(head == NULL){
				cout<<"No Node To Delete "<<endl<<endl;
				return;
			}
			
			
			cout<<"Enter The Number To Delete : ";
			cin>>todelete;
			
			
			
			while(head != NULL && head->info == todelete){
				
				temp = head;
				head = head->next;
				
				delete temp;
				
				if(head != NULL){
					
					head->prev = NULL;
					
				}
				
			
			}
			
			
			temp = head;
			
			
			
			while(temp != NULL){
				
				if(temp->info == todelete){
					
					temp1 = temp;
					
					temp->prev->next = temp->next;
					
					if(temp->next != NULL){
						
						temp->next->prev = temp->prev;
						
					}
					
					
					
					temp = temp1->prev;
					
					delete temp1;
					
				}

				
				temp = temp->next;
			}
		}
};



int main(){
	
	DLL A;
	int input;
	
	do{
		cout<<"1. Add"<<endl;
		cout<<"2. Print"<<endl;
		cout<<"3. Delete"<<endl;
		cin>>input;
		
		
		if(input == 1){
			A.add();
		}
		else if(input == 2){
			A.print();
		}
		else if(input == 3){
			A.del();
		}
		
		cout<<endl<<endl;
		
	}
	while(input <= 3);
	
}