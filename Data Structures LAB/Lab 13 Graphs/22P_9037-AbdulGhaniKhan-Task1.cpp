#include <iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

class Node {
	public:
		int val;
		Node* next;
		Node(int val) {
			this->val = val;
			next = NULL;
		}
};

class LinkedList {
	public:
		Node* head;
		Node* temp;
		LinkedList() {
			head = NULL;
			temp = NULL;
		}

		void append(int val) {
			Node* newNode = new Node(val);
			if (head == NULL) {
				head = newNode;
			} else {
				Node* curr = head;
				while (curr->next != NULL) {
					curr = curr->next;
				}
				curr->next = newNode;
			}
		}
		void remove(int val) {
			Node* curr = head;
			Node* prev = NULL;

			// If the head node itself needs to be removed
			if (curr != NULL && curr->val == val) {
				head = curr->next; // Change head
				delete curr;        // Free old head
				return;
			}

			// Search for the node to be removed, keep track of the previous node
			while (curr != NULL && curr->val != val) {
				prev = curr;
				curr = curr->next;
			}

			// If the node was not found
			if (curr == NULL) return;

			// Unlink the node from the list
			prev->next = curr->next;

			// Free memory
			delete curr;
		}
		void printList() {
			Node* curr = head;
			while (curr != NULL) {
				cout << curr->val << " ";
				curr = curr->next;
			}
		}
};

class graph {
		LinkedList* adjlist; // pointer to an array of linked list
		int n;
	public:
		graph(int size) {
			adjlist = new LinkedList[size]; // initialize the pointer to point to a dynamic aray of linked list
			n = size;
			
			for(int i=0;i<n;i++){
				adjlist[i].append(i);
			}
		}

		void addedge(int source, int destination, bool bi) {
			
			if(source >= 0 && destination < n){
				
				if(bi){
					adjlist[source].append(destination);
					adjlist[destination].append(source);
				}
				else{
					adjlist[source].append(destination);
				}
			
			}
			else{
				cout<<"Source Or Destination Wrong"<<endl;
			}
			
		}

		void removeEdge(int source, int destination, bool bi) {
			if(source >= 0 && destination < n){
				if(bi){
					adjlist[source].remove(destination);
					adjlist[destination].remove(source);
				}
				else{
					adjlist[source].remove(destination);
				}
			}
			else{
				cout<<"Source Or Desination Wrong"<<endl;
			}
		}

		void DFS(int start) {
			// you can use the built-in stack and vector to use in this method
			
			vector <int> visited(n, 0); 
		    stack <int> stk;
		    stk.push(start);
		
		    while(!stk.empty()){
		    	
		        int currentNode = stk.top();
		        stk.pop();
		
		        if(visited[currentNode] == 0){
		        	
		            cout<<currentNode<<" ";
		            visited[currentNode] = 1;
		            
		        }
		
		        Node* temp = adjlist[currentNode].head->next;
		        
		        while(temp != nullptr){
		        	
		            if(visited[temp->val] == 0){
		            	
		                stk.push(temp->val);
		            
					}
		            temp = temp->next;
		        }
		        
		    }

			
			
		}
		void BFS(int start) {
			// you can use the built-in queue and vector to use in this method
			
			vector <bool> visited(n, false); 
	        queue <int> q;
	        
	        visited[start] = true;
	        q.push(start);
	
	        while(!q.empty()){
	        	
	            int currentVertex = q.front();
	            cout << currentVertex << " ";
	            q.pop();
	
	            Node* temp = adjlist[currentVertex].head->next; 
	            
				while(temp != nullptr){
	            	
	                if(!visited[temp->val]){
	                	
	                    visited[temp->val] = true;
	                    q.push(temp->val);
	                
					}
					
	                temp = temp->next;
	            }
	        }
		}

		void print() {
			// print the adjacency list
			
			for (int i = 0; i < n; ++i){
				
		        cout<<"Vertex -> "<<adjlist[i].head->val<<" : ";
		        
		        Node* temp = adjlist[i].head->next;
		        
		        while (temp != NULL){
		        	
		            cout<<temp->val<<" ";
		            
		            temp = temp->next;
		            
		        }
		        
		        cout<<endl;
		    }
		    
		    
		}
};

int main() {
	graph g(5);
	g.addedge(0, 1, true);
	g.addedge(3, 1, true);
	g.addedge(0, 2, true);
	g.addedge(3, 2, true);
	g.addedge(0, 3, true);

	cout << "Graph before removing edges:" << endl;
	g.print();
	
	cout << "Graph after removing edges:" << endl;
	g.removeEdge(3, 1, true);
	g.print();
		
	g.DFS(1);
	cout<<"\nBFS: \n";
	g.BFS(1);


}