#include <iostream>
#include <vector>
using namespace std;

class Patient {
public:
    string name;
    int urgency;

    Patient(string name, int urgency) {
        this->name=name;
        this->urgency=urgency;
    }
};

class Heap {
public:
    vector<Patient> htree;

    int getParent(int child) {
       if(child == 0){
       	cout<<"It is The Root"<<endl<<endl;
       	
       	return -1;
	   }
	   
	   return (child-1)/2;
	   
    }

    int getLeft(int parent) {
        if((parent*2)+1 < htree.size()){
        	return (parent*2)+1;
		}
		else{
			return -1;
		}
    }

    int getRight(int parent) {
        if((parent*2)+2 < htree.size()){
        	return (parent*2)+2;
		}
		else{
			return -1;
		}
    }

    void swap(Patient *a, Patient *b) {
        Patient temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node) {
        
        int parentNode = getParent(node);
        
        if(parentNode == -1){
        	return;
		}
        
        if(htree[parentNode].urgency < htree[node].urgency){
        	Patient temp = htree[parentNode];
        	htree[parentNode] = htree[node];
        	htree[node] = temp;
        	
        	heapifyUp(parentNode);
		}
		else{
			heapifyUp(parentNode);
		}
		   
    }

   
	void heapifyDown(int node) {
		
		
        int leftC,rightC,minC;
        do{
            leftC=2*node+1;
            rightC=2*node+2;
            minC=node;
            
            if(leftC<htree.size()&&htree[leftC].urgency>htree[minC].urgency)
                minC=leftC;
                
            if (rightC<htree.size()&&htree[rightC].urgency>htree[minC].urgency)
                minC=rightC;

            if (minC!=node){
            	swap(&htree[node], &htree[minC]);
                node=minC;
			}
			else
                break;
        }while(1);    	
	
		
	}


    void insert(Patient patient) {
    	
        htree.push_back(patient);
    	heapifyUp(htree.size()-1);
    	
	}

    void del() {
        if(htree.size() == 0){
        	cout<<"Nothing To Delete"<<endl<<endl;
        	return;
		}
        
        swap(&htree[0] , &htree[htree.size()-1]);
		
		cout<<"Deleting "<<htree[htree.size()-1].name<<" Which Has Urgency "<<htree[htree.size()-1].urgency<<endl;
		htree.pop_back();
		
		heapifyDown(0);
    }

    void updateUrgency(string patientName, int newUrgency) {
       int notFound = 0;
    	
       for(int i=0;i<htree.size();i++){
       	
			if(htree[i].name == patientName){
       			
       			cout<<"Patient Found And Urgency Level Update "<<endl;
       		
       			htree[i].urgency = newUrgency;
       			
       			heapifyUp(i);
       			heapifyDown(i);
       			
       			break;
		   }
		   else{
		   		notFound++;
		   }
		   
	   }
	   
	   if(notFound == htree.size() ){
	   	cout<<"Patient Not Found"<<endl;
	   }
    }

    void display() {
        if (htree.empty()) {
            cout << "No appointments to display." << endl;
            return;
        }
        cout << "Current Appointments:" << endl;
        for (int i = 0; i < htree.size(); i++) {
            cout << "Name: " << htree[i].name << ", Urgency: " << htree[i].urgency << endl;
        }
    }
};

int main() {
    Heap priorityQueue;

    // Schedule appointments
    Patient p1 ("Ali", 3);
    Patient p2 ("Bilal", 1);
    Patient p3 ("Alina", 2);
    Patient p4 ("Hashir", 4);
//    void insert(Patient patient) {
//    	
//        htree.push_back(patient);
//    	heapifyUp(htree.size()-1);
//    	
//	}
    priorityQueue.insert(p1);
    priorityQueue.insert(p2);
    priorityQueue.insert(p3);
    priorityQueue.insert(p4);

    // Display appointments
    priorityQueue.display();

    // Send next patient to the doctor
    cout << "Sending next patient to the doctor:" << endl;
    priorityQueue.del();
    priorityQueue.display();

    // Update urgency level
    priorityQueue.updateUrgency("Ali", 0);
    priorityQueue.display();
	priorityQueue.del();

    return 0;
}
