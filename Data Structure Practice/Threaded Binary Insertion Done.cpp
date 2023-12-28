#include<iostream>
#include<string.h>

using namespace std;

struct Node{
	
	int info;
	Node* left;
	Node* right;
	int LTH;
	int RTH;
	
	Node(){
		left = NULL;
		right = NULL;
	}
		
};

class tree{
	
	public:
		Node* root;
		Node* temp;
		Node* temp3;
		Node* parent;
		
		int number;
		
	
	tree(){
		root = new Node;
		root->info = 10;
		root->left = root;
		root->LTH = 0;
		root->right = root;
		root->RTH = 0;
		
		parent = NULL;
		temp3 = NULL;
		
	}
	
	void insertion(Node* head){
		
		if(root->info <= number){
			root->info = number + 1;
		}
		
		if(head == root && root->left == root){
			
			temp = new Node;
			temp->info = number;
			
			temp->left = root->left;
			temp->LTH = 1;
			
			temp->right = root;
			temp->RTH = 1;
			
			root->left = temp;
			root->LTH = 0;
			
			return;
		}
		
		
		if(number < head->info && head->LTH != 1){
			insertion(head->left);
		}
		else if(number == head->info){
			cout<<"Cannot Add A Duplicate"<<endl<<endl;
		}
		else if(number > head->info && head->RTH != 1){
			insertion(head->right);
		}
		else{
			if(number < head->info){
				
				temp = new Node;
				temp->info = number;
				
				temp->left = head->left;
				temp->LTH = 1;
				temp->right = head;
				temp->RTH = 1;
				head->left = temp;
				
				head->LTH = 0;
				
			}
			else{
				
				temp = new Node;
				temp->info = number;
				
				temp->right = head->right;
				temp->RTH = 1;
				
				temp->left = head;
				temp->LTH = 1;
				head->right = temp;
				
				head->RTH = 0;
				
			}
		}
		
	}
	
	Node* findSuccessor(Node* head){
		while(head->left != NULL){
			head = head->left;
		}
		
		return head;
	}
	
	Node* nextInOrder(Node* head){
		if(head->RTH == 1){
			return head->right;
		}
		else{
			head = head->right;
			
			while(head->LTH == 0 ){
				head = head->left;
			}
			
			return head;
		}
	}
	
	void fastOrder(Node *head){
		
		while((head = nextInOrder(head)) != root ){
			cout<<head->info<<" ";
		}
		
		return;
	}
	
	Node* returnSuccessor(Node *head){
		// Will Send The Right Of The Node For Which 
		// We Are Finding The Successor
		
		while(head->LTH != 1){
			head = head->left;
		}
		
		return head;
		
		
	}
	
	Node* returnPredecessor(Node *head){
		// Will Send The Left Of The Node For Which
		// We Are Finding The Predecessor
		
		while(head->RTH != 1){
			head = head->right;
		}
		
		return head;
	}
	
	void deletion(Node *head){
		if(root->left == root){
			
			cout<<"Nothing In The Tree To Delete "<<endl<<endl;
			
			return;
		}
		else if(number < head->info && head->LTH != 1){
			
			// Not loosing the track of the parent
			
			parent = head;
			
			deletion(head->left);
			
		}
		else if(number > head->info && head->RTH != 1 && head != root){ // Sometime when i give it greater value it starts infinite loop 
																		// from root to root left and so on continuously
			
			parent = head;
			
			deletion(head->right);
			
		}
		else if(number == head->info){
			
			if(head->RTH == 1 && head->LTH == 1){
				
				if(head->right == parent ){ //Came From Right
					
					temp = head;
					
					head->right->LTH = 1;
					head->right->left = head->left;
					
					delete head;
				}
				else{		// Came From Left
					
					temp = head;
					
					parent->RTH = 1;
					parent->right = head->right;
					
					delete head;
					
				}
				
			}
			else if(head->LTH == 1){
				
				if(head->left == parent && parent != root){ // in heads left their is parent
											// means came from left
					
					temp3 = returnSuccessor(head->right);
					
					temp3->left = head->left;
					
					head->left->right = head->right;
					
					delete head;
				}
				else if(head->left == parent && parent == root){
					temp3 = returnSuccessor(head->right);
					
					temp3->left = head->left;
					
					head->left->left = head->right;
					
					delete head;
				}
				else if(head->right->LTH != 1){  //zig zag zag case
					temp3 = returnSuccessor(head->left);
					
					temp3->left = head->left;
					parent->left = head->right;
					
					delete head;
				}
				else{					// parent not present in heads left
					
					head->right->left = head->left;
					parent->left = head->right;
					
					delete head;
					
				}
			
			}
			else if(head->RTH == 1){
				if(head->right == parent && parent != root){	// parent is present in
											// heads right 
											// means that it came from right
					
					temp3 = returnPredecessor(head->left);
					
					temp3->right = head->right;
					head->right->left = head->left;
					
					delete head;
					
				}
				else if(head->right == parent && parent == root){  // zag zag zag case
					
					temp3 = returnPredecessor(head->left);
					temp3->right = head->right;
					parent->left = head->left;
					
					delete head;

					
				}
				else if(head->left->RTH != 1){// doing zag zig zig case
					temp3 = returnPredecessor(head->left);
					
					temp3->right = head->right;
					parent->right = head->left;
					
					delete head;
				}
				else{						// parent is not present in heads right
											// that means successor is pointing somewhere else
					
					head->left->right = head->right;
					parent->right = head->left;
					delete head;
					
				}
			}
			else{							// Double Child Case
				
				temp3 = returnSuccessor(head->right);
				head->info = temp3->info;
				
				parent = head;
				number = temp3->info;
				deletion(head->right);
			}
		}
		else{
			cout<<"Number Not Found It Is Not In The Tree"<<endl<<endl<<endl;
		}
	}



