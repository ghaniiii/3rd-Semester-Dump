//Write a program to swap two numbers using pointers. The pointers must be
//passed to the function.

#include<iostream>

using namespace std;


void Swapper(int *pointerA , int *pointerB){
	
	cout<<endl;
	cout<<"Swapping The Two"<<endl<<endl;
	
	*pointerA = *pointerA + *pointerB;
	*pointerB = *pointerA - *pointerB;
	*pointerA = *pointerA - *pointerB;
	
}

int main(){
	int a, b ;
	
	int *pointerA = &a;
	
	int *pointerB = &b;

	
	cout<<"Enter the First Number : ";
	cin>>a;
	
	cout<<"Enter the Second Number : ";
	cin>>b;

	Swapper(pointerA , pointerB);
	
	cout<<"Hence The First Number Is : "<<a<<endl<<"And The Second Number Is : "<<b<<endl;
}