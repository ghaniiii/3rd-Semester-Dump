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


void print(){
	for(int i=0;i<10;i++){
		cout<<array[i]<<" ";
	}
	
	cout<<endl;
}

void selectionSort(){
	
	int temp;
	int flag;
	int index;
	
	for(int i=0;i<10;i++){
		temp = array[i];
		flag = 0;
		
		for(int j=i+1;j<10;j++){
			if(temp < array[j]){
				array[i] = array[j];
				flag = 1;
				index = j;
			}
		}
		
		if(flag == 1){
			array[index] = temp; 
		}
		
	}
}


int main(){
	
	for(int i=0;i<10;i++){
		array[i] = -1;
	}
	
	int i = 0;
	
	while(i!=10){
		insertSort();
		print();
		
		i++;

	}
	
	selectionSort();
	print();
	
	
	
	
	
	
	return 0 ;
}