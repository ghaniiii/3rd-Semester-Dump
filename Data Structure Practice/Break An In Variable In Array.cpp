#include<iostream>
#include<string.h>

using namespace std;

int count_Numbers(int numbers){
		
	int count = 0;
		
	while(numbers > 0){
		numbers /= 10;
		count++;
	}
	
	return count;
		
}

int main(){
	
	int number;
	
	cout<<"Enter The Number : ";
	cin>>number;
	
	int temp = number;
	
	int array[count_Numbers(number)];
	
	for(int i=count_Numbers(number) - 1 ; i >= 0 ; i--){
		array[i] = temp % 10;
		temp = temp / 10;
	}
	
	for(int i=0;i<count_Numbers(number) ; i++){
		cout<<array[i]<<"  ";
	}
	
	return 0;
}