	int search(Node *head){
		
		int Found = 0;
		
		while((head = nextInOrder(head)) != root ){
			if(head->info == number){
				cout<<"Number "<<head->info<<" Found In The Tree"<<endl<<endl;
				
				Found = 1;
				
				break;
			}
			
		}
		
		if(Found == 0){
			cout<<"Number Not Fount It Is Not In The Tree"<<endl<<endl;
		}
		
		return Found;
	}
	
	void findMax(Node *head){
		
		if(root->left == root){
			cout<<"Nothing In The Tree"<<endl<<endl;
			
			return;
		}
		
		head = head->left;
		
		while(head->RTH == 0){
			head = head->right;
		}
		
		cout<<"The Max Number In The Tree Is : "<<head->info<<endl<<endl;
		
	}
	
	void findMin(Node *head){
		
		if(root->left == root){
			cout<<"Nothing In The Tree"<<endl<<endl;
			
			return;
		}
		
		head = head->left;
		
		while(head->LTH == 0){
			head = head->left;
		}
		
		cout<<"The Min Number In The Tree Is : "<<head->info<<endl<<endl;
		
	}
	
	
};


int main(){
	tree T;
	
	int option;
	
	do{
		cout<<"1. Insertion"<<endl;
		cout<<"2. Fast Order , In Order Triversal"<<endl;
		cout<<"3. Deletion"<<endl;
		cout<<"4. Search A Value"<<endl;
		cout<<"5. Find Max"<<endl;
		cout<<"6. Find Min"<<endl;
		cout<<"7. Update A Value"<<endl;
		cout<<"8. Exit"<<endl<<endl;
		
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			cout<<"Enter The Number To Add : ";
			cin>>T.number;
			T.insertion(T.root);
		}
		else if(option == 2){
			T.fastOrder(T.root);
			cout<<endl<<endl;
		}
		else if(option == 3){
			cout<<"Enter The Number That You Want To Delete : ";
			cin>>T.number;
			

			T.deletion(T.root);
			T.parent = NULL;

		}
		else if(option == 4){
			cout<<"Enter A Number That You Want To Find In The Tree : ";
			cin>>T.number;
			
			T.search(T.root);
		}
		else if(option == 5){
			T.findMax(T.root);
		}
		else if(option == 6){
			T.findMin(T.root);
		}
		else if(option == 7){
			
			int num1;
			
			cout<<"Enter The Number That You Want To Update : ";
			cin>>num1;
			
			T.number = num1;
			
			int check = T.search(T.root);
			
			
			if(check){
				
				int num2;
				
				cout<<"Enter The Number That You Want To Replace With The Actual Number : ";
				cin>>num2;
				
				T.number = num2;
				
				int check2 = T.search(T.root);
				
				if(!check2){
					
					T.number = num1;
					
					T.deletion(T.root);
					T.parent = NULL;
					
					T.number = num2;
					
					T.insertion(T.root);
					
					cout<<"\nUpdatation Successfully Completed"<<endl<<endl;
				}
				else{
					cout<<"Cannot Add A Duplicate.\nAs the Number You Entered Is Already In The Tree"<<endl<<endl;
				}
				
				
				
				
			}
			
			
		}
		else if(option == 8){
			break;
		}
		else{
			cout<<"Wrong Option "<<endl<<endl;
		}
		
	}
	while(option != 8);
	
	
}