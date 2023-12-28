#include<iostream>
#include<string.h>

using namespace std;

struct Node{
	
	int info;
	Node *next;
		
};


class Stack{
	Node *temp;
	Node *top;
	int limit;
	int length;
	
	public:
		Stack(int limit){
			temp = NULL;
			top = NULL;
			length = 0;
			this->limit = limit;
			
		}
		
		void push(){
			if(length == limit){
				cout<<"The Stack Is Full"<<endl;
				cout<<"Please Pop Something To Push Again"<<endl<<endl;
				return;
			}
			
			temp = new Node;
			cout<<"Enter The Info In The New Node : ";
			cin>>temp->info;
			temp->next = top;
			top = temp;
			length++;
		}
		
		void pop(){
			if(top == NULL){
				cout<<"No More Nodes To Pop"<<endl<<endl;
				return;
			}
			
			temp = top;
			top = top->next;
			
			cout<<"The Element Popped Was : "<<temp->info<<endl<<endl;
			
			delete temp;
			length--;
			
		}
		
		int returnTop(){
			if(isEmpty()){
				return -1;
			}
			else{
				return top->info;	
			}
			
		}
		
		bool isEmpty(){
			if(top == NULL){
				return true;
			}
			
			return false;
		}
		
};


int main(){
	
	int option;
	Stack A(10);
	
	do{
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Return Top"<<endl;
		cout<<"4. Is Empty"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		
		if(option == 1){
			A.push();
		}
		else if(option == 2){
			A.pop();
		}
		else if(option == 3){
			if(A.isEmpty() == false){
				cout<<"The Top Element Is : "<<A.returnTop()<<endl<<endl;
			}
			else{
				cout<<"No Nodes To Return"<<endl<<endl;
			}
			
		}
		else if(option == 4){
			if(A.isEmpty()){
				cout<<"Stack Is Empty"<<endl<<endl;
			}
			else{
				cout<<"Stack Is Not Empty"<<endl<<endl;
			}
		}
	}
	while(option <= 4);
	
}