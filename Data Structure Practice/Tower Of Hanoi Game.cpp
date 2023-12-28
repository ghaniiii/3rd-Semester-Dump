#include<iostream>
#include<string.h>

using namespace std;


struct Node{
	
	int info;
	Node* next;
	
		Node(){
			info = 0;
			next = NULL;
		}
		
};

class Stack{
	
	public:
	
	Node* top1;
	Node* top2;
	Node* top3;
	Node* temp;
	
	int limit;
	
	int size1;
	int size2;
	int size3;
	
	int counter = 0;
	
	
	Stack(int number){
		top1 = NULL;
		top2 = NULL;
		top3 = NULL;
		limit = number;
		temp = NULL;
		size1 = 0;
		size2 = 0;
		size3 = 0; 
		
		for(int i = number ; i > 0 ; i--){
			enque1(i);
		}
		
		size1 = number;
	}
	
	bool isFull1(){
		if(size1 == limit){
			return true;
		}
		else{
			return false;
		}
	}

	bool isFull2(){
		if(size2 == limit){
			return true;
		}
		else{
			return false;
		}
	}
	
	bool isFull3(){
		if(size3 == limit){
			return true;
		}
		else{
			return false;
		}
	}
	
	bool isEmpty1(){
		if(top1 == NULL){
			return true;
		}
		else{
			return false;
		}
	}
	
	bool isEmpty2(){
		if(top2 == NULL){
			return true;
		}
		else{
			return false;
		}
	}
	
	bool isEmpty3(){
		if(top3 == NULL){
			return true;
		}
		else{
			return false;
		}
	}
	
	void enque1(int number){
		
		if(size1 <= limit){
		
			if(top1 == NULL){
			top1 = new Node;
			top1->info = number;
			size1++;
			
				return; 
			}
			
			temp = new Node;
			temp->info = number;
			temp->next = top1;
			top1 = temp;
			
			
			
			size1++;
		
		}
		else{
			cout<<"This Peg is Full Cannot Add Another Disk "<<endl;
		}
			
	}
	
	void enque2(int number){
		
		if(size2 <= limit){
		
			if(top2 == NULL){
			top2 = new Node;
			top2->info = number;
			size2++;
			
				return; 
			}
			
			temp = new Node;
			temp->info = number;
			temp->next = top2;
			top2 = temp;
			
			size2++;
		
		}
		else{
			cout<<"This Peg is Full Cannot Add Another Disk "<<endl;
		}
			
	}
	
	void enque3(int number){
		
		if(size3 <= limit){
		
			if(top3 == NULL){
			top3 = new Node;
			top3->info = number;
			size3++;
			
				return; 
			}
			
			temp = new Node;
			temp->info = number;
			temp->next = top3;
			top3 = temp;
			
			size3++;
		
		}
		else{
			cout<<"This Peg is Full Cannot Add Another Disk "<<endl;
		}
			
	}
	
	int deque1(){
		if(size1 > 0){
			
			int number = top1->info;
			temp = top1;
			top1 = top1->next;
			delete temp;
			size1--;
			
			return number;
			
		}
		else{
			cout<<"There is Nothing In This Peg To Move"<<endl;
			return -1;
		}
	}
	
	int deque2(){
		if(size2 > 0){
			
			int number = top2->info;
			temp = top2;
			top2 = top2->next;
			delete temp;
			
			size2--;
			return number;
			
		}
		else{
			cout<<"There is Nothing In This Peg To Move"<<endl;
			return -1;
		}
	}
	
	int deque3(){
		if(size3 > 0){
			
			int number = top3->info;
			temp = top3;
			top3 = top3->next;
			delete temp;
			size3--;
			
			return number;
			
		}
		else{
			cout<<"There is Nothing In This Peg To Move"<<endl;
			return -1;
		}
	}
	
	void print1(){
		temp = top1;
		
		if(temp == NULL){
			cout<<"Empty"<<endl;
		}
		
		while(temp != NULL){
			cout<<"  "<<temp->info<<endl;
			
			temp = temp->next;
		}
		
		cout<<"-----"<<endl;
		cout<<"Peg 1"<<endl;
		cout<<"-----"<<endl;
		cout<<endl<<endl;
	}
	
	void print2(){
		temp = top2;
		
		if(temp == NULL){
			cout<<"Empty"<<endl;
		}
		
		while(temp != NULL){
			cout<<"  "<<temp->info<<endl;
			
			temp = temp->next;
		}
		
		cout<<"-----"<<endl;
		cout<<"Peg 2"<<endl;
		cout<<"-----"<<endl;
		cout<<endl<<endl;
	}
	
	void print3(){
		temp = top3;
		
		if(temp == NULL){
			cout<<"Empty"<<endl;
		}
		
		while(temp != NULL){
			cout<<"  "<<temp->info<<endl;
			
			temp = temp->next;
		}
		
		cout<<"-----"<<endl;
		cout<<"Peg 3"<<endl;
		cout<<"-----"<<endl;
		cout<<endl<<endl;
	}
};


