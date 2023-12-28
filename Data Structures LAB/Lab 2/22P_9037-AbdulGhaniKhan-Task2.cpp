#include<iostream>
#include<string.h>

using namespace std;

int main(){
	
	int size;
	
	cout<<"Enter The Size : ";
	cin>>size;
	
	char line[size][size];
	
	
	char *pointer;
	
	int number;
	
	pointer = &line[0][0];
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			
			number = rand() % 2;
			
			if(number == 0){
				*pointer = 'x';
			}
			else if(number == 1){
				*pointer = '-';
			}
			
			pointer++;
		}
	}
	
	pointer = &line[size/2][size/2];
	
	*pointer = 'o';
	
	pointer  = &line[0][0];
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<*pointer<<" ";
			
			pointer++;
		}
		cout<<endl;
	}
	
	int option;
	
	char yessno;
	
	do{
		
	
	
	pointer = &line[size/2][size/2];
	
	cout<<"Current Position o "<<endl;
	cout<<"Choose A Move You Are Standing At The Middle Of The Grid "<<endl;
	cout<<"1. Move Up "<<endl;
	cout<<"2. Move Down "<<endl;
	cout<<"3. Move Right "<<endl;
	cout<<"4. Move Left "<<endl;
	
	
	
	cin>>option;
	
	if(option == 1){
		pointer = pointer - size;
		
		
		
		
	}
	else if(option == 2){
		pointer = pointer + size;
		
		
		
	}
	else if(option == 3){
		pointer++;
		
		
	}
	else if(option == 4){
		pointer--;
		
		
	}
	else{
		cout<<"Wrong Option"<<endl<<endl;
	}
	
	if(*pointer == '-'){
			cout<<"You Are In A Safe Place"<<endl<<endl;
			
		}
		else if(*pointer == 'x'){
			cout<<"You Are Busted"<<endl<<endl;
		}
	
	pointer = &line[0][0];
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<*pointer<<" ";
			
			pointer++;
		}
		cout<<endl;
	}
	
	cout<<"Do You Want To Play Again ?? : ";
	cin>>yessno;
	
	cout<<endl<<endl<<endl;
	
	}
	while(yessno == 'y');
	
	
	return 0;
}