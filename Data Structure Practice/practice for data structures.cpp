#include<iostream>
#include<string.h>

using namespace std;

int main(){
	
		int twoDArray[5][5];
		int option;
		
	while(1){
	
		
		for(int i=0;i<5;i++){
			
			cout<<"Enter The Binary In "<<i+1<< " One By One"<<endl<<endl;
			
			for(int j=0;j<5;j++){
				
				cin>>twoDArray[i][j];
				
			}
		}
		
		int counterFor1 = 0;
		int counterFor0 = 0;
		
		cout<<"These Rows Has More 1's Then 0's In This Specific 2D Array"<<endl<<endl;
		
		for(int i=0;i<5;i++){
			
			counterFor1 = 0;
			counterFor0 = 0;
			
			
			for(int j=0;j<5;j++){
				if(twoDArray[i][j] == 1){
					counterFor1++;
				}
				if(twoDArray[i][j] == 0){
					counterFor0++;
				}
				
				
			}
			
			if(counterFor1 > counterFor0){
				
				cout<<"Row : "<<i+1<<" : ";
				
					for(int l = 0;l<5;l++){
						cout<<twoDArray[i][l];
					}
				
				cout<<endl;
			}
			
		}
	
		cout<<endl;
			
		cout<<"Do You Want To Exit"<<endl<<endl;
		cout<<"Press 1 To Exit"<<endl<<endl;
		
		cin>>option;
		
		if(option == 1){
			break;
		}
		
		
		
		
	}
	
	
	
	
	
	
	return 0;
}