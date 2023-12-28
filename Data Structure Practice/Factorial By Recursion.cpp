#include<iostream>
#include<string.h>

using namespace std;

int factorial(int number){
	
	if(number == 0){
		return 1;
	}
	
		
		return number*factorial(number-1);
			
}


int main(){
	
	int number;
	
	cout<<"Enter The Number That You Want TO Find the Factorial Of Which : ";
	cin>>number;
	
	cout<<"Factorial Of The NUmber "<<factorial(number);
	
}