int main(){
	
	Stack A(4);
	int option = 1;
	
	int decision1;
	int decision2;
	
	int temp;
	int counter = 0;
	
	do{
		A.print1();
		A.print2();
		A.print3();
		
		cout<<"Move From : ";
		cin>>decision1;
		
		if(decision1 == 1){
			
			if(!A.isEmpty1()){
				cout<<"Move To : ";
				cin>>decision2;
				
				if(decision2 == 1){
					counter++;
				}
				else if(decision2 == 2){
					
					if(!A.isFull2()){
						
						if(A.top2 == NULL){
							temp = A.deque1();
							A.enque2(temp);
							counter++;
						}
						else if(A.top1->info < A.top2->info ){
							temp = A.deque1();
							A.enque2(temp);
							counter++;
						}
						else{
							cout<<"Voilating Rule 2\nA Larger Disk Cannot Be Placed On Top Of A Smaller One"<<endl;
						}	
						
					}
					else{
						cout<<"This Peg Is Already Full"<<endl;
					}
				}
				else if(decision2 == 3){
					
					if(!A.isFull3()){
						
						if(A.top3 == NULL){
							temp = A.deque1();
							A.enque3(temp);
							counter++;
						}
						else if(A.top1->info < A.top3->info ){
							temp = A.deque1();
							A.enque3(temp);
							counter++;
						}
						else{
							cout<<"Voilating Rule 2\nA Larger Disk Cannot Be Placed On Top Of A Smaller One"<<endl;
						}
						
					}
					else{
						cout<<"This Peg Is Already Full"<<endl;
					}
					
				}
				else{
					cout<<"Wrong Option "<<endl;
				}
			}
			else{
				cout<<"The Peg Has No Disks"<<endl;
			}
			
		}
		else if(decision1 == 2){
			if(!A.isEmpty2()){
				cout<<"Move To : ";
				cin>>decision2;
				
				if(decision2 == 1){
					if(!A.isFull1()){
						if(A.top1 == NULL){
							temp = A.deque2();
							A.enque1(temp);
							counter++;
						}
						else if(A.top2->info < A.top1->info ){
							temp = A.deque2();
							A.enque1(temp);
							counter++;
						}
						else{
							cout<<"Voilating Rule 2\nA Larger Disk Cannot Be Placed On Top Of A Smaller One"<<endl;
						}
						
						
					}
					else{
						cout<<"This Peg Is Already Full"<<endl;
					}
				}
				else if(decision2 == 2){
					counter++;
				}
				else if(decision2 == 3){
					if(!A.isFull3()){
						if(A.top3 == NULL){
							temp = A.deque2();
							A.enque3(temp);	
							counter++;
						}
						else if(A.top2->info < A.top3->info ){
							temp = A.deque2();
							A.enque3(temp);	
							counter++;
						}
						else{
							cout<<"Voilating Rule 2\nA Larger Disk Cannot Be Placed On Top Of A Smaller One"<<endl;
						}
													
					}
					else{
						cout<<"This Peg Is Already Full"<<endl;
					}
				}
				else{
					cout<<"Wrong Option "<<endl;
				}
				
			}
			else{
				cout<<"The Peg Has No Disks"<<endl;
			}
		}
		else if(decision1 == 3){
			
			if(!A.isEmpty3()){
				cout<<"Move To : ";
				cin>>decision2;
				
				if(decision2 == 1){
					if(!A.isFull1()){
						if(A.top1 == NULL){
							temp = A.deque3();
							A.enque1(temp);
							counter++;
						}
						else if(A.top3->info < A.top1->info ){
							temp = A.deque3();
							A.enque1(temp);
							counter++;
						}
						else{
							cout<<"Voilating Rule 2\nA Larger Disk Cannot Be Placed On Top Of A Smaller One"<<endl;
						}
						
					}
					else{
						cout<<"This Peg Is Already Full"<<endl;
					}
				}
				else if(decision2 == 2){
					if(!A.isFull2()){
						if(A.top2 == NULL){
							temp = A.deque3();
							A.enque2(temp);
							counter++;
						}
						else if(A.top3->info < A.top2->info ){
							temp = A.deque3();
							A.enque2(temp);
							counter++;
						}
						else{
							cout<<"Voilating Rule 2\nA Larger Disk Cannot Be Placed On Top Of A Smaller One"<<endl;
						}
						
					}
					else{
						cout<<"This Peg Is Already Full"<<endl;
					}
				}
				else if(decision2 == 3){
					counter++;
				}
				else{
					cout<<"Wrong Option "<<endl;
				}
				
			}
			else{
				cout<<"The Peg Has No Disks"<<endl;
			}
			
		}
		else{
			cout<<"Wrong Option "<<endl;
		}
		
		int counter2 = 1;
		
		int i = 1;
			A.temp = A.top3;
			while(A.temp != NULL){
				if(A.temp->info == i){
					counter2++;
				}
				A.temp = A.temp->next;
				i++;
			}
		
		
		if(counter2 == 5){
			cout<<"You Have Won The Game"<<endl<<endl;
			cout<<"And Have Completed It In "<<counter<<" Moves"<<endl;
			break;
		}
		
	}
	while(option);
	
	
	
	return 0;
}