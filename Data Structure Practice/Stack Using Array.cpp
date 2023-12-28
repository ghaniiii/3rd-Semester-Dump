#include<iostream>
#include<string.h>

using namespace std;

class StackArray{
	int *top;
	int *array;
	int length;
	int size;
	
	public:
		StackArray(int size){
			this->size = size;
			array = new int[size];
			top = NULL;
			length = 0;
		}
		
		void push(){
			
			if(length == size){
				cout<<"Stack Is Full"<<endl<<endl;
				return;
			}
			
			if(top == NULL){
				top = array;
				cout<<"Enter The Value : ";
				cin>>*top;
				length++;
				return;
			}
			top++;
			
			cout<<"Enter The Value : ";
			cin>>*top;
			length++;
		}
		
		void pop(){
			if(length == 0){
				cout<<"No Elements In The Stack"<<endl<<endl;
				return;
			}	
			top--;
			length--;
		}
		
		int returnTop(){
			if(isEmpty() == true){
				return -1;
			}
			else{
				return *top;	
			}
		}
		
		bool isEmpty(){
			if(length == 0){
				return true;
			}
			return false;
		}
		
};

int main(){
	StackArray A(10);
	int option;
	
	do{
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Return Top"<<endl;
		cout<<"4. Check If Stack Is Empty"<<endl<<endl;
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
				cout<<"The Top Value Is : "<<A.returnTop()<<endl<<endl;
			}
			else{
				cout<<"No Nodes To Return"<<endl;
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