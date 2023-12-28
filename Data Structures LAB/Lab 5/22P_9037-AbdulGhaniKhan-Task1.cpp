#include<iostream>
#include<string.h>

using namespace std;

class Node{
	
	public:
	
	int value;
	Node *next;
	
		Node(int value){
			this->value = value;
			next = NULL;
		}
	
};

class Stack{
	
	Node *temp;
	Node *top;
	int max = 2;
	int length;
	
		
	public:
		
		Stack(){
			length = 0;
			temp = NULL;
			top = NULL;
		}
		
		void push(int value){
			if(length == max){
				cout<<"Stack Is Full"<<endl;
				return;
			}
			
			if(top == NULL){
				top = new Node(value);
				return;
			}
			
			temp = new Node(value);
			temp->next = top;
			
			top = temp;
		}
		
		
		int pop(){
			if(top != NULL){
				
				temp = top;
				
				int val = temp->value;
				
				top = top->next;
				
				delete temp;
				
				return val;
				
			}
			
			
		}
		
		~Stack(){
			delete temp;
			delete top;
		}
		
};


int main(){
	
	int num1;
	int num2;
	Stack A;
	
	cout<<"You Will Be Swapping Values Of Two Numbers Here "<<endl<<endl;
	
	cout<<"Enter The First Number : ";
	cin>>num1;
	
	cout<<"Enter The Second Number : ";
	cin>>num2;
	
	A.push(num1);
	A.push(num2);
	
	cout<<endl<<"Numbers Swapped"<<endl<<endl;
	
	num1 = A.pop();
	num2 = A.pop();
	
	cout<<"Now First Number Is : "<<num1<<"\nAnd Second Number Is : "<<num2;

	
}