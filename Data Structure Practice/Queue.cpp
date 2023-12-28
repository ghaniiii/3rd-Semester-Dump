#include<iostream>
#include<stdexcept>

using namespace std;

struct Node{
	int info;
	Node *next;
};

class Queue{
	private:
		Node *front;
		Node *rear;
		
		Node *temp;
		int max;
		int size;
		
	public:
		Queue(){
			cout<<"Enter The Max Size Of The Queue : ";
			cin>>max;
			
			front = NULL;
			rear = NULL;
			
			temp = NULL;
			size = 0;
		}
		
		void deque(){
			
			if(front == NULL){
				cout<<"Nothing To Deque From The Queue Add Something Before Dequeing"<<endl;
				return;
			}
			
			if(front == rear){
				
				cout<<"Dequeing Last Node "<<endl<<endl;
				
				cout<<"Value in The Node Is : "<<front->info<<endl<<endl;
				
				delete front;
				
				front = NULL;
				rear = NULL;
				temp = NULL;
				
				size--;
				
				return;
				
			}
			
			temp = front;
			
			cout<<"Dequed Node With Value : "<<temp->info<<endl<<endl;
			
			front = front->next;
			
			delete temp;
			
			temp = NULL;
			
			size--;
			
			
		}
		
		void enque(){
			
			if(size != max){
				
				if(rear == NULL){
					
					rear = new Node;
					
					cout<<"Enter The Info In The New Node : ";
					cin>>rear->info;
					
					rear->next = NULL;
					front = rear;
					
					size++;
					
					return;
					
				}
				
				rear->next = new Node;
				rear = rear->next;
				
				cout<<"Enter The Info In The New Node : ";
				cin>>rear->info;
				
				rear->next = NULL;
				
				size++;
				
			}
			else{
				cout<<"Max Queue Limit Reached"<<endl;
			}
			
			
		}
		
		bool isEmpty(){
			if(front == NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
		int returnFront(){
				
			return front->info;
		
		}
		
		int returnRear(){
			
			return rear->info;
			
		}
		
		~Queue(){
			delete front , rear , temp;
		}
};



int main(){
	
	Queue A;
	int option;
	
	do{
		
		cout<<"1. Enque"<<endl;
		cout<<"2. Deque"<<endl;
		cout<<"3. Return Front "<<endl;
		cout<<"4. Return Rear "<<endl;
		cout<<"5. Exit"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>option ;
		
		cout<<endl;
		
		if(option == 1){
			A.enque();
		}
		else if(option  == 2){
			A.deque();
		}
		else if(option == 3){
			
			if(!A.isEmpty()){
				cout<<"The Front Element Is : "<<A.returnFront()<<endl;
			}
			else{
				cout<<"The Que Is Empty "<<endl<<endl;
			}
				

			
		}
		else if(option == 4){
			if(!A.isEmpty()){
				cout<<"The Rear Element Is : "<<A.returnRear()<<endl;
			}
			else{
				cout<<"The Que Is Empty"<<endl<<endl;
			}
		}
		else if(option == 5){
			break;
		}
		
		
	}
	while(option != 5);
	
	
	
	
}