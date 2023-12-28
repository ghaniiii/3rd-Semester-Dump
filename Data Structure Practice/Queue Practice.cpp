#include<iostream>

using namespace std;

class Queue{
	public:
		int size;
		int *array;
		int *first;
		int *last;
		int number;
		int count;
		
	
		Queue(int size){
			this->size = size;
			
			array = new int[size];

			first = array;
			last = array;
			count = 0;
		}
		
		void enque(){
			
			if(first == array+size-1 && count < size){
				*first = number;
				first = array;
				count++;
				
				return;
			}
			
			if(count < size){
				*first = number;
				first++;
				count++;
			}
			else{
				cout<<"Queue Overflows"<<endl;
			}
		}
		
		void deque(){
			
			if(last == array+size-1 && count > 0){
				cout<<*last<<" , Element Dequed Last"<<endl;
				last = array;
				count--;
				return;
			}
			
			if(count > 0){
				cout<<*last<<" , Element Dequed"<<endl;
				last++;
				count--;
			}
			else{
				cout<<"Queue Underflows"<<endl;
			}
			
		}
		
		
};

int main(){
	Queue T(5);
	int option;
	
	do{
		cout<<"1. Enque"<<endl;
		cout<<"2. Deque"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"4. Print"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			cout<<"Enter The Number To Enque"<<endl;
			cin>>T.number; 
			T.enque();
		}
		else if(option == 2){
			T.deque();
		}
		else if(option == 3){
			break;
		}
		else if(option == 4){
			T.print();
		}
		else{
			cout<<"Wrong Option"<<endl<<endl;
		}
		
	}
	while(option != 3);
}