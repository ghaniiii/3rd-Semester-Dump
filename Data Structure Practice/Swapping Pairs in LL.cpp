#include<iostream>
#include<string.h>

using namespace std;

struct Node{

	int number;
	Node *next;
	
};

class LL{
	private:
		Node *head;
		Node *temp;
		Node *temp1;
		
	public:
		LL(){
			head = NULL;
			temp = NULL;
			temp1 = NULL;
		}
		
		void print(){
			if(head == NULL){
				cout<<"No Nodes Added Till Now "<<endl;
				return;
			}
			
			temp = head;
			int i = 1;
			
			while(temp != NULL){
				cout<<i<<") "<<temp->number<<endl;
				
				temp = temp->next;
				i++;
			}
		}
		
		void add(){
			if(head == NULL){
				head = new Node;
				
				cout<<"Enter The Value In The First Node : ";
				cin>>head->number;
				
				head->next = NULL;
				
				return;
			}
			
			temp = head;
			
			while(temp->next != NULL){
				temp = temp->next;
			}
			
			temp1 = new Node;
			
			temp->next = temp1;
			
			temp1->next = NULL;
			
			cout<<"Enter The Value In The New Node : ";
			cin>>temp1->number;
		}
		
		
		void swapPairs(){
			temp = head;
			
			int tempNum;
			
			while(temp != NULL){
				if(temp->next != NULL){
					tempNum = temp->number;
					
					temp->number = temp->next->number;
					
					temp->next->number = tempNum;
					
					 
				}
				
				if(temp == NULL || temp->next == NULL){
					return;
				}
				
				temp = temp->next->next;
			}
		}
		
		~LL(){
			delete head;
			delete temp;
			delete temp1;
		}
};



int main(){
	int option;
	LL A;
	
	do{
		
		cout<<"Choose An Option :- "<<endl;
		cout<<"1. To Add A Node"<<endl;
		cout<<"2. To Swap Each Pair"<<endl;
		cout<<"3. Print"<<endl<<endl;
		
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			A.add();
		}
		else if(option == 2){
			A.swapPairs();
		}
		else if(option == 3){
			A.print();
		}
		
		
		
	}
	while(option <= 3);
}