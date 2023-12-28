#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct Node{

	int info;
	Node *left;
	Node *right;
	int counter;
	string name;
	
	Node(){
		left = NULL;
		right = NULL;
		counter = 0;
		name = "\0";
	}
	
};


class Tree{
	public:
		Node *head;
		Node *temp;
		Node *temp1;
		
	
		Tree(){
			head = NULL;
			temp = NULL;
			temp1 = NULL;
		}
		
		
	void insert(int key , string stone ,  Node* temp ){
		
		if(temp == NULL){
			temp = new Node;
			temp->info = key;
			temp->name = stone;
			
			head = temp;
			
			return;
		}
		
		if(temp->left == NULL && key < temp->info){
			temp->left = new Node;
			temp->left->info = key;
			temp->left->name = stone;
			
			return;
		}
		
		if(temp->right == NULL && key > temp->info){
			temp->right = new Node;
			temp->right->info = key;
			temp->right->name = stone;
			
			return;
		}
			
		if(key < temp->info && temp->left != NULL){
			insert(key , stone , temp->left);
		}
		
		if(key > temp->info && temp->right != NULL){
			insert(key , stone , temp->right);
		}
		
		if(key == temp->info){
			
			cout<<"Dublicate Cannot Be Stored"<<endl<<endl;
			
			temp->counter++;
		}
			
	}
		
	
	
	void pre_orderSearch(Node* head){
		
		if(head == NULL){
			return ;
		}
		
		cout<<"["<<head->name<<" , "<<head->info<<"]"<<endl;
		
		if(head->left != NULL){
			pre_orderSearch(head->left);
		}
		
		
		if(head->right != NULL){
			pre_orderSearch(head->right);
		}
		
	}
	
	
	Node* searchThroughPower(Node* head , int key){
		
		Node *Found = new Node;
		Found->info = 0;
		
		if(head == NULL){
			return Found;
		}
		
		
		if(head->info == key){
			
			Found = head;
			
			return Found;
		}
		
		
		if(head->left != NULL && Found->info != key){
		    Found = searchThroughPower(head->left , key);
		}
		
		
		if(head->right != NULL && Found->info != key){
			Found = searchThroughPower(head->right , key);
		}
		
		return Found;
		
	}
	
	
	void in_orderSearch(Node* head){
		
		if(head == NULL){
			return ;
		}
		
		if(head->left != NULL){
			in_orderSearch(head->left);
		}
		
		cout<<"["<<head->name<<" , "<<head->info<<"]"<<endl;
		
		if(head->right != NULL){
			in_orderSearch(head->right);
		}
		
	}
	
	
	void post_orderSearch(Node* head){
		
		if(head == NULL){
			return ;
		}
		
		
		
		if(head->left != NULL){
			post_orderSearch(head->left);
		}
		
		
		if(head->right != NULL){
			post_orderSearch(head->right);
		}
		
		cout<<"["<<head->name<<" , "<<head->info<<"]"<<endl;
				
	}
	
	Node* returnSuccessor(Node* temp ){
		
		if(temp->left != NULL){
			if(temp->left->left != NULL){
				
				return returnSuccessor(temp->left);
			
			}
			else{
				return temp;
			}
		}
		else{
			return temp;
		}
		
	}
	
	Node* returnMax(Node* temp){
		
		if(temp->right == NULL){
			return temp;
		}
		else{
			
			while(temp->right != NULL){
				temp = temp->right;
			}
			
			return temp;
			
		}
			
	}
	
	void deletion(int key , Node* head){
		if(head == NULL){
			return;
		}
		
		//Case 3 And All Possible Head Cases
		
		if(head->info == key && head->left != NULL && head->right != NULL){
				
				if(head->right->left == NULL){
					head->info = head->right->info;
					
					temp = head->right;
					head->right = temp->right;
					
					delete temp; 
					
				}
				else{
				
					temp = returnSuccessor(head->right);
				
					head->info = temp->left->info;
					temp1 = temp->left;
					
					temp1 = temp1->right;
					
					delete temp->left;
					
					temp->left = temp1;
					
				}
				
		}
		
		if(this->head->info == key && this->head->right != NULL && this->head->left == NULL){
			temp = head;
			this->head = this->head->right;
			
			delete temp; 
			
			return;
		}
		
		if(this->head->info == key && this->head->left != NULL && this->head->right == NULL){
			temp = head;
			this->head = this->head->left;
			
			delete temp;
			
			return;
		}
		
		if(this->head->info == key && this->head->right == NULL && this->head->left == NULL ){
			delete this->head;
			
			this->head = NULL;
			
			return;
		}
		
		
		//Leaf Cases
		
		
		if(head->left != NULL){
			
			if( head->left->info == key && head->left->left == NULL && head->left->right == NULL){
				temp = head->left;
				head->left = temp->left;
				
				delete temp;
			}
			
		}
		
		if(head->right != NULL){
			if( head->right->info == key && head->right->right == NULL && head->right->left == NULL){
				temp = head->right;
				head->right = temp->right;
				
				delete temp;
			}
		}
		
		
		
		// Single Child Cases;
		
		
		if(head->left != NULL){
			 
			if((head->left->info == key && head->left->right == NULL && head->left->left != NULL) || (head->left->info == key && head->left->right != NULL && head->left->left == NULL)){
				if(head->left->info == key && head->left->right == NULL && head->left->left != NULL){
					temp = head->left;
					head->left = temp->left;
					
					delete temp;
				}
				if(head->left->info == key && head->left->right != NULL && head->left->left == NULL){
					temp = head->left;
					head->left = temp->right;
					
					delete temp;
				}
			 
			}
		
		}
		
		if(head->right != NULL){
			
			if((head->right->info == key && head->right->right == NULL && head->right->left != NULL) || (head->right->info == key && head->right->right != NULL && head->right->left == NULL)){
				if(head->right->info == key && head->right->right == NULL && head->right->left != NULL){
					temp = head->right;
					head->right = temp->left;
					
					delete temp;
				}
				if(head->right->info == key && head->right->right != NULL && head->right->left == NULL){
					temp = head->right;
					head->right = temp->right;
					
					delete temp;
				}
			}
			
		}
		
		
			
			
		// No Cases Hold For The key Recursively Move On
			
			
		if(key < head->info && head->left != NULL){
			deletion(key , head->left);
		}
			
		if(key > head->info && head->right != NULL){
			deletion(key , head->right);
		}
			
		
	}
	
	

	
};

