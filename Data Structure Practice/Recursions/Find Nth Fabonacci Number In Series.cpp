#include<iostream>
#include<string.h>

using namespace std;


int fabonacci(int first , int second , int counter , int limit){
	
	if(counter < limit){
		return fabonacci(second , first + second , counter + 1 , limit);
	}
	else{
		return second;
	}
	
}


int main(){
	
	int number;
	
	cout<<"Find The Nth Number Of A Fabonacci series : ";
	cin>>number;
	
	
	if(number == 1){
		cout<<" 0 ";
	}
	else if(number  == 2){
		cout<<"1";
	}
	else{
		cout<<fabonacci(0 , 1 , 2 , number);
	}
}



