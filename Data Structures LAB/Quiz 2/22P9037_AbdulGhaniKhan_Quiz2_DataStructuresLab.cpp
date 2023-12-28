#include<iostream>
#include<string.h>

using namespace std;

struct Node{

	Node *next;
	string info;
	
	Node(){
		next = NULL;
		info = "-";
	}
		
};

class LL{
	private:
		Node *head1;
		Node *head2;
		
		Node *temp;
		Node *temp1;
		
		
	public:
		LL(){
			head1 = NULL;
			head2 = NULL;
			temp = NULL;
			temp1 = NULL;
			
		}
		
		void inserthead1(string a){
			
			if(head1 == NULL){
				head1 = new Node;
				head1->next = NULL;
				
				head1->info = a;
				
				return;
			}
			
			temp = head1;
			
			while(temp->next != NULL){
				temp = temp->next;
			}
			
			temp->next = new Node;
			temp->next->info = a;
			
			
			temp = head1;
			
			return;
		}
		
		void inserthead2(string a){
			
			if(head2 == NULL){
				head2 = new Node;
				head2->next = NULL;
				
				head2->info = a;
				
				return;
			}
			
			temp = head2;
			
			while(temp->next != NULL){
				temp = temp->next;
			}
			
			temp->next = new Node;
			temp->next->info = a;
			
			
			temp = head2;
			
			return;
		}
		
		string deletionhead1(string a){
			
			string toreturn;
			
			temp = head1;
				
				if(head1->info == a){
					temp1 = head1;
					head1 = head1->next;
					
					
					toreturn = temp1->info;
					
					delete temp1;
					temp1 = head1;
					
					return toreturn;
				}
				else{
					
					while(temp->next->info != a){
						temp = temp->next;	
					}
					
					temp1 = temp->next;
					temp->next = temp1->next;
					
					
					toreturn = temp1->info;
					delete temp1;
					
					return toreturn;
				
				}
				
			
			
		}
		
		string deletionhead2(string a){
			
			string toreturn;
			
				temp = head2;
				
				if(head2->info == a){
					temp1 = head2;
					head2 = head2->next;
					
					toreturn = temp1->info;
					
					delete temp1;
					temp1 = head2;
					return toreturn;
				}
				else{
					
					while(temp->next->info != a){
						temp = temp->next;	
					}
					
					temp1 = temp->next;
					temp->next = temp1->next;
					
					toreturn = temp1->info;
					
					delete temp1;
					
					return toreturn;
					
				}
				
			
			
			
		}
			
		
		
		void printhead1(){
			
			if(head1 == NULL){
				cout<<"Nothing To Print"<<endl<<endl;
				
				return;
			}
			
			temp = head1;
			
			while(temp != NULL){
				cout<<temp->info<<" ";
				
				temp = temp->next;
			}
		}
		
		void printhead2(){
			
			if(head2 == NULL){
				cout<<"Nothing To Print"<<endl<<endl;
				
				return;
			}
			
			
			temp = head2;
			
			while(temp != NULL){
				cout<<temp->info<<" ";
				
				temp = temp->next;
			}
		}
};



class Stack{
	private:
		string *Array;
		int size;
		int counter;
		string *head;
		string *temp;
		
	public:
		Stack(){
		
			counter = 0;
			
			temp = NULL;
		}
		
		void initialization(int size){
			
			this->size = size;
			Array = new string[size];
			head = NULL;
			
			return;
		}
		
		
		void push(string a){
			if(counter <= size){
				
				if(head == NULL){
					head = Array;
					*head = a;
					
					counter++;
					
					return;
				}
				
				head++;
				
				*head = a;
				
				counter++;
				
			}
		}
		
		string pop(){
			
			if(counter == 1){
				temp = head;
				head = NULL;
				
				counter--;
				
				return *temp;
			
			}
			
			
				
				temp = head;
				
				head--;
				counter--;
				
				return *temp;
			
			
		}
};



int main(){
	
	LL A;
	Stack B;
	int option;
	int words;
	
	
	cout<<"Welcome To The Treasure Hunt Game "<<endl<<endl;
	cout<<"Your First Task Is To Reach To The First Marked Location"<<endl<<endl;
	cout<<"Press 1 When You Find The Location Or Press 0 To Leave The Game : ";
	cin>>option;
	
	if(option == 1){
		cout<<"Nice Dig The Place And Find The Encrypted Message"<<endl<<endl;
		cout<<"Enter The Number Of Words In The Message : ";
		cin>>words;
		
		B.initialization(words);
		
		string Array[words];
		
		cout<<"Now Enter The Words One By One :- "<<endl<<endl;
		
		for(int i=0;i<words;i++){
			cout<<i+1<<". "; cin>>Array[i];
		}
		
		cout<<"Perfect Now Wait For Me To Decrypt It :-"<<endl<<endl;
		
		for(int i=0; i<words ; i++){
			A.inserthead1(Array[i]);
		}
		
		for(int i=0; i<words ; i++){
			B.push(A.deletionhead1(Array[i]));
		}
		
		for(int i=0;i<words;i++){
			Array[i] = B.pop();
		}
		
		
		
		cout<<"The Decrypted Message Is :- "<<endl<<endl;
		
		for(int i=0; i<words ; i++){
			A.inserthead1(Array[i]);
		}
		
		A.printhead1();
		
		cout<<endl<<endl;
		
		cout<<"Now Go To This Location Fast And Again Do The Same Process"<<endl<<endl;
		cout<<"Press 1 When You Find The Location Or Press 0 To Exit : ";
		cin>>option;
		
		if(option == 1){
			cout<<"Well Done Now Dig The Place And Find The Next Encrypted Message"<<endl<<endl;
			cout<<"Enter The Number Of Words In The Message Now : ";
			cin>>words;
			
			B.initialization(words);
			
			string Array2[words];
			
			cout<<"Now Enter Each Word One By One :-"<<endl<<endl;
			
			for(int i=0; i<words; i++){
				cout<<i+1<<". "; cin>>Array2[i];
			}
			
			cout<<"Excellent Now Wait For Me To Decrypt This Message :- "<<endl<<endl;
			
			for(int i=0; i<words ; i++){
				A.inserthead2(Array2[i]);
			}
			
			for(int i=0; i<words ; i++){
				B.push(A.deletionhead2(Array2[i]));
			}
			
			for(int i=0;i<words;i++){
				Array2[i] = B.pop();
			}
			
			
			cout<<"The Decrypted Message Is :- "<<endl<<endl;
		
			for(int i=0; i<words ; i++){
				A.inserthead2(Array2[i]);
			}
			
			A.printhead2();	
			
			cout<<endl<<endl;
			
			cout<<"Now Run For The Treasure This Is The Final Location Of The Treasure"<<endl<<endl;
			cout<<"Youve Found It Congeratulations"<<endl<<endl; 
		}
		else{
			cout<<"Atleast You Found The First Location Good Luck Next Time "<<endl<<endl;
		}
		
	}
	else{
		cout<<"You Didnt Even Find The First Location"<<endl<<endl;
	}
	
	
	
	return 0;
}


