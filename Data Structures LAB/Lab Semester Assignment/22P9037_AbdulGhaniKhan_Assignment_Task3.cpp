#include<iostream>


using namespace std;

struct Student{
	
	string name;
	int meritScore;
	Student *next;
	
	Student(){
		name = "----";
		meritScore = 0;
	}
};

class Queue{
	
	public:
		
		Student *front;
		Student *rear;
		
		Student *temp;
		int size;
		
	
		Queue(){
			
			front = NULL;
			rear = NULL;
			
			temp = NULL;
			size = 0;
		}
		
		void deque(){
			
			if(front == NULL){
				cout<<"No One Is In The Queue To Process"<<endl;
				return;
			}
			
			if(front == rear){
				
				cout<<"Processing Last Student In The Current Queue "<<endl<<endl;
				
				cout<<"Student Name Is : "<<front->name<<endl;
				cout<<"Student Merit Is : "<<front->meritScore<<endl<<endl;
				
				if(front->meritScore <= 50){
					cout<<"Sorry You Are Not Eligible For Admission In FAST"<<endl<<endl;
				}
				else{
					cout<<"You Are Eligible Please Take Your Fee Challaan From Accounts Office"<<endl<<endl;
				}
				
				delete front;
				
				front = NULL;
				rear = NULL;
				temp = NULL;
				
				size--;
				
				return;
				
			}
			
			temp = front;
			
			cout<<"Processed Student : "<<temp->name<<endl;
			cout<<"Merit Score Was : "<<temp->meritScore<<endl<<endl;
			
			if(temp->meritScore <= 50){
				cout<<"Sorry You Are Not Eligible For Admission In FAST"<<endl<<endl;
			}
			else{
				cout<<"You Are Eligible Please Take Your Fee Challaan From Accounts Office"<<endl<<endl;
			}
			
			front = front->next;
			
			delete temp;
			
			temp = NULL;
			
			size--;
			
			
		}
		
		void enque(){
			string name;
			int merit;
			
			cout<<"Enter The Name Of The Student : ";
			fflush(stdin);
			getline(cin , name);
			cout<<"Now Enter The Student Merit : ";
			cin>>merit;
			
			if(merit < 0 || merit > 100){
				cout<<"Wrong Merit "<<endl;
				return;
			}
				
				if(rear == NULL){
					
					rear = new Student;
					
					rear->name = name;
					
					rear->meritScore = merit;
					
					rear->next = NULL;
					front = rear;
					
					size++;
					
					return;
					
				}
				
				rear->next = new Student;
				rear = rear->next;
				
				rear->name = name;
					
				rear->meritScore = merit;
				
				rear->next = NULL;
				
				size++;
				
		}
		
		bool isEmpty(){
			if(front == NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
		void print(){
			temp = front;
			while(temp != NULL){
				cout<<temp->name<<endl;
				temp = temp->next;
			}
		}
		
		
		~Queue(){
			delete front , rear , temp;
		}
};

class threeQueues{
	
	public:
	
		Queue One;
		Queue Two;
		Queue Three;

		
		void addAStudentToTheQueue(){
			int min = findMin1(One.size , Two.size , Three.size);
			
			if(min == One.size){
				One.enque();
			}
			else if(min == Two.size){
				Two.enque();
			}
			else if(min == Three.size){
				Three.enque();
			}
			else{
				One.enque();
			}
		}
		
		
		int findMin1(int a , int b , int c){
			
			int minNum = a;

		    if(b < minNum){
		    	
		        minNum = b;
		    
			}
			
		    if(c < minNum){
		    	
		        minNum = c;
		    
			}
		
		    return minNum;
			
		}
		
		int findMin(int a , int b , int c){
			
			if(a != 0 && (a < b || b == 0) && (a < c || c == 0)){

		        return a;
		        
		    } 
			else if(b != 0 && (b < a || a == 0) && (b < c || c == 0)){
				
		        return b;
		        
		    } 
			else if(c != 0 && (c < a || a == 0) && (c < b || b == 0)){
				
		        return c;
		        
		    }
		    
		    if(a != 0){
		    	return a;
			}
		    else if(b != 0){
		    	return b;
			}
		    else if(c != 0){
		    	return c;
			}
			 
		    return -1;
			
		}
		
		void processAdmission(){
			
			int processingQueue;
			int size;
			
			
			
			for(int i = 1; i<=3 ;i++){
				processingQueue = findMin(One.size , Two.size , Three.size);
				
				if(processingQueue == One.size){
					size = One.size;
					for(int i = 1; i<= size ; i++){
						One.deque();
					}
				}
				else if(processingQueue == Two.size){
					size = Two.size;
					for(int i = 1; i <= size ; i++){
						Two.deque();
					}
				}
				else if(processingQueue == Three.size){
					size = Three.size;
					for(int i = 1 ; i <= size; i++){
						Three.deque();
					}
				}
			}
			
		}
		
		void queueStatus(){
			cout<<"--------------------------------"<<endl;
			cout<<"              Desk 1"<<endl;
			cout<<"--------------------------------"<<endl;
			cout<<"Number Of Students In Queue :"<<One.size<<endl<<endl;
			
			One.print();
			
			cout<<endl<<endl;
			
			cout<<"--------------------------------"<<endl;
			cout<<"              Desk 2"<<endl;
			cout<<"--------------------------------"<<endl;
			cout<<"Number Of Students In Queue :"<<Two.size<<endl<<endl;

			
			Two.print();
			
			cout<<endl<<endl;
			
			cout<<"--------------------------------"<<endl;
			cout<<"              Desk 3"<<endl;
			cout<<"--------------------------------"<<endl;
			cout<<"Number Of Students In Queue :"<<Three.size<<endl<<endl;

			
			Three.print();
			
			cout<<endl<<endl;
			
		}
		
		void seeWhoIsNext(){
			int option;
			
			cout<<"1. Desk One"<<endl;
			cout<<"2. Desk Two"<<endl;
			cout<<"3. Desk Three"<<endl;
			cout<<"Enter Your Option : ";
			cin>>option;
			
			if(option == 1){
				if(One.rear != NULL){
					cout<<"Next Student Waiting Is : "<<One.rear->name<<endl;
				}
				else{
					cout<<"There Is No One Waiting"<<endl;
				}
				
			}
			else if(option == 2){
				if(Two.rear != NULL){
					cout<<"Next Student Waiting Is : "<<Two.rear->name<<endl;
				}
				else{
					cout<<"There Is No One Waiting"<<endl;
				}
				
			}
			else if(option == 3){
				if(Three.rear != NULL){
					cout<<"Next Student Waiting Is : "<<Three.rear->name<<endl;
				}
				else{
					cout<<"There Is No One Waiting"<<endl;
				}
			}
			else{
				cout<<"Wrong Option"<<endl;
			}
			
			cout<<endl<<endl;
		}
		
	
};

int main(){
	threeQueues Desks;
	
	int option;
	
	do{
		cout<<"1. Add Student To Queue"<<endl;
		cout<<"2. Process Admissions"<<endl;
		cout<<"3. Check Queue Status"<<endl;
		cout<<"4. See Whos Next"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			Desks.addAStudentToTheQueue();
		}
		else if(option == 2){
			Desks.processAdmission();
		}
		else if(option == 3){
			Desks.queueStatus();
		}
		else if(option == 4){
			Desks.seeWhoIsNext();
		}
		else if(option == 5){
			break;
		}
		else{
			cout<<"Wrong Option"<<endl;
		}
		
		cout<<endl<<endl;
	}
	while(option != 5);
}