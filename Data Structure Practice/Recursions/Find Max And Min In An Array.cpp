#include<iostream>
#include<string.h>

using namespace std;

int findMax(int *array , int size ,int index , int &max , int &min){
	
	if(index <= size - 1 ){
		
		if(max <= array[index]){
			
			max = array[index];
		
		}
		
		if(min >= array[index]){
			
			min = array[index];
			
		}
		
		return findMax(array , size , index + 1 , max , min);
	}	
	else{
		return max;
	}
	
}



int main(){
	
	int size = 5;
	
	int array[size];

	cout<<"Enter The Values In The Array :- "<<endl;
	
	for(int i=0;i<size;i++){
		cout<<"Enter The Value In Index "<<i+1<<" : ";
		cin>>array[i];
		
	}
	
	int max = array[0];
	int min = array[0];
	
	findMax( array , size , 0 , max , min);
	
	
	cout<<"Maximum Number Is : "<<max<<endl;
	cout<<"Minimum Number Is : "<<min<<endl;
	
}