#include<iostream>

#include<string.h>

using namespace std;

int main(){
	
	int arr[5];
	int *ptr;
	
	ptr = arr;
	
	for(int i=0;i<5;i++){
		cin>>*ptr;
		ptr++;
	}
	
	ptr = arr;
	
	for(int i=0;i<5;i++){
		cout<<*ptr<<" ";
		ptr++;
	}
	
	
}