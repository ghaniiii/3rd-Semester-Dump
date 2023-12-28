#include<iostream>
#include<string.h>

using namespace std;

int calculateAddition(int a, int b){
 return a+b;
}

string print(){
	return "Hello World";
}

int main(){
	
	string (*Operation)();
	Operation = print;
	
	cout<<Operation()<<endl;
	
	int (*operationAddition)(int , int);
	
	operationAddition = calculateAddition;
	
	cout<<operationAddition(5,4);
	
	
	
	return 0;
}