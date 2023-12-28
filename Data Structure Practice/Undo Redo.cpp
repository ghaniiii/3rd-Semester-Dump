#include<iostream>
#include<string.h>

using namespace std;

struct Node{

	char val;
	Node *next;
	
};

class Stack{
		
		
	public:
		
		Node *top;
		Node *temp;
		int max;
		int length;
		
		
		Stack(int max){
			
			this->max = max;
			length = 0;
			temp = NULL;
			top = NULL;
			
		}
		
		bool isEmpty(){
			if(top == NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
		bool isFull(){
			if(length == max){
				return true;
			}
			else{
				return false;
			}
		}
		
		void push(int value){
			if(!isFull()){
				temp = new Node;
				temp->val = value;
				temp->next = top;
				top = temp;
				
				length++;
			}
		}
		
		
		char pop(){
			if(!isEmpty()){
				temp = top;
				top = top->next;
				char tempVal = temp->val;
				
				delete temp;
				length--;
				
				return tempVal;
			}
		}
};

class GroupOfStacks{
	public:
		Stack A,B,C;
		int length;
		
		GroupOfStacks(int length) : A(length) , B(length) , C(length){
			this->length = length;
		}
		
		void putValuesInStack(string line){
			for(int i=0;i<line.length();i++){
				A.push(line[i]);
			}
			
		}
		
		void displayValues(){
			
			cout<<"Displaying :-"<<endl<<endl;
			
			length = A.length;
			
			for(int i=0;i<length;i++){
				B.push(A.pop());
			}
			
			length = B.length;
			
			for(int i=0;i<length;i++){
				char val = B.pop();
				A.push(val);
				cout<<val<<" ";
			}
		}
		
		void undo(){

			C.push(A.pop());
			
		}
		
		void redo(){
			A.push(C.pop());
		
		}
		
};


int main(){
	
	string line;
	int option;
	
	cout<<"Enter The String : ";
	fflush(stdin);
	getline(cin,line);
	
	GroupOfStacks A(line.length());
	A.putValuesInStack(line);
	
	do{
		
		A.displayValues();
		cout<<endl<<endl;
		
		
		cout<<"1. Undo"<<endl;
		cout<<"2. Redo"<<endl;
		cout<<"3. Exit"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		
		if(option == 1){
			A.undo();
		}
		else if(option == 2){
			A.redo();
		}
		else if(option == 3){
			break;
		}
		
		cout<<endl;
		
	}
	while(option != 3);
	
}