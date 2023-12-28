#include<iostream>
#include<string.h>

using namespace std;


class Node{
	public:
		char value;
		Node *next;
		
	Node(char value){
		this->value = value;
		next = NULL;
	}
	
};


class Stack{
	Node *top;
	Node *temp;
	
	int length;
	int max;
	
	public:
		Stack(int max){
			this->max = max;
			top = NULL;
			temp = NULL;
			length = 0;		
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
		
		
		void push(char val){
			
			if(!isFull()){
				
				temp = new Node(val);
				
				temp->next = top;
				
				top = temp;
				
				length++;
				
			}
			else{
				cout<<"Nothing To Undo"<<endl<<endl;
			}
			
		}
		
		char pop(){
			if(isEmpty()){
				cout<<"Stack Is Empty"<<endl;
				return '\0';
			}
			else{
				char value;
				value = top->value;
				temp = top;
				top = top->next;
				
				delete temp;
				
				length--;
				
				return value;
			}
		}
		
		
		~Stack(){
			delete top;
			delete temp;	
		}
	
};


int main(){
	
	int option;
	string name;
	
	
	cout<<"Enter The String : ";
	fflush(stdin);
	getline(cin , name);
	
	Stack A(name.length());
	
	do{
		cout<<"String Is : "<<name<<endl<<endl;
		
		
		cout<<"1. Undo "<<endl;
		cout<<"2. Redo "<<endl;
		cout<<"3. Exit "<<endl<<endl;
		
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			
			if(!A.isFull()){
				
				int i=0;
			
				while(name[i] != '\0'){
					i++;
				}
				
				A.push(name[i-1]);
				name[i-1] = name[i];
				
			}
			else{
				cout<<endl;
				cout<<"Nothing To Undo"<<endl<<endl;
				cout<<endl;
			}
			
			
		}
		else if(option == 2){
			
			if(!A.isEmpty()){
				
				int i = 0;
			
				while(name[i] != '\0'){
					i++;
				}
				
				name[i] = A.pop();
				name[i+1] = '\0';
					
			}
			else{
				cout<<endl;
				cout<<"Nothing To Redo"<<endl<<endl;
				cout<<endl;
			}
			
		}
		else if(option == 3){
			break;
		}
		else{
			cout<<endl;
			cout<<"Wrong Input"<<endl<<endl;
		}
		
	}
	while(option != 3);
	
	
	
}
