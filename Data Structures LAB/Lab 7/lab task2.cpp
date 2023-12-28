#include<iostream>
#include<string.h>

using namespace std;

struct Node{
	Node *next;
	string info;
};

class Queue{
	public:
		Node *head;
		Node *tail;
		Node *temp;
		
		int length;
		int limit;
	
		Queue(int size){
			
			limit = size;
			head = NULL;
			tail = NULL;
			
			length = 0;
		
		}
		
		void enque(string name){
			
		
				if(isEmpty()){
					head = new Node;
					tail = head;
					
					tail->info = name;
					
					tail->next = NULL;
					
					length++;
					
					return;
				}
				
				tail->next = new Node;
				tail = tail->next;
				
				tail->info = name;
				
				tail->next = NULL;
				
				length++;
				
		
			
			
		}
		
		string deque(){
			
			string tempString;
			
			if(isEmpty()){
				return "\0";
			}
			
			if(head == tail){
				
				temp = head;
				
				head = NULL;
				tail = NULL;
				
				tempString = temp->info;
				
				delete temp;
				
				return tempString;
				
			}
			
			
			
			temp = head;
			head = head->next;
			
			tempString = temp->info;
			
			delete temp;
			
			length--;
			
			return tempString;
			
		}
		
		bool isEmpty(){
			if(head == NULL && tail == NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
		
		~Queue(){
			
			cout<<"Destructing"<<endl;
			
			while(head != NULL){
				
				deque();
				
			}
			
				delete head;
				delete temp;
				delete tail;
			
			
		}
};


int main(){
	
	int limit;
	int counter;
	int option;
	int option2;
	
	cout<<"Enter The Queue Limit  : ";
	cin>>limit;
	
	Queue Tickets(limit);
	Queue RollerCoaster(limit);
	Queue RoundWheel(limit);
	Queue MotionRide(limit);
	
	string temp;
	
	
	do{
		cout<<"1. Enter In The Ticket Line "<<endl;
		cout<<"2. Give Tickets "<<endl;
		cout<<"3. Proceed With Rides"<<endl;
		cout<<"4. Exit"<<endl<<endl;
		
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			
			if(limit != Tickets.length){
				
				cout<<"Enter The Name : ";
				fflush(stdin);
				getline(cin , temp);
				
				if(temp != "\0"){
					Tickets.enque(temp);
				}
				else{
					cout<<"Enter Something Atleast"<<endl<<endl;
				}
				
				
			}
			else{
				cout<<"Queue Is Full Currently "<<endl<<endl;
			}
			
			
		}
		else if(option == 2){
			
		
			
			temp = Tickets.deque();
			
			if(temp != "\0"){
				cout<<"Currently In Processing Is :  "<<temp<<endl<<endl;
				cout<<"Which Ticket Do You Want ? "<<endl;
				cout<<"1. Roller Coaster"<<endl;
				cout<<"2. Round Wheel "<<endl;
				cout<<"3. Motion Ride"<<endl;
				cout<<"4. Leave Without Buying "<<endl<<endl;
				cout<<"Enter Your Option : ";
				
				cin>>option2;
				
				if(option2 == 1){
					RollerCoaster.enque(temp);
				}
				else if(option2 == 2){
					RoundWheel.enque(temp);
				}
				else if(option2 == 3){
					MotionRide.enque(temp);
				}
				else if(option2 == 3){
					
				}
				
			}
			else{
				cout<<"Nothing In Ticketing Queue"<<endl<<endl;
			}
		
			
		}
		else if(option == 3){
			
			while(RollerCoaster.head != NULL){
				cout<<RollerCoaster.deque()<<" Is Enjoying Roller Coaster"<<endl;
			}
			
			while(RoundWheel.head != NULL){
				cout<<RoundWheel.deque()<<" Is Enjoying Round Wheel"<<endl;
			}
			
			while(MotionRide.head != NULL){
				cout<<MotionRide.deque()<<" Is Enjoying Motion Ride"<<endl;
			}
		}
		else if(option == 4){
			break;
		}
		
		cout<<endl<<endl<<endl;
		
	}
	while(option != 4);
	
	
}
