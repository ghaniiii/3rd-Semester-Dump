// Can Be A Possible Replacement For Heap , This One Will Not Contain Heapify Up And Down , Tho It Works Like A Heap Implemented Through Array

#include<iostream>
#include<string.h>

using namespace std;

int array[10];


int size = 0;

void insertSort(){
	
	int number;
	
	cout<<"Enter The Number To Insert : ";
	cin>>number;
	
	if(size == 10){
		cout<<"Array FULL"<<endl;
		return;
	}
	
	if(size == 0){
		array[0] = number;
		size++;
		return;
	}
	
	for(int i=0;i<size;i++){
		if(number < array[i] && array[i] != -1){
			for(int j=size;j>=i;j--){
				array[j] = array[j-1];
			}
			
			array[i] = number;
			size++;
			
			return;
		}

	}
	
	array[size] = number;
	size++;
	
}

void delete1(){
	
	int todelete;
	
	if(size == 0){
		cout<<"Nothing To Delete "<<endl<<endl;
		return;
	}
	
	cout<<"Deleting "<<array[0]<<endl;
	
	for(int i=0;i<size-1;i++){
		
		array[i] = array[i + 1];
		
	}
	
	array[size-1] = -1;
	size--; 
}


void print(){
	for(int i=0;i<10;i++){
		cout<<array[i]<<" ";
	}
	
	cout<<endl;
}


int main(){
	
	for(int i=0;i<10;i++){
		array[i] = -1;
	}
	
	int option;
	
	while(1){
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete"<<endl;
		cout<<"3. Print"<<endl;
		cout<<"4. Exit"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			insertSort();
		}
		else if(option == 2){
			delete1();
		}
		else if(option == 3){
			print();
		}
		else if(option == 4){
			break;
		}
		else{
			cout<<"Wrong Option "<<endl;
		}
	}
	
	
	//AGK ALGO
}
