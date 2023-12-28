#include<iostream>
#include<string.h>


using namespace std;

int fabonacci( int first , int second , int counter , int limit){
	if(counter != limit){
		cout<<first+second<<"  ";
		
		return fabonacci( second , first + second , counter + 1 , limit);
	}
	
}



int main(){
	
	int numbers;
	
	cout<<"How Many Fabonacci Numbers Do You Want To Print : ";
	cin>>numbers;
	
	if(numbers == 1){
		cout<<"0"<<endl;
	}
	else if(numbers == 2){
		cout<<"0  1  ";
	}
	else{
		
		cout<<"0  1  ";
		fabonacci(0, 1 , 2 , numbers);
		
	}
	
}