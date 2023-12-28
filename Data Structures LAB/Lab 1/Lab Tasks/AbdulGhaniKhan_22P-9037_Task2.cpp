#include<iostream>

using namespace std;

void palindromeCheck(string input){
	
	char *pointerFirst = &input[0];
	char *pointerLast = &input[input.length()-1];
	
	bool check = true;
	
	for(int i=0 ;i<input.length()/2 ; i++){
		if(*pointerFirst != *pointerLast){
			check = false;
		}
		
		pointerFirst++;
		pointerLast--;
	}
	
    if(check == true){
    	cout<<input<<" is A Palandrome"<<endl;
	}
	else{
		cout<<input<<" is Not A Palandrome"<<endl;
	}
	
}

void frequencyCheck(string input){
	char alphabet;
	char *ptr = &input[0];
	
	cout<<"Which Letter Do You Want To Check : ";
	cin>>alphabet;
	
	char *letter = &alphabet;
	int counter = 0;
	
	for(int i=0;i<input.length();i++){
		if(*letter == *ptr){
			counter++;
		}
		ptr++;
	}
	
	cout<<"The Frequency Of The Alphabet Is : "<<counter<<endl;
}

int main(){
	
	
	string input;
	
		cout<<"Enter the String : ";
		fflush(stdin);
		getline(cin , input);
	

	int option;
	
	
	do{
		
		cout<<"1. To Find If The String Is Palindrome"<<endl;
		cout<<"2. To Find the Frequency Of A Certain Character "<<endl;
		cout<<"3. To Exit"<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		
		if(option == 1){
			palindromeCheck(input);
			cout<<endl<<endl<<endl;
		}
		else if(option == 2){
			frequencyCheck(input);
			cout<<endl<<endl<<endl;
		}
		else{
			break;
			
			
		
		}
	}while(option != 3);
	

	
	
	
	
	
	
	
	
}