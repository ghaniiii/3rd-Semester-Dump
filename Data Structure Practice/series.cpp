#include<iostream>
#include<string.h>


using namespace std;


int power(int num , int power){
	
	int number = num;
	
	if(power == 0){
		return 1;
	}
	
	if(power  == 1 ){
		return num;
	}
	
	for(int i = 1; i < power ; i++){
		num = number * num;
	}
	
	return num;
}


int factorial(int num){
	if(num == 1){
		return  1;
	}
	
	return  num * factorial( num - 1);
}


int main(){
	
	cout<<power(2 , 3)<<endl;
	cout<<factorial(4)<<endl;
	
	float number;
	int terms;
	
	cout<<"Enter The Number : ";
	cin>>number;
	
	cout<<"Enter The Number Of Terms : ";
	cin>>terms;
	
	int count = 3;
	int fact = 2;
	float num = number;
	
	for(int i=1; i < terms ; i++){
		
		if(i % 2 != 0){
			number = number - ((float)power(num , count)/factorial(fact));
		}
		
		if(i % 2 == 0){
			number = number + ((float)power(num , count)/factorial(fact));
		}
		
		count += 2;
		fact += 2;
		
	}
	
	
	cout<<"The Answer Is "<<number<<endl;
	
	
	
	
}