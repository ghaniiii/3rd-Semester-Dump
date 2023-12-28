#include<iostream>

using namespace std;

void function(char* ptr){
	while(*ptr != '\0'){
		cout<<*ptr<<endl;
		ptr++;
	}
}

int main(){
	char word[] = "Pakistan";
	
	function(word);
}