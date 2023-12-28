#include<iostream>
#include<string.h>

using namespace std;

struct Node{
	int info;
	Node *next;
};

class LinkedList{
	private:
		Node *head;
		Node *temp;
		Node *temp1;
		
		
	public:
		LinkedList(){
			head = NULL;
			temp = NULL;
			temp1 = NULL;
		}
		
		void add(){
			
			char choice;
			
			int numberToEnter;
			
			int key;
			
			if(head == NULL){
				
				head = new Node;
				
				cout<<"Enter The Number That You Want To Store : ";
				cin>>head->info;
				
				head->next = NULL;	
				
				return;
			}
			else{
				
				cout<<"Do You Need A Key : ";
				cin>>choice;
				
				temp = head;
				
				if(choice == 'y'){
					cout<<"Enter The Key After Which You Want To Add : ";
					cin>>key;
					
					
					
					while(temp != NULL){
						
						if(temp->info == key){
							temp1 = new Node;
							
							cout<<"Enter The Value In The New Node : ";
							cin>>temp1->info;
							
							temp1->next = temp->next;
							
							temp->next = temp1;
							
						}
						
						temp = temp->next;
					}
				}
				else{
					
					temp = head;
					
					while(temp != NULL){
						
						if(temp->next == NULL){
							
							temp1 = new Node;
							
							temp->next = temp1;
							
							temp1->next = NULL;
							
							cout<<"Enter The Number In The Node : ";
							cin>>temp1->info;
							
							return;
							
						}
						
						temp = temp->next;
					}
					
					
					
				}
				
				
			}
			
			
		}
		
		
		void del() {
		    int key;
		
		    cout << "Enter The Number That You Want To Delete : ";
		    cin >> key;
		
		    while(head != NULL && head->info == key){
		    	temp = head;
		    	
		    	head = head->next;
		    	
		    	delete temp;
			}
			
			temp = head;
			
			while(temp !=  NULL && temp->next != NULL){
			
				if(temp->next->info == key){
					
					temp1 = temp->next;
					
					temp->next = temp1->next;
					
					delete temp1;
				
				}
				else{
					temp = temp->next;
				}
				
				
				
			}
		}


		void checkKeyPresent(){
			
			if(head == NULL){
				cout<<"Nothing In The LL"<<endl<<endl;
				return;
			}
			
			int key;
			cout<<"Enter The key To Find : ";
			cin>>key;
			
			Node *temp2 ;
			Node *valuePoint;
			
			valuePoint = head;
			
			if(valuePoint->info == key){
				cout<<"It Is Present In First Half"<<endl;
				return;
			}
			
			while(valuePoint->info != key ){
				
				
				valuePoint = valuePoint->next;
				
				if(valuePoint == NULL){
					break;
				}
			}
			
			if(valuePoint == NULL){
				cout<<"The Key Is Not Present In The Linked List"<<endl;
				return;
			}
			
			temp = head;
			temp2 = valuePoint;
			
			while(temp2->next != NULL && temp != valuePoint){
				temp2 = temp2->next;
				temp = temp->next;
			}
			
			if(temp2->next == NULL && temp == valuePoint){
				cout<<"It Is Present In The Middle"<<endl;
			}
			else if(temp2->next == NULL && temp != valuePoint){
				cout<<"It is In The Second Half"<<endl;
			}
			else{
				cout<<"It is In The First Half"<<endl;
			}
			
		}

		
		void print(){
			
			temp = head;
			
			while(temp != NULL){
				
				cout<<temp->info<<" ";
				
				temp = temp->next;
			}
			
			cout<<endl<<endl<<endl;
		}
};




int main(){
	
	int option;
	
	LinkedList A;
	
	
	
	do{
		
		cout<<"1. To Add"<<endl;
		cout<<"2. To Print"<<endl;
		cout<<"3. To Delete"<<endl;
		cout<<"4. Check Where Key Is Present"<<endl;
		cout<<"5. Exit"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
	
		if(option == 1){
			A.add();
		}
		else if(option == 2){
			A.print();
		}
		else if(option == 3){
			A.del();
		}
		else if(option == 4){
			A.checkKeyPresent();
		}
		else if(option == 5){
			break;
		}
		else{
			cout<<"Wrong Option "<<endl;
		}
	
	
		cout<<endl<<endl<<endl;
	}
	while(1);
	
	
	
	return 0;
}