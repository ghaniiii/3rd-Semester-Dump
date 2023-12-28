//Write a program in which take a string input from the user, ask the user the
//character to find in the string, the ask the user to replace that character with
//which character. Update all the occurrences of that character with the new
//character and display the updated string. After that, capitalize the updated
//string.

#include<iostream>
#include<string.h>

using namespace std;

int main(){
	
	string line;
	char searchWord;
	char word;
	
	cout<<"Enter the String : ";
	fflush(stdin);
	getline(cin , line);
	
	cout<<"Enter the Character That You Want Get Replaced : ";
	cin>>searchWord;
	
	cout<<"Enter The Character That You Want To Replace With : ";
	cin>>word;
	
	int lengthOfLine = line.length();
	
	char *pointer;
	
	pointer = &line[0];
	
	while(*pointer != '\0'){
		if(*pointer == searchWord){
			*pointer = word;
		}
		pointer++;
	}
	
	
	cout<<"The Updated String Is : "<<line<<endl;
	
	cout<<"The Capitalized String Is : ";
	
	pointer = &line[0];
	
	while(*pointer != '\0'){
		*pointer = *pointer - 32;
		
		pointer++;
	}
	
	
	cout<<line<<endl;
	
	
}