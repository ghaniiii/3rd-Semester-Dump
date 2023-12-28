#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class graph {
	int n=5; // Number of nodes in the graph
    bool matrix[5][5];// take  2D static array of fixed size for ease 
    
public:
    graph(int size) {
    	for(int i=0;i<n;i++){
    		for(int j = 0;j<n;j++){
    			matrix[i][j] = 0;
			}
		}
    }

    void addedge(int source, int destination, bool bi) {
    	// here bool bi means bidirectional or not
    	// if true so node 1 should be connected to node 2 and also the vice versa
    		if(source >= 0 && destination < n){
				
				if(bi){
					matrix[source][destination] = 1;
					matrix[destination][source] = 1;
				}
				else{
					matrix[source][destination] = 1;
				}
			
			}
			else{
				cout<<"Source Or Destination Wrong"<<endl;
			}
    }

    void removeEdge(int source, int destination, bool bi) {
       		if(source >= 0 && destination < n){
				
				if(bi){
					matrix[source][destination] = 0;
					matrix[destination][source] = 0;
				}
				else{
					matrix[source][destination] = 0;
				}
			
			}
			else{
				cout<<"Source Or Destination Wrong"<<endl;
			}
    }

    void DFS(int start) {
    	// here you can use the built-in stack from stack library.
        vector <bool> visited(n, false);
        stack <int> stk;

        stk.push(start);
        visited[start] = true;

        while(!stk.empty()){
        	
            int currentVertex = stk.top();
            stk.pop();
            cout << currentVertex << " ";

            for(int i = 0; i < n; i++){
                
				if(matrix[currentVertex][i] && !visited[i]){
					
                    stk.push(i);
                    visited[i] = true;
                
				}
            }
            
        }
    }

    void BFS(int start) {
    	// here you can use the built-in queue from the queue library
        vector <bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            
			int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            for(int i = 0; i < n; i++){
            	
                if(matrix[currentVertex][i] && !visited[i]){
                  
				    q.push(i);
                    visited[i] = true;
                
				}
				
            }
            
        }
    }

    void print() {
        for (int i = 0; i < n; ++i) {
            
			cout << i << ": ";
            
			for (int j = 0; j < n; ++j) {
                
				if (matrix[i][j]) {
                    cout << j << " ";
                }
                
            }
            
			cout << endl;
        }
    }
};

int main() {
   // simple make a graph containing 5 nodes, connect some edges yourself
   // call the print, dfs, and bfs function
   
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
   
   
    return 0;
}