#include<iostream>
#include<string.h>

using namespace std;


class Queue{
	private:
		int size;
		int front;
		int rear;
		string temp;
		
		string *array;
		
		int length;
		
		
	public:
		Queue(int size){
			this->size = size;
			
			front = -1;
			rear = -1;
			
			array = new string[size];
			
			length = 0;
			
		}
		
		void addPatient(string name){
			
			if(front == -1 && rear == -1){
				
				front++;
				rear++;
				
//				cout<<"Enter The Patient Name : ";
//				fflush(stdin);
//				getline(cin , temp);
				
				array[rear] = name;
				
				length++;
				
				return;
				
			}
			
			if(front + size - 1 == rear || rear + 1 == front){
				cout<<"Queue Is Full Currently "<<endl<<endl;
				
				return;
			}
			else{
				if(rear == size - 1){
					
					rear = 0;
//					cout<<"Enter The Patient Name : ";
//					fflush(stdin);
//					getline(cin , temp);
					
					array[rear] = name;
					
					length++;
				}
				else{
					
					rear++;
//					cout<<"Enter The Patient Name : ";
//					fflush(stdin);
//					getline(cin , temp);
					
					array[rear] = name;
					length++;
				
				}
				
			}
			
			
			
			
		}
		
		string sendPatient(){
			
			if(front == -1 && rear == -1){
//				cout<<"Queue Is Empty No One To Send Currently"<<endl;
				
				return "\0";
			}
			
			if(front == rear){
//				cout<<"Patient "<<array[front]<<" Has Been Sent To The Doctor "<<endl<<endl;
				
				temp = array[front];
				
				front = -1;
				rear = -1;
				
				length--;
				
				return temp;
			
			}
			
			if(front == size - 1){
				
//				cout<<"Patient "<<array[front]<<" Has Been Sent To The Doctor "<<endl<<endl;
				
				temp = array[front];
				
				front = 0;
				
				length--;
				
				return temp;
			}
			else{
				
//				cout<<"Patient "<<array[front]<<"has Been Sent To The Doctor "<<endl<<endl;
				
				temp = array[front];
				
				front++;
				
				length--;
				
				return temp;
				
			}
			
		}
		
		void whosNext(){
			if(front == -1 && rear == -1){
				cout<<"No One In The Que"<<endl;
			}
			
			cout<<"Patient "<<array[front]<<" is Next In The Queue"<<endl<<endl;
			
		}
		
//		void PrintAll(){
//			
//			int front1 = front;
//			int rear1 = rear;
//			int counter = 1;
//			
//			Queue A(length);
//			
//			for(int i=0;i<size;i++){
//				if(front1 == size - 1){
//					front1 = 0;
//				}
//				
//				temp = sendPatient();
//				
//				A.addPatient(temp);
//				
//				cout<<counter<<". "<<temp<<endl;
//				
//				counter++;
//				
//				
//			}
//			
//			front1 = front;
//			rear1 = rear;
//			
//			for(int i=0;i<length; i++){
//				if(front1 == size - 1){
//					front1 = 0;
//				}
//				
//				temp = A.sendPatient();
//				
//				if(temp == "\0"){
//					
//				}
//				else{
//					addPatient(temp);
//				}
//				
//				
//			}
//						
//		}
		
		
		
};



int main(){
	
	int number;
	string temp;
	
	cout<<"Please Specify The Max Queue Number : ";
	cin>>number;
	
	Queue A(number);
	int option;
	
	do{
		cout<<"1. Add Patient"<<endl;
		cout<<"2. Send Patient"<<endl;
		cout<<"3. See Whos Next"<<endl;
//		cout<<"4. Display All Patient"<<endl;
		cout<<"4. Exit "<<endl<<endl;
		
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			cout<<"Enter Patient Name : ";
			fflush(stdin);
			getline(cin , temp);
			
			A.addPatient(temp);
		}
		else if(option == 2){
			
			temp = A.sendPatient();
			
			if(temp == "\0"){
				cout<<"There Is No One In The Queue To Be Send To The Doctor"<<endl<<endl;
				
			}
			else{
				
				cout<<"Patient "<<temp<<" Has Been Sent To The Doctor"<<endl<<endl;
				
			}
			
		}
		else if(option == 3){
			
			A.whosNext();
			
		}
//		else if(option == 4){
//			
//			A.PrintAll();
//			
//		}
		else if(option == 4){
			break;
		}
		
	}
	while(option != 4);
	
	
	
	
	
	
	
	
}