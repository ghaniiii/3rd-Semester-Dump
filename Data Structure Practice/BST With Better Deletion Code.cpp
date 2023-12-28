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
			
				return returnSuccessor(temp->left);
			
		}
		else{
			return temp;
		}
		
	}
	
	Node* deletion(int key , Node* head){

	
		if(head == NULL){
			return head;
		}
		else if(key < head->info){
			
			head->left = deletion( key , head->left);
				
		}
		else if(key > head->info){
			
			head->right = deletion(key , head->right);
			
		}
		else{
			if(head->right == NULL && head->left == NULL){
				delete head;
				head = NULL;
			}
			else if(head->right == NULL){
				temp = head;
				
				head = temp->left;
				
				delete temp;
			}
			else if(head->left == NULL){
				
				temp = head;			
				head = temp->right;
				delete temp;
				
			}
			else{
				
				temp1 = returnSuccessor(head->right);
				head->info = temp1->info;
				head->right = deletion(temp1->info , head->right);
				
			}
		}
		
		return head;
		
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
		
			T.head = T.deletion(number , T.head);
		}
		else if(option == 6){
			break;
		}
		
		cout<<endl<<endl;
		
	}
	while(option != 6);
	
	
	
}