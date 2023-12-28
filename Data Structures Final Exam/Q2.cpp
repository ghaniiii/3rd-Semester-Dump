#include <iostream>
#include <vector>
using namespace std;

class Employee{
	public:
		int employeeID;
		string name;
		float sales;
		float customerSatisfaction;
		float projectCompletion;
		float performanceScore;

		Employee(int employeeID, string name, float customerSatisfaction, float projectCompletion , float sales) {
			this->employeeID=employeeID;
			this->name=name;
			this->customerSatisfaction=customerSatisfaction;
			this->projectCompletion=projectCompletion;
			this->sales = sales;
		}

		void calculatePerformanceScore() {
			performanceScore = sales+customerSatisfaction+projectCompletion; 
		}
};

class MaxHeap {
	public:
		vector<Employee> htree;

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

		void swap(Employee* a, Employee* b) {
			Employee temp = *a;
			*a = *b;
			*b = temp;
		}

		void heapifyUp(int node) {
			int parentNode = getParent(node);
        
	        if(parentNode == -1){
	        	return;
			}
	        
	        if(htree[parentNode].performanceScore < htree[node].performanceScore){
	        	Employee temp = htree[parentNode];
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
	            
	            if(leftC<htree.size()&&htree[leftC].performanceScore>htree[minC].performanceScore)
	                minC=leftC;
	                
	            if (rightC<htree.size()&&htree[rightC].performanceScore>htree[minC].performanceScore)
	                minC=rightC;
	
	            if (minC!=node){
	            	swap(&htree[node], &htree[minC]);
	                node=minC;
				}
				else
	                break;
	        }while(1);
		}

		void insertEmployee(Employee emp) {
			emp.calculatePerformanceScore();
			htree.push_back(emp);
    		heapifyUp(htree.size()-1);
		}

		void getTopRankingEmployee() {
			 if(htree.size() == 0){
	        	cout<<"Nothing To Delete"<<endl<<endl;
	        	return;
			}
	        
	        swap(&htree[0] , &htree[htree.size()-1]);
			
			cout<<"Deleting "<<htree[htree.size()-1].name<<" Which Had Performance Score "<<htree[htree.size()-1].performanceScore<<endl;
			htree.pop_back();
			
			heapifyDown(0);
		}

		void updatePerformance(int employeeID, float newSales, float newCS, float newPCE) {
			int notFound = 0;
    	
	       for(int i=0;i<htree.size();i++){
	       	
				if(htree[i].employeeID == employeeID){
	       			
	       			cout<<"Employee Found And Updated "<<endl;
	       			htree[i].sales = newSales;
	       			htree[i].customerSatisfaction = newCS;
	       			htree[i].projectCompletion = newPCE;
	       			
	       			htree[i].calculatePerformanceScore();
	       			
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
		

		void displayEmployees() {
			if (htree.empty()) {
				cout << "No Employees." << endl;
				return;
			}
			cout << "Employee Rankings:" << endl;
			for (const Employee& emp : htree) {
				cout << "Employee ID: " << emp.employeeID << ", Name: " << emp.name << ", Performance Score: " << emp.performanceScore << endl;
			}
		}

};

int main() {
	MaxHeap employeeMaxHeap;

	while (true) {
		cout << "\nMenu:\n";
		cout << "1. Enter a new employee details\n";
		cout << "2. Get the top-ranking employee\n";
		cout << "3. Update an employee's scores\n";
		cout << "4. Display employee rankings\n";
		cout << "5. Exit\n";

		int choice;
		cin >> choice;

		switch (choice) {
			case 1: {
				int id;
				string name;
				float sales, cs, pce;
				cout << "Enter Employee ID: ";
				cin >> id;
				cin.ignore(); // Clear newline character from the buffer
				cout << "Enter Employee Name: ";
				getline(cin, name);
				cout << "Enter Sales (in percentage): ";
				cin >> sales;
				cout << "Enter Customer Satisfaction (in percentage): ";
				cin >> cs;
				cout << "Enter Project Completion Efficiency (in percentage): ";
				cin >> pce;
				
				

				Employee newEmployee(id, name, cs, pce, sales);
				newEmployee.calculatePerformanceScore();
				employeeMaxHeap.insertEmployee(newEmployee);
				cout << "Employee added successfully!" << endl;
				break;
			}
			case 2: {
				employeeMaxHeap.getTopRankingEmployee();
				break;
			}
			case 3: {
				int empID;
				float newSales, newCS, newPCE;
				cout << "Enter Employee ID to update scores: ";
				cin >> empID;
				cout << "Enter new Sales (in percentage): ";
				cin >> newSales;
				cout << "Enter new Customer Satisfaction (in percentage): ";
				cin >> newCS;
				cout << "Enter new Project Completion Efficiency (in percentage): ";
				cin >> newPCE;
				employeeMaxHeap.updatePerformance(empID, newSales, newCS, newPCE);
				break;
			}
			case 4: {
				employeeMaxHeap.displayEmployees();
				break;
			}
			case 5:
				cout << "Exiting the program." << endl;
				return 0;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
	}

	return 0;
}
