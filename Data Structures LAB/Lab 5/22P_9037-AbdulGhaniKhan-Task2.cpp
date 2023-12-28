#include<iostream>
#include<string.h>

using namespace std;

class Stack{
	
	char *array;
	char *top;
	int size;
	int max;
	
	public:
		
		Stack(int value){
			
			array = new char[value];
			top = NULL;
			size = 0;
			max = value;
			
		}
		
		bool isEmpty(){
			if(size == 0){
				return true;
			}
			else{
				return false;
			}
		}
		
		bool isFull(){
			if(size == max){
				return true;
			}
			else{
				return false;
			}
		}
		
		void push(char value){
			if(!isFull()){
				if(top == NULL){
					top = array;
					*top = value;
					
					size++;
					return;
				}
				
				top++;
				*top = value;
				size++;
			}
		}
		
		
		char pop(){
			if(isEmpty()){
				cout<<"Cannot Pop More Elements"<<endl;
				
			}
			else{
				
				char topValue = *top;
			
				top--;
				size--;
				
				return topValue;
				
			}
			
			
		}
		
		~Stack(){
			
			delete array;
			delete top;
			
		}
	
};


int main(){
	
	string name;
	string reversed = {};
	
	cout<<"Enter The String That You Want To Reverse : ";
	fflush(stdin);
	getline(cin , name);
	
	Stack A(name.length());
	
	for(int i=0;i<name.length();i++){
		A.push(name[i]);
	}
	
	for(int i=0;i<name.length();i++){
		reversed = reversed + A.pop();
	}
	
	cout<<"Reversed String Is : "<<reversed<<endl;
	
	
	
	
}