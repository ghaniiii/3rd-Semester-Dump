#include<iostream>
#include<string.h>

using namespace std;

struct Node{
	int info;
	Node *left;
	Node *right;
	
	Node(){
		left = NULL;
		right = NULL;
	}
};


class BST{
	public:
		Node *root;
		Node *temp1;
		int number;
		int check = 0;
		int check2 = 0;
		bool check3 = 1;
		int counter = 0;
		
		BST(){
			root = NULL;
			temp1 = NULL;
		}
		
		void checkLeaves(Node *head){
			
			if(head == NULL && head == root){
				cout<<"Nothing In The Tree"<<endl;
				return;
			}
			
			if(head->left == NULL && head->right == NULL && check2 == 0){
				check = counter;
				check2 = 1;
			}
			
			if(head->left == NULL && head->right == NULL && check2 == 1){
				if(check != counter){
					check3 = 0;
				}
			}
			
			if(head->left != NULL){
				counter++;
				checkLeaves(head->left);
			}
			
			if(head->right != NULL){
				counter++;
				checkLeaves(head->right);
			}
			
			counter--;
		}
		
		void insert(Node *temp){
			if(temp == NULL && temp == root){
				root = new Node;
				root->info = number;
			}
			else{
				if(number < temp->info && temp->left != NULL){
					insert(temp->left);
				}
				else if(number > temp->info && temp->right != NULL){
					insert(temp->right);
				}
				else{
					if(temp->left == NULL && number < temp->info){
						temp->left = new Node;
						temp->left->info = number;
					}
					else{
						temp->right = new Node;
						temp->right->info = number;
					}
				}
			}
		}
		
		
		void pre_Order_Search(Node *temp){
			if(temp == NULL && root == temp){
				cout<<"Nothing In The Tree To Print"<<endl<<endl;
			}
			else{
				cout<<temp->info<<endl;
				
				if(temp->left != NULL){
					pre_Order_Search(temp->left);
				}
				
				if(temp->right != NULL){
					pre_Order_Search(temp->right);
				}
			}
		}
		
		void in_Order_Search(Node *temp){
			if(temp == NULL && root == temp){
				cout<<"Nothing In The Tree To Print"<<endl<<endl;
			}
			else{
				if(temp->left != NULL){
					in_Order_Search(temp->left);
				}
				cout<<temp->info<<endl;
				if(temp->right != NULL){
					in_Order_Search(temp->right);
				}
			}
		}
		
		void post_Order_Search(Node *temp){
			if(temp == NULL && root == temp){
				cout<<"Nothing In The Tree To Print"<<endl<<endl;
			}
			else{
				if(temp->left != NULL){
					post_Order_Search(temp->left);
				}
				if(temp->right != NULL){
					post_Order_Search(temp->right);
				}
				cout<<temp->info<<endl;
			}
		}
		
		Node* returnSuccessor(Node* temp ){
			if(temp->left != NULL){
					return returnSuccessor(temp->left);
			}
			else{
				return temp;
			}
		}
		
		Node* deletion(Node* temp){
			if(temp == NULL){
				return temp;
			}
			else if(number < temp->info){
				temp->left = deletion(temp->left);
			}
			else if(number > temp->info){
				temp->right = deletion(temp->right);
			}
			else{
				if(temp->right == NULL && temp->left == NULL){
					delete temp;
					temp = NULL;
					return temp;
				}
				else if(temp->right == NULL){
					temp1 = temp;
					temp = temp->left;
					delete temp1;
				}
				else if(temp->left == NULL){
					temp1 = temp;
					temp = temp->right;
					delete temp1;
				}
				else{
					temp1 = returnSuccessor(temp->right);
					temp->info = temp1->info;
					number = temp->info;
					temp->right = deletion(temp->right);
				}
			}
			
			return temp;
		}
		
};


int main(){
	BST T;
	int option;
	
	
	
	do{
		
		cout<<"1. Enter Values "<<endl;
		cout<<"2. Display Pre Order "<<endl;
		cout<<"3. Display In Order "<<endl;
		cout<<"4. Display Post Order "<<endl;
		cout<<"5. Delete Item "<<endl;
		cout<<"6. Check Leaves If They Are On The Same Level "<<endl;
		cout<<"7. Exit"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		
		if(option == 1){
			cout<<"Enter The Number That Your Want To Insert : ";
			cin>>T.number;
			T.insert(T.root);
		}
		else if(option == 2){
			T.pre_Order_Search(T.root);
		}
		else if(option == 3){
			T.in_Order_Search(T.root);
		}
		else if(option == 4){
			T.post_Order_Search(T.root);
		}
		else if(option == 5){
			cout<<"Enter The Number That You Want To Delete : ";
			cin>>T.number;
			T.root = T.deletion(T.root);
		}
		else if(option == 6){
			if(T.root == NULL){
				cout<<"Nothing In The Tree"<<endl;
			}
			else{
				T.check = 0;
				T.check2 = 0;
				T.check3 = 1;
				T.counter = 0;
				
				T.checkLeaves(T.root);
				
				if(T.check3){
					
					cout<<"They Are On The Same Level"<<endl;
					
				}
				else{
					cout<<"They Are Not At The Same Level"<<endl;
				}
				
			}
		}
		else if(option == 7){
			break;
		}
		else{
			cout<<"Wrong Option"<<endl<<endl;
		}
	}
	while(option != 7);
	
	
}