#include<iostream>
#include<string.h>

using namespace std;


struct Node{

	string name;
	Node *next;
	
};


class CRL{
	private:
		Node *head;
		Node *temp;
		int length;
		int max;
		Node *tail;
		Node *temp1;
		
		
	public:
		CRL(int max){
			head = NULL;
			temp = NULL;
			temp1 = NULL;
			length = 0;
			this->max = max;
			tail = NULL;
		}
		
		void addAllNames(){
			
			string line;
			
			if(head == NULL){
				cout<<"Enter The Name Of The 1st Student : ";
				fflush(stdin);
				getline(cin,line);
				
				head = new Node;
				head->next = head;
				head->name = line;
			}
			
			temp = head;
			
			
			for(int i=2;i <= max;i++){
				
				temp1 = new Node;
				temp->next = temp1;
				temp1->next = head;
				
				cout<<"Enter The Name Of The "<<i<<"nd Student : ";
				fflush(stdin);
				getline(cin,line);
				
				temp1->name = line;
				
				temp = temp->next;
				
				tail = temp1;
				
			}
			
			
			
			cout<<"All Names Successfully Added"<<endl<<endl;
			
		}
		
		void startRound(int remove){
			
			if(remove < 0){
				cout<<"Not A Valid Number"<<endl;
				return;
			}
			
			temp = head;
			
			if(remove == 0){
				tail->next = head->next;
				
				cout<<"The Guy Who Lost Is "<<head->name<<endl;
				
				delete head;
				head = tail->next;
				
				max--;
				
				print();
				
				return;
			}
			
			if(max == 1){
				cout<<"You Already Have The Winner He Is : "<<temp->name<<endl;
				
				return;
			}
			
			
			int counter = 0;
			
			temp = head;
			temp1 = head->next;
			
			if(remove != 0){
				counter++;
			}
			
			
			while(counter < remove){
				temp = temp->next;
				temp1 = temp1->next;
				
				counter++;
			}
			
			temp->next = temp1->next;
			
			cout<<"The Guy Who Lost Was : "<<temp1->name<<endl;
			
			if(temp1 == head){
				head = temp;
			}
			
			delete temp1;
			
			max--;
			
			print();
			
			
		}
		
		
		void print(){
			
			temp = head;
			
			cout<<"Student Are :-"<<endl<<endl;
			
			for(int i=1;i<=max;i++){
				cout<<temp->name<<endl;
				
				temp = temp->next;
		
			}
			
			
		}
		
		int returnMax(){
			return max;
		}
		
		string returnWinner(){
			return head->name;
		}
		
};



int main(){
	
	int option;
	int number;
	int removeNum;
	char yesno;
	
	do{
		cout<<"Press 1 To Start The Game : ";
		cin>>option;
		
		if(option == 1){
			cout<<"Enter The Number Of Players : ";
			cin>>number;
			
			if(number < 2 ){
				cout<<"You Need Atleast 2 Person For The Game "<<endl<<endl;
			}
			else{
				
				cout<<"Enter the Number After Which The Person Will Loose "<<endl;
				cout<<"For Example If You Enter 5 After 5 Seats The Person Will Loose"<<endl<<endl;
					
				cout<<"Enter Number : ";
				cin>>removeNum;
				
				if(removeNum < 1){
					cout<<"This Number Should Be Atleast 1 Or Greater : ";
				}
				else{
					
					CRL A(number);
					A.addAllNames();
					
					do{
						
						cout<<"Enter 1 For The Round To Start : ";
						cin>>option;
						
						if(option == 1){
							A.startRound(removeNum);
						}
						
					}
					while(A.returnMax() != 1 && option == 1);
					
					if(A.returnMax() == 1){
						cout<<endl;
					
						cout<<"The Winner Is : "<<A.returnWinner();
						
						cout<<endl<<endl;
					}
					
					cout<<endl<<endl;
					
				}
				
				
			}
		}
		else{
			cout<<"Wrong Input"<<endl;
		}
		
		cout<<"Do You Want To Play The Game Again ? : y/n : ";
		cin>>yesno;
		
	}
	while(yesno == 'y');
}