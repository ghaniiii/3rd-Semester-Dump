#include<iostream>
#include<string.h>

using namespace std;

struct Node{

	int info; // id
	string name;
	string title;
	string department;
	
	Node *left;
	Node *right;
	
	Node(){
		left = NULL;
		right = NULL;
	}
	
	Node(int number , string name , string title , string department){
		left = NULL;
		right = NULL;
		info = number;
		this->name = name;
		this->title = title;
		this->department = department;
	}
	
};

class tree{
	public:
		
		Node *root;
		Node *temp;
		Node *temp1;
		int number;
		int globalHeight;
		
	tree(){
		root = NULL;
		temp = NULL;
		temp1 = NULL;
		globalHeight = 0;
	}	
	
	void findHeight(Node *temp2 , int localHeight){
		
		if(temp2 == NULL){
			return;
		}
		
		if(temp2->left != NULL){
			findHeight(temp2->left , localHeight + 1);
		}
		
		if(globalHeight < localHeight){
			globalHeight = localHeight;
		}
		
		if(temp2->right != NULL){
			findHeight(temp2->right , localHeight + 1);
		}
		
	}
	
	Node* rightRotate(Node* head){
    
    	temp = NULL;
    	
		temp = head->left;
	    head->left = temp->right;
	    temp->right = head;
	    
	    return temp;
	}
	
	Node* leftRotate(Node* head){
	    
	    temp = NULL;
	    
		temp = head->right;
	    head->right = temp->left;
	    temp->left = head;
	    
		return temp;
	}
	
	Node* insertion(Node* head){
		string name;
		string title;
		string department;
		
		
	    if(head == nullptr){
	    	
	    	cout<<"Enter The Name : ";
	    	fflush(stdin);
	    	getline(cin , name);
	    	cout<<"Enter The Title : ";
	    	fflush(stdin);
	    	getline(cin , title);
	    	cout<<"Enter The Department : ";
			fflush(stdin);
			getline(cin , department); 
	    	
	        return new Node(number , name , title , department);
	    }
	
	    if(number < head->info){
	        head->left = insertion(head->left);
	    } 
		else if(number > head->info){
	        head->right = insertion(head->right);
	    }
	    else if(number == head->info){
	    	cout<<"Cannot Add Other Employee Having Same ID"<<endl<<endl;
		}

		
		int balanceFactor = findBF(head);
		
		if(balanceFactor > 1){
			
			cout<<"The Tree Has Become Imbalanced"<<endl<<endl;
			
	        if(number < head->left->info){
	        	cout<<"Performing Right Rotation At "<<head->info<<endl<<endl;
	            return rightRotate(head);
	        } 
			else{
				cout<<"Performing Double Rotation \nLeft Rotation At "<<head->left->info<<" And Right Rotation At "<<head->info<<endl<<endl;
	            head->left = leftRotate(head->left);
	            return rightRotate(head);
	        }
	    }
	    
	    if(balanceFactor < -1){
	    	
	    	cout<<"The Tree Has Become Imbalanced"<<endl<<endl;
	    	
	        if(number > head->right->info){
	        	cout<<"Performing Left Rotation At "<<head->info<<endl<<endl;
	            return leftRotate(head);
	        } 
			else{
				cout<<"Performing Double Rotation \nRight Rotation At "<<head->right->info<<"And Left Rotation At "<<head->info<<endl<<endl;
	            head->right = rightRotate(head->right);
	            return leftRotate(head);
	        }
	    }
		
		
		return head;
	}
	
	Node* findSuccessor(Node* head){
		while(head->left != NULL){
			head = head->left;
		}
		
		return head;
	}
	
	Node* deletion(Node* head){
		
		if(head == NULL && head == root){
			cout<<"Nothing To Delete in The Tree"<<endl;
			
			return NULL;
		}
		
		if(head == NULL){
			return NULL;
		}
		
		
		if(number < head->info){
			head->left = deletion(head->left);
		}
		else if(number > head->info){
			head->right = deletion(head->right);
		}
		else{
			if(head->right == NULL && head->left == NULL){
				delete head;
				head = NULL;	
			}
			else if(head->right == NULL){
				temp = head;
				head = head->left;
				delete temp;
				temp = NULL;
			}
			else if(head->left == NULL){
				temp = head;
				head = head->right;
				delete temp;
				temp = NULL;
			}
			else{
				
				temp1 = findSuccessor(head->right);
				
				head->info = temp1->info;
				
				number = temp1->info;
				
				head->right = deletion(head->right);
				
			}
			
		}
		
		if(head == NULL){	
			return head;
		}
		
		int balanceFactor = findBF(head);
		
		if(balanceFactor > 1){
			
			cout<<"The Tree Has Become Imbalanced"<<endl<<endl;
			
	        if(number < head->left->info){
	        	cout<<"Performing Right Rotation At "<<head->info<<endl<<endl;
	            return rightRotate(head);
	        } 
			else{
				
				if(head->left->right != NULL){
					cout<<"Performing Left Rotation At "<<head->left->info<<endl;
					head->left = leftRotate(head->left);
				}
				
				cout<<"Performing Right Rotation At "<<head->info<<endl<<endl;
	            
	            return rightRotate(head);
	        }
	    }
	    
	    if(balanceFactor < -1){
	    	
	    	cout<<"The Tree Has Become Imbalanced"<<endl<<endl;
	    	
	        if(number > head->right->info){
	        	cout<<"Performing Left Rotation At "<<head->info<<endl<<endl;
	            return leftRotate(head);
	        } 
			else{
				
				if(head->right->left != NULL){
					cout<<"Performing Right Rotation At "<<head->right->info<<endl;
					head->right = rightRotate(head->right);
				}
	            
	            cout<<"Performing Left Rotation At "<<head->info<<endl<<endl;
	            return leftRotate(head);
	        }
	    }
				
		return head;
	}
	
