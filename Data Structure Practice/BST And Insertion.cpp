#include<iostream>
#include<string.h>

using namespace std;

struct Node{

	int info;
	Node *left;
	Node *right;
	int counter;
	
	Node(){
		left = NULL;
		right = NULL;
		counter = 0;
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
		
		
	void insert(int key ,  Node* temp ){
		
		if(temp == NULL){
			temp = new Node;
			temp->info = key;
			
			head = temp;
			
			return;
		}
		
		if(temp->left == NULL && key < temp->info){
			temp->left = new Node;
			temp->left->info = key;
			
			return;
		}
		
		if(temp->right == NULL && key > temp->info){
			temp->right = new Node;
			temp->right->info = key;
			
			return;
		}
			
		if(key < temp->info && temp->left != NULL){
			insert(key , temp->left);
		}
		
		if(key > temp->info && temp->right != NULL){
			insert(key , temp->right);
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
		
		cout<<" "<<head->info<<" "<<"With Duplicate Adding Attempt  Of : "<<head->counter<<" "<<endl;
		
		if(head->left != NULL){
			pre_orderSearch(head->left);
		}
		
		
		if(head->right != NULL){
			pre_orderSearch(head->right);
		}
		
	}
	
	
	
	void in_orderSearch(Node* head){
		
		if(head == NULL){
			return ;
		}
		
		if(head->left != NULL){
			in_orderSearch(head->left);
		}
		
		cout<<" "<<head->info<<" "<<"With Duplicate Adding Attempt  Of : "<<head->counter<<" "<<endl;
		
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
		
		cout<<" "<<head->info<<" "<<"With Duplicate Adding Attempt  Of : "<<head->counter<<" "<<endl;
		
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


int main(){
	
	Tree T;
	int option;
	int number;
	
	do{
		
		cout<<"1. Enter The Value in The Tree "<<endl;
		cout<<"2. Traverse The Tree In The Pre Order "<<endl;
		cout<<"3. Traverse The Tree In In Order "<<endl;
		cout<<"4. Traverse The Tree In Post Order "<<endl;
		cout<<"5. Delete A Number From The Tree"<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			
			cout<<"Enter The Number That You Want To Insert : ";
			cin>>number;
			
			T.insert(number , T.head);
		}
		else if(option == 2){
			
			T.pre_orderSearch(T.head);
			
		}
		else if(option == 3){
			T.in_orderSearch(T.head);
		}
		else if(option == 4){
			T.post_orderSearch(T.head);
		}
		else if(option == 5){
			
			cout<<"Enter The Number That You Want To Delete : ";
			cin>>number;
		
			T.deletion(number , T.head);
		}
		else if(option == 6){
			break;
		}
		
		cout<<endl<<endl;
		
	}
	while(option != 6);
	
	
	
}