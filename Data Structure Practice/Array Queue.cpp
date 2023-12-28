#include<iostream>

#include<string.h>

using namespace std;

class ArrayQueue{
	private:
		
		int size;
		int *array;
		int *front;
		int *rear;
		int elements;
		
	public:
		ArrayQueue(int size){
			this->size = size;
			
			array = new int[size];
			
			front = NULL;
			rear = NULL;
			
			elements = 0;
		}
		
		
		void enque(){
			
			if(front == NULL && rear == NULL){
				cout<<"Enter THe First Element : ";
				front = array;
				rear = array;
				
				cin>>*rear;
				elements++;
				
				return;
			}
			
			
			if(rear + 1 != front && front + size - 1 != rear){
				
				if(rear == array+size-1){
					rear = array;
					cout<<"Enter The number In The Rear : ";
					cin>>*rear;
					
					
				}
				else{
					rear++;
					cout<<"Enter The Number In The Rear : ";
					cin>>*rear;
					
					
				}
				
				
			}
			else{
				cout<<"Queue Overflows"<<endl;
			}
			
			
			
		}
		
		void deque(){
			
			if(rear == NULL && front == NULL){
				cout<<"Queue UnderFlows"<<endl;
				return;
			}
			
			if(front == rear){
				cout<<"Dequed Last Element"<<endl;
				front = NULL;
				rear = NULL;
			
				
				return;
			}
			
			if(front == array + size - 1){
				
				cout<<"Element Dequed Is : "<<*front<<endl;
				front = array;
				
				
			}
			else{
				
				front++;
				cout<<"Element Dequeued"<<endl;
				
			}
			
			
			
			
		}
		
		void printForwardAndRear(){
			
			if(front == NULL && rear == NULL){
				cout<<"Nothing In The Que"<<endl;
				return;
			}
			
			cout<<"Front Element Is : "<<*front<<endl;
			cout<<"Rear Element Is : "<<*rear<<endl;
		}
		
		
};


int main(){
	
	int number;
	
	cout<<"Specify The Array Size : ";
	cin>>number;
	
	
	ArrayQueue A(number);
	
	int option;
	
	do{
		cout<<"1. Enque"<<endl;
		cout<<"2. Deque"<<endl;
		cout<<"3. Print Forward And Rear "<<endl;
		cout<<"4. Exit"<<endl<<endl;
		
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			A.enque();
		}	
		else if(option == 2){
			A.deque();
		}
		else if(option == 3){
			A.printForwardAndRear();
		}
		else if(option == 4){
			break;
		}
		
	}
	while(option != 4);
	
	return 0;
}