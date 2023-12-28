#include<iostream>

using namespace std;

struct Node{
	Node* next;
	float val;
	
	Node(){
		next = NULL;
		val = 0;
	}
};

class BucketSort{
	
	public:	
	
	float number2;
	int number;
	
	
	Node array[10];
	
	void insert(){
		
		number = number2;
		int toplace;
		
		if(number < 0){
			number = number * -1;
			toplace = number % 10;
			number = number * -1;
		}
		else{
			toplace = number % 10;
		}
		
		
		
		
		if(array[toplace].next == NULL){
			array[toplace].next = new Node;
			array[toplace].next->val = number2;
			array[toplace].val++;
			return;
		}
		
		Node *temp;
		temp = array[toplace].next;
		
		
		while(temp->next != NULL){
			temp = temp->next;
		}
		
		temp->next = new Node;
		temp->next->val = number2;
		array[toplace].val++;
		
		
		return;
	}
	
	
	void sort(){
		
		int count = 0;
		Node* temp;
		
		float temp2;
		
		for(int i=0;i<10;i++){
			
			temp = array[i].next;
			
			if(temp != NULL)
			while(count <= array[i].val){
				
				if(temp->next != NULL){
					if(temp->val > temp->next->val){
						temp2 = temp->next->val;
						temp->next->val = temp->val;
						temp->val = temp2;
						count = 0;
					}
					
					temp = temp->next;
				}
				
				if(temp->next == NULL){
					temp = array[i].next;
				}
				
				count++;
			}
		}
		
	}
	
	
	void print(){
		
		Node *temp;
		
		for(int i=0;i<10;i++){
			temp = &array[i];
			cout<<i<<":  ";
			while(temp != NULL){
				cout<<temp->val<<" ";
				
				temp = temp->next;
			}
			
			cout<<endl;
			
		}
		
		cout<<endl<<endl;
	}
	
	
	
};



int main(){
	
	BucketSort T;
	int option;
	
	while(1){
		cout<<"1. Insert "<<endl;
		cout<<"2. Sort "<<endl;
		cout<<"3. Print"<<endl;
		cout<<"4. Exit"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			
			cout<<"Enter The Number : ";
			cin>>T.number2;
			T.insert();
		}
		else if(option == 2){
			T.sort();
		}
		else if(option == 3){
			T.print();
		}
		else if(option == 4){
			break;
		}
		else{
			cout<<"Wrong Option"<<endl<<endl;
		}
		
		
		cout<<endl<<endl;
	}
	
	
	
	return 0;
}