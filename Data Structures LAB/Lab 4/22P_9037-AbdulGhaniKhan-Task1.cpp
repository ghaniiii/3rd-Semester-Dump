#include<iostream>
#include<string.h>

using namespace std;

struct Node{
	
	string description;
	Node *next;
	Node *prev;
	bool TaskCompletion = false;
	
};

class doubleLL{
	private:
		int length;
		Node *temp;
		Node *temp1;
		Node *head;
		
	public:
		doubleLL(){
			length = 0;
			temp = NULL;
			temp1 = NULL;
			head = NULL;
		}
		
		
		void add(){
			
			string line;
			int option;
			int position;
			
			
			if(head == NULL){
				
				head = new Node;
				head->next = NULL;
				head->prev = NULL;
				
				cout<<"Enter The Description Of The First Task : ";
				fflush(stdin);
				getline(cin,line);
				
				head->description = line;
				
				length++;
				
				return;
			}
			
		 	cout<<"Choose The Priority Of The Task :-"<<endl;
		 	cout<<"1. High"<<endl;
		 	cout<<"2. Mid Custom"<<endl;
		 	cout<<"3. Least"<<endl<<endl;
		 	
		 	cout<<"Enter Your Option : ";
		 	cin>>option;
		 	
		 	
			if(option == 1){
				
				temp = new Node;
				temp->next = head;
				temp->prev = NULL;
				
				head->prev = temp;
				
				head = temp;
				
				cout<<"Enter The Description Of The Task : ";
				fflush(stdin);
				getline(cin,line);
				
				temp->description = line;
				
				length++;
				
				return;
				
			}
			else if(option == 2){
				
				cout<<"Enter The Postion : ";
				cin>>position;
				
				if(position <= 1 || position > length ){
					
					cout<<endl<<endl;
					
					cout<<"Wrong Position You Might Be Adding At A Wrong Position"<<endl;
					cout<<"Or You Are Not Adding In Between High And Least"<<endl;
					cout<<"Or This Might Be You Are Missing Highest Priority Task Or Lowest Priority Task"<<endl;
					cout<<"Or Add Atleast 2 Task To Enter in Middle"<<endl;
					cout<<"Try Adding Highest Priority Tasks And Lowest Priority Tasks And Then Add In Middle"<<endl<<endl<<endl;
					
				}
				else{
					
					temp = head;
					
					for(int i = 1 ; i < (position-1) ; i++){
						
						temp = temp->next;
						
					}
					
					temp1 = new Node;
					temp1->next = temp->next;
					
					temp->next = temp1;
					
					if(temp1->next != NULL){
						temp1->next->prev = temp1;
					}
					
					
					temp1->prev = temp;
					
					cout<<"Enter The Description Of The Task : ";
						fflush(stdin);
						getline(cin,line);
						
					temp1->description = line;
					
					length++;
					
					
					return;
					
				}
				
			}
			else if(option == 3){
				temp = head;
				
				while(temp != NULL){
					if(temp->next == NULL){
						
						temp1 = new Node;
						temp1->next = temp->next;
						temp1->prev = temp;
						
						temp->next = temp1;
						
						cout<<"Enter The Description Of The Task : ";
						fflush(stdin);
						getline(cin,line);
						
						temp1->description = line;
						
						length++;
						
						return;
					}
					
					
					temp = temp->next;
				}
				
			}
			
			
			
			
		}
		
		
		void MarkCompleted(){
			
			if(head == NULL){
				cout<<"No Task Added Till Now "<<endl;
				return;
			}
			
			temp = head;
			int counter = 1;
			int option;
			int position;
			
			while(temp != NULL){
					cout<<counter<<". "<<temp->description<<endl;
					cout<<"   "<<"Task Completion : ";
					
					if(temp->TaskCompletion){
						cout<<"Completed"<<endl;
					}
					else{
						cout<<"Incompleted"<<endl;
					}
					
					temp = temp->next;
					
					counter++;
				
			}
			
			temp = head;
			
			cout<<"Enter The Task That You Want To Mark Completed : ";
			cin>>position;
			
			if(position < 1 || position > length){
				cout<<"Wrong Task Number"<<endl<<endl;
			}
			else{
				
				for(int i=1 ; i<position ; i++){
				temp = temp->next;
				}
				if(temp != NULL){
					temp->TaskCompletion = true;
				
					cout<<"Task Marked Completed"<<endl;
					
					return;
				}
				else{
					cout<<"Wrong Task Number"<<endl;
				}
				
			}
			
			
			
			
		}
		
		
		void display(){
			
			if(head == NULL){
				cout<<"No Task Added To Print"<<endl;
				
				return;
			}
			
			
			int option;
			
			cout<<"Display In As :-"<<endl;
			cout<<"1. Descending Order"<<endl;
			cout<<"2. Ascending Order"<<endl<<endl;
			cout<<"Enter The Option : ";
			cin>>option;
			
			int counter = 1;
			
			temp = head;
			
			if(option == 1){
				while(temp != NULL){
					cout<<counter<<". "<<temp->description<<endl;
					cout<<"   "<<"Task Completion : ";
					
					if(temp->TaskCompletion){
						cout<<"Completed"<<endl;
					}
					else{
						cout<<"Incompleted"<<endl;
					}
				
					temp = temp->next;
					
					counter++;
				
				}
				
				
			}
			else if(option == 2){
				
				
				while(temp->next != NULL){
					temp = temp->next;
				}
				
				while(temp != NULL){
					cout<<counter<<". "<<temp->description<<endl;
					cout<<"   "<<"Task Completion : ";
					
					if(temp->TaskCompletion){
						cout<<"Completed"<<endl;
					}
					else{
						cout<<"Incompleted"<<endl;
					}
					
					temp = temp->prev;
					
					counter++;
					
				}
				
			}
			
		}
		
		
		void DeleteCompleted(){
			
			if(head == NULL){
				cout<<"No Tasks Added Till Now"<<endl;
				return;
			}
			
			int count = 0;
			
			temp = head;
			
			if(head->TaskCompletion && head->next == NULL){
				delete head;
				head = NULL;
				
				length--;
				
				cout<<"All Completed Tasks Deleted Succesfully"<<endl;
				
				return;
			}
			
			
			
			if(head->TaskCompletion){
				while(head->TaskCompletion){
					temp = head;
					
					head = head->next;
					
					delete temp;	
					
					if(head != NULL){
						head->prev = NULL;	
					}
				
					count++;
					
					if(head == NULL){
						return;
					}
				}
			}
			
			temp = head;
			
						
			while( temp!=NULL ){
				
				
				if(temp->TaskCompletion ){
					
					temp1 = temp;
					
					if(temp1->next != NULL){
						
						temp1->next->prev = temp1->prev;
						
					}
					
						temp1->prev->next = temp1->next;	
					
					
					
					temp = temp1->prev;
					
					delete temp1;
					
					length--;
					count++;
					
				}
				
				temp = temp->next;
			}
			
			if(count == 0){
				cout<<"No Tasks To Delete As None Are Completed  "<<endl<<endl;
				
			}
			else{
				cout<<"All Completed Tasks Deleted Successfully"<<endl<<endl;
			}
			
		}
};


int main(){
	
	int option;
	
	doubleLL A;
	
	do{
		cout<<"1. Add Task"<<endl;
		cout<<"2. Mark As Completed"<<endl;
		cout<<"3. Remove Completed Tasks"<<endl;
		cout<<"4. Display Tasks"<<endl;
		cout<<"5. Exit"<<endl<<endl;
		
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			A.add();
		}
		else if(option == 2){
			A.MarkCompleted();
		}
		else if(option == 3){
			A.DeleteCompleted();
		}
		else if(option == 4){
			A.display();
		}
		
		cout<<endl<<endl;
		
	}
	while(option <= 4);
	
	
	
	
}