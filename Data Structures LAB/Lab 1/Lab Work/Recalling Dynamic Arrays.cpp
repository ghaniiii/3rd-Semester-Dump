#include<iostream>
#include<string.h>

using namespace std;

class DynamicArray{
	private:
		int size;
		string *ADynamicArray;
		
	public:
		DynamicArray(){
			this->size = 0;
		    ADynamicArray = new string[size];
		}
		
		void add(string Content){
			
			string *newDynamicArray = new string[size+1];
			
			for(int i=0;i<size;i++){
				newDynamicArray[i] = ADynamicArray[i];
			}
			
			size++;
			newDynamicArray[size-1] = Content;
			
			
			delete[] ADynamicArray;
			ADynamicArray = newDynamicArray;
			
			
			cout<<"Content Added Successfully "<<endl<<endl;
		}
		
		void removeItem(int indexNumber){
			for(int i=indexNumber-1;i<size-1;i++){
				ADynamicArray[i] = ADynamicArray[i+1];
			}
			
			size = size - 1;
			
			cout<<"Content Successfully Deleted"<<endl<<endl;
		}
		
		void updateItem(int indexNumber){
			
			string updatedContent;
			
			cout<<"Enter The Content That You Want To Over Write"<<endl<<endl;
			fflush(stdin);
			getline(cin , updatedContent);
			
			
			ADynamicArray[indexNumber-1] = updatedContent;
			
			cout<<"Content Has Been Successfully Updated"<<endl<<endl;
		}
		
		void displayContent(){
			for(int i=0;i<size;i++){
				cout<<i+1<<". "<<ADynamicArray[i]<<endl;
			}
			
			cout<<"Content Successfully Displayed"<<endl<<endl;
		}
		
		~DynamicArray(){
			delete ADynamicArray;
		}
};

int main(){
	DynamicArray A1;
	
	string option;
	int menuOption;
	string Content;
	int forIndexItemRemoval;
	
	do{
		cout<<"__________________MENU________________"<<endl<<endl<<endl;
		cout<<"1. Add An Item To The Dynamic Array"<<endl<<endl;
		cout<<"2. Update A Current Item In the Dynamic Array"<<endl<<endl;
		cout<<"3. Delete A Content Through Serial Number From The Dynamic Array"<<endl<<endl;
		cout<<"4. Display All the Contents In The Dynamic Array"<<endl<<endl;
		cout<<"5. Exit"<<endl<<endl<<endl;
		
		
		cout<<"Enter Your Option 1-4 : ";
		cin>>menuOption;
		
		cout<<endl<<endl;
		
		if(menuOption == 1){
			
			cout<<"Enter The Content That You Want To Add To The Dynamic String Array : ";
			
			fflush(stdin);
			getline(cin , Content);
			
			
			
			A1.add(Content);
		}
		else if(menuOption == 2){
			
			cout<<"Enter the Serial Number Data That You Want To Update : ";
			cin>>forIndexItemRemoval;
			
			
			
			A1.updateItem(forIndexItemRemoval);
		}
		else if(menuOption == 3){
			cout<<"Enter the Serial Number Data That You Want To Delete : ";
			cin>>forIndexItemRemoval;
			
			A1.removeItem(forIndexItemRemoval);
			
		}
		else if(menuOption == 4){
			cout<<"Displaying Now ....."<<endl<<endl;
			
			A1.displayContent();
		}
		
		
		
	}
	while(menuOption != 5);
	
}