	int findBF(Node* newNode){
	
		globalHeight = 0;
		
		findHeight(newNode->left , 1);
		
		int left = globalHeight;
		
		globalHeight = 0;
		
		findHeight(newNode->right , 1);
		
		int right = globalHeight;
		
		int balanceFactor = left - right;
		
		return balanceFactor;
	}

	void in_Order(Node *head){
		if(head == NULL && head == root){
			cout<<"Nothing To Print"<<endl<<endl;
		}
		else{
			if(head->left != NULL){
				in_Order(head->left);
			}
			
			cout<<head->info<<" ";
			
			if(head->right != NULL){
				in_Order(head->right);
			}
		}
	}
	
	void pre_Order(Node *head){
		if(head == NULL && head == root){
			cout<<"Nothing To Print"<<endl<<endl;
		}
		else{
			cout<<head->info<<" ";
			
			if(head->left != NULL){
				pre_Order(head->left);
			}
			
			if(head->right != NULL){
				pre_Order(head->right);
			}
		}
	}
	
	Node* findMax(Node *head){
		if(head == NULL){
			cout<<"Nothing In The Tree"<<endl<<endl;
			return NULL;
		}
		
		while(head->right != NULL){
			head = head->right;
		}
		
		return head;
	}
	
	Node* findMin(Node *head){
		if(head == NULL){
			cout<<"Nothing In The Tree"<<endl<<endl;
			return NULL;
		}
		
		while(head->left != NULL){
			head = head->left;
		}
		
		return head;
	}
	
	void printOrganizationalChart(Node* head, int space) {
        if (head == NULL)
            return;

        // Increase distance between levels
        space += 5;

        // Process right child first
        printOrganizationalChart(head->right, space);

        // Print current employee info with proper spacing
        cout << endl;
        for (int i = 5; i < space; i++)
            cout << " ";
        cout << "| ID: " << head->info << " - " << head->name << " (" << head->title << ")";

        // Process left child
        printOrganizationalChart(head->left, space);
    }
	
	Node* search(Node* head){
    	if(head == NULL){
    		
        	return NULL;
        	
    	}
		else{
        
			if(head->info == number){
           		return head;
        	}
			else if(number < head->info){
            	return search(head->left);  
        	} 
			else{
            	return search(head->right);  
        	}
    	}
	}
	
};

int main(){
	tree T;
	int option;
	Node *temp;
	
	do{
		cout<<"1. Add An Employee"<<endl;
		cout<<"2. Remove Employee"<<endl;
		cout<<"3. Generate Organizational Chart"<<endl;
		cout<<"4. Search For An Employee"<<endl;
		cout<<"5. Modify Employee Information"<<endl;
		cout<<"6. Exit"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			cout<<"Enter The ID : ";
			cin>>T.number;
			
			cout<<endl;
			
			T.root = T.insertion(T.root);
			
		
		
		}
		else if(option == 2){
			cout<<"Enter The ID Of The Employee To Remove : ";
			cin>>T.number;
			
			cout<<endl;
			
			T.root = T.deletion(T.root);
			
			
		}
		else if(option == 3){
			
			cout<<"Organizational Chart (Tree Form) : " <<endl<<endl;
            T.printOrganizationalChart(T.root , 0);
            cout<<endl<<endl;
			
			
		}
		else if(option == 4){
			cout<<"Enter The ID Of The Employee : ";
			cin>>T.number;
			
			temp = NULL;
			
			temp = T.search(T.root);
			
			if(temp != NULL){
				
				if(temp->info == T.number){
					cout<<"ID Matched Displaying Now :-"<<endl<<endl;
					cout<<"ID : "<<temp->info<<endl;
					cout<<"Name : "<<temp->name<<endl;
					cout<<"Designation : "<<temp->title<<endl;
					cout<<"Department : "<<temp->department<<endl;
				}
				
			}
			else{
				cout<<"ID Not Found Person With This ID Is Not In The Organization"<<endl<<endl;
			}
			
		}
		else if(option == 5){
			int optionOfUpdation;
			
			cout<<"Enter The ID Of The Employee Whose Information You Want To Update : ";
			cin>>T.number;
			
			temp = NULL;
			
			temp = T.search(T.root);
			if(temp != NULL){

				if(temp->info == T.number){
					cout<<"Number Found And Ready To Update"<<endl<<endl;
					
					cout<<"1. Update Name "<<endl;
					cout<<"2. Designation "<<endl;
					cout<<"3. Department "<<endl;
					cout<<"4. Exit Current Menu "<<endl<<endl;
					
					cout<<"Enter Your Option : ";
					cin>>optionOfUpdation;
					
					if(optionOfUpdation == 1){
						cout<<"Enter The Updated Name : ";
						fflush(stdin);
						getline(cin , temp->name);
					}
					else if(optionOfUpdation == 2){
						cout<<"Enter The Updated Designation : ";
						fflush(stdin);
						getline(cin , temp->title);
					}
					else if(optionOfUpdation == 3){
						cout<<"Enter The Updated Department : ";
						fflush(stdin);
						getline(cin , temp->department);
					}
					else if(optionOfUpdation == 4){
						
					}
					else{
						cout<<"Wrong Option "<<endl<<endl;
					}
									
				}
			
			}
			else{
				cout<<"Person With This ID Not Found , He Is Not In The Organization"<<endl<<endl;
			}
			
			
				
		}
		else if(option == 6){
			break;
		}
		else{
			cout<<"Wrong Option"<<endl;
		}
		
		cout<<endl<<endl;
	}
	while(option != 6);
}