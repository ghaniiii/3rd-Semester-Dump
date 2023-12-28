#include<iostream>
#include<string.h>

using namespace std;

class Array{
	private:
		int array[10];
		int *p;
		int *maxsize;
		int sizeOfArray = 10;

		
	public:
		Array(){
			
			p = array;
			maxsize = NULL ;
		}
		
		int get(){
			return *p;
		}
		
		void update(){
			int numberToFind;
			
			p = array;
			
			while(p <= maxsize){
				cout<<*p<<endl;
				p++;
			}
			
			
			
			cout<<"Which Number Integer Do You Want To Update : ";
			cin>>numberToFind;
			
			p = array;
			
			while(p <= maxsize){
				if(*p == numberToFind)
				break;
				
				p++;
			}
			
			if(*p == numberToFind){
				cout<<"Number Found.."<<endl;
				cout<<"Enter The Number That You Want To Input At Its Place : ";
				cin>>numberToFind;
				
				*p = numberToFind;
			}
			else{
				cout<<"Number Not Found"<<endl;
			}
			
		}
		
		int length(){
			int size = 0;
			
			p = array;
			
			while(p <= maxsize){
				size++;
				p++;
			}
			
			return size;
		}
		
		void back(){
			if(array < p){
				p--;
			}
			else{
				cout<<"Its The First Index We Cant Move Back More"<<endl;
			}
		}
		
		void next(){
			if(p<maxsize){
				p++;
			}
			else{
				cout<<"Its The Last Index We Cant Move Forward"<<endl;
			}
		}
		
		void start1(){
			p = array;
			
			cout<<"Pointer Moved To The First Index"<<endl;
		}
		
		void end(){
			p = maxsize;
			
			cout<<"Pointer Moved Towards The Last Filled Index"<<endl;
		}
		
		void remove(){
			int numberToFind;
			
			cout<<"Which Number Do You Want To Remove ? : ";
			cin>>numberToFind;
			
			p = array;
			
			while(p<=maxsize){
				if(*p == numberToFind)
				break;
				
				p++;
			}
			
			if(*p == numberToFind){
				
				while(p<maxsize){
					
					*p = *(p+1);
					
					p++;
				
				}
				
				maxsize--;
				
			}
			else{
				cout<<"Number Not Found"<<endl;
			}
			
		}
		
		void add(int number){
			int numberToFind;
			p = array;
			
			if(number == 0){
				cout<<"Enter The Number To Be Stored : ";
				cin>>numberToFind;
				
				*p = numberToFind;
				maxsize = array;
				
				
			}
			else{
			
			
				cout<<"In Front Of Which Number Do You Want To Add ? : ";
				cin>>numberToFind;
				
				// Finds the number
				
				while(p<=maxsize){
					if(*p == numberToFind)
					break;
					
					p++;
				}
				
				//Instruction When Finds the number
				
				
				
				if(*p == numberToFind){
					
					maxsize++;
					p++;
					
					int *temp = p;
					p = maxsize;
					
					while(temp <= p){
						
						
						
						//makes space for the number to be added and moves the numbers forward 1 space
						
						*p = *(p-1);
						
//						*(p+1) = *p;   this one doesnt work as it over writes the next number;
						
						p--;
						
					}
					
					p = array;
					
					// pointer again searches for that number by starting from zero index
					
					while(p<=maxsize){
						if(*p == numberToFind)
							break;
						
							p++;
					}
					
					// Pointer finds the number and moves 1 forward to add the number where it left the 
					// space for the new number to add.
					
					p++;
					
					cout<<"Enter The Number That You Want To Add : ";
					cin>>numberToFind;
					
					*(p) = numberToFind;
					
					
					
				}
				else{
					cout<<"Number Not Found"<<endl;
				   
				}
			}
			
			
		}
		
		void print(){
			
			p = array;
			
			while(p <= maxsize){
				cout<<*p<<endl;
				p++;
			}
			
			p = array;
		}
};


int main(){
	int option;
	Array A;
	int number = 0;
	
	do{
	
		cout<<"Menu.."<<endl;
		cout<<"1. Add"<<endl;
		cout<<"2. Get"<<endl;
		cout<<"3. Update"<<endl;
		cout<<"4. Length"<<endl;
		cout<<"5. Back"<<endl;
		cout<<"6. Next"<<endl;
		cout<<"7. Start"<<endl;
		cout<<"8. End"<<endl;
		cout<<"9. Remove"<<endl;
		cout<<"10. Print Array"<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		cout<<endl<<endl<<endl;
		
		if(option == 1){
			A.add(number);
			number = -1;
		}
		else if(option ==2){
			cout<<"The Number Is : "<<A.get()<<endl;
		}
		else if(option ==3){
			A.update();
		}
		else if(option == 4){
			cout<<"The Numbers Stored In The Array Currently Are "<<A.length()<<" in Number"<<endl;
		}
		else if(option ==5){
			A.back();
		}
		else if(option == 6){
			A.next();
		}
		else if(option == 7){
			A.start1();
		}
		else if(option == 8){
			A.end();
		}
		else if(option == 9){
			A.remove();
		}
		else if(option == 10){
			A.print();
		}
		
		cout<<endl<<endl<<endl;
		
	}
	while(option < 11);

	
}