void insertGems(Tree *T){
	
	T->insert(50 , "Diamond" , T->head);
	T->insert(30 , "Ruby" , T->head);
	T->insert(70 , "Sapphire" , T->head);
	T->insert(40 , "Pearl" , T->head);
	T->insert(10 , "Opal" , T->head);
	T->insert(60 , "Garnet" , T->head);
	T->insert(20 , "Zircon" , T->head);
	T->insert(5 , "Jade" , T->head);
	
}



int main(){
	
	Tree T;
	int option;
	int number;
	int option2;
	string stoneName;
	Node *Needed;
	
	
	int bag;
	int maxCapacityOfTheBag;
	
	cout<<" __________________________________"<<endl;
	cout<<"|                                  |"<<endl;
	cout<<"|   WELCOME TO THE MAGICAL FOREST  |"<<endl;
	cout<<"|__________________________________|"<<endl<<endl;
	
	
	cout << "        ^              ^    " << endl;
    cout << "       ^^^            ^^^   " << endl;
    cout << "      ^^^^^          ^^^^^  " << endl;
    cout << "     ^^^^^^^        ^^^^^^^ " << endl;
    cout << "    ^^^^^^^^^      ^^^^^^^^^" << endl;
    cout << "        |              |    " << endl<<endl<<endl;
	
	cout<<"How Much Magical Power Can Your Bag Hold ?? : ";
	cin>>maxCapacityOfTheBag;
	
	insertGems(&T);
	
	do{		
	
		
		cout<<"1. Display The Magical Tree "<<endl;
		cout<<"2. Search For A Gem By Specifying Its Power "<<endl;
		cout<<"3. Find The Gem With The Highest Magical Power"<<endl;
		cout<<"4. Pluck A Gem From The Tree"<<endl;
		cout<<"5. Exit"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		cout<<endl<<endl;
		
		if(option == 1){
				
			cout<<"Which Traversal Do You Want :- "<<endl<<endl;
			cout<<"1. Pre - Order Traversal "<<endl;
			cout<<"2. In - Order Traversal "<<endl;
			cout<<"3. Post - Traversal "<<endl<<endl;
			cout<<"Enter Your Option : ";
			cin>>option2;
				
			if(option2 == 1){
				T.pre_orderSearch(T.head);
			}
			else if(option2 == 2){
				T.in_orderSearch(T.head);
			}
			else if(option2 == 3){
				T.post_orderSearch(T.head);
			}
			else{
				cout<<"Wrong Option"<<endl;
			}
				
			
			
		}
		else if(option == 2){
						
			cout<<"Enter The Power Of A Gem To Search For It : ";
			cin>>option2;
			
			Needed = T.searchThroughPower(T.head , option2);
			
			if(Needed->info == option2){
				
				cout<<"["<<Needed->name<<" , "<<Needed->info<<"]"<<endl;
				
			}
			else{
				cout<<"Not Found It Is Not In The Tree"<<endl;
			}
			
		}
		else if(option == 3){
			
			
			Needed = T.returnMax(T.head);
			
			cout<<"["<<Needed->name<<" , "<<Needed->info<<"]"<<endl;
			
		}
		else if(option == 4){
						
			T.in_orderSearch(T.head);
			
			cout<<"Enter The Power Of The Gem That You Want To Pluck : ";
			cin>>number;
			
			Needed = T.searchThroughPower(T.head , number);
			
			
			if(Needed->info == number){
				
				cout<<"Plucked Successfully"<<endl;
				cout<<"["<<Needed->name<<" , "<<Needed->info<<"] Is In The Bag "<<endl;
				
				bag = bag + Needed->info;
				
				T.deletion(Needed->info , T.head);
				
			}
			else{
				cout<<"Wrong Power It Was Not Found"<<endl;
			}
			
		}
		else if(option == 5){
			break;
		}
	
		
		cout<<endl<<endl;
		
		if(bag == maxCapacityOfTheBag){
			cout<<" _________________________________________________________"<<endl;
			cout<<"|                                                         |"<<endl;
			cout<<"|  You Won !!!  Now Take The Bag And Run From The Forest  |"<<endl;
			cout<<"|        Be Advised The Witch Now Knows About This        |"<<endl;
			cout<<"|    Make Your Way Out Before You  Get Caught By Her !!   |"<<endl;
			cout<<"|_________________________________________________________|"<<endl<<endl;
			
			break;
		}
		else if(bag > maxCapacityOfTheBag){
			
			cout<<" _________________________________________________________"<<endl;
			cout<<"|                                                         |"<<endl;
			cout<<"|  You've Lost , Your Bag Burst , Greediness It Is !!!!!  |"<<endl;
			cout<<"|        Be Advised The Witch Now Knows About This        |"<<endl;
			cout<<"|       Run For Your Life Before She Catches You !!       |"<<endl;
			cout<<"|_________________________________________________________|"<<endl<<endl;
			
			break;
		}
		
		
		
		cout<<endl<<endl;
				
	}
	while(option != 6);


	
	
}