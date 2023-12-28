#include<iostream>

using namespace std;

const int MAX_DISKS = 10; 


class Stack{
	
	    int arr[MAX_DISKS];
	    int top;
	
	public:
		
	    Stack(){
	    	
	        top = -1;
	    
		}
	
	    bool isEmpty(){
	        return (top == -1);
	    }
	
	    bool isFull(){
	    	
	        return (top == MAX_DISKS - 1);
	    
		}
	
	    void push(int val){
	    	
	        if(!isFull()){
	        	
	            arr[++top] = val;
	        
			}
			else{
				
	            cout<<"Stack Overflow!"<<endl;
	        
			}
	    }
	
	    int pop(){
	    	
	        if(!isEmpty()){
	        	
	            return arr[top--];
	        
			} 
			else{
	         
			    cout<<"Stack Underflow!"<<endl;
	            return -1;
	        
			}
	    }
	
	    int peek(){
	    	
	        if(!isEmpty()){
	        	
	            return arr[top];
	        
			} 
			else{
				
	            cout<<"Stack is empty!"<<endl;
	            return -1;
	        
			}
	    }
};


void towerOfHanoi(int num_disks){
	
    Stack src, aux, dest;
    
    
    int total_moves = (1 << num_disks) - 1; //Formula Found online of the total moves require to solve the hanoi problem

    char source = 'A', auxiliary = 'B', destination = 'C';

    for(int i = num_disks; i >= 1; i--){
    	
        src.push(i);
    
	}

    // swapping the auxilliary with the dest and desstination with the auxilliary if odd
    if(num_disks % 2 == 1){
      
	    swap(auxiliary, destination);
        
        cout<<"As its Odd Disks Consider Auzilliary As Destination And Destination As Auxilliary"<<endl<<endl;
        cout<<"If Still Confused Just Follow The Letters"<<endl;
        cout<<"A is The Source Having All The Disks At First"<<endl;
        cout<<"B Is The Auxilliary And C Is The Destination"<<endl;
    }

    cout<<endl<<"It Will Take "<<total_moves<<" Moves To Complete The Task "<<endl<<endl;



    for(int move = 1; move <= total_moves ; move++){
    	
        if(move % 3 == 1){
        	
            if(src.isEmpty() || (!aux.isEmpty() && src.peek() > aux.peek())){
            	
                cout<<"Move disk from auxiliary to source: "<<aux.peek()<<" -> "<<source<<endl;
                src.push(aux.pop());
            
			}
			else{
				
                cout<<"Move disk from source to auxiliary: "<<src.peek()<<" -> "<<auxiliary<<endl;
                aux.push(src.pop());
            
			}
        } 
		else if (move % 3 == 2){
			
            if(src.isEmpty() || (!dest.isEmpty() && src.peek() > dest.peek())){
            	
                cout<<"Move disk from destination to source: " <<dest.peek()<<" -> "<<source<<endl;
                src.push(dest.pop());
            
			} 
			else{
          
		        cout<<"Move disk from source to destination: "<<src.peek()<<" -> "<<destination<<endl;
                dest.push(src.pop());
          
		    }
        } 
		else if(move % 3 == 0){
			
            if(dest.isEmpty() || (!aux.isEmpty() && dest.peek() > aux.peek())){
            	
                cout<<"Move disk from auxiliary to destination: "<<aux.peek()<<" -> " <<destination<<endl;
                dest.push(aux.pop());
            
			} 
			else{
              
			    cout<<"Move disk from destination to auxiliary: "<<dest.peek()<<" -> "<<auxiliary<<endl;
                aux.push(dest.pop());
            
			}
        }
    }
    
    cout<<endl<<"Hence The Tower Of Hanoi Problem Solved Like This"<<endl;
}

int main(){
    int option;

    do{
      
	    int num_disks;

        cout<<"Enter the number of disks (max 10): ";
        cin>>num_disks;

        cout<<endl;

        if(num_disks > MAX_DISKS || num_disks <= 0){
        	
            cout<<"Invalid input! Number of disks should be between 1 and "<<MAX_DISKS<<"."<<endl;

        } 
		else{
			
            cout<< "Steps to solve Tower of Hanoi for "<<num_disks<<" disks:"<<endl<<endl<<endl;
            towerOfHanoi(num_disks);
        
		}

        cout<<endl<<endl;
        cout<<"Press 1 To Exit Or Any Other Number To Play Again"<<endl<<endl;

        cout<<"Enter Your Option : ";
        cin>>option;

        cout<<endl<<endl;
        
        
    } 
	while(option != 1);

    return 0;
}
