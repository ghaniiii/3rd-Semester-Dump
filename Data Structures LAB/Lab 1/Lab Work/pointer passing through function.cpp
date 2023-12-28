#include<iostream>
using namespace std;

void func(int *ptr){
	
	*ptr = *ptr * *ptr;
	
	
	
}

int main(){
	int a = 5;
	int *ptr = &a;
	
	cout<<"Value Before Function Call : "<<*ptr<<endl;
	
	func(ptr);
	
	cout<<"Value After Function Call : "<<*ptr;
}