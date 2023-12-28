#include<iostream>
#include<string.h>

using namespace std;

int main(){
	
	int weeks = 4;
	int days = 7;
	
	int TDarray[weeks][days];
	
	int *ptr = &TDarray[0][0];
	
	for(int i=0;i<weeks;i++){
		for(int j=0;j<days;j++){
			*ptr = rand() % 20 + 10;
			ptr++;
		}
	}
	
	ptr = &TDarray[0][0];
	
	for(int i=0;i<weeks;i++){
		
		cout<<"Week # "<<i+1<<" :";
		
		for(int j=0;j<days;j++){
			cout<<*ptr<<" ";
			ptr++;
		}
		
		cout<<endl<<endl;
	}
	
	ptr = &TDarray[0][0];
	
	for(int i=0 ; i<weeks;i++){
		
		int max = *ptr ;
		string dayname;
		int daycount = 0;
		
		for(int j=0;j<days;j++){
			if(max <= *ptr){
				max = *ptr;
				daycount = j+1;
			}
			
			ptr++;
			
		}
		
		if(daycount == 1){
			dayname = "Monday ";
		}
		else if(daycount == 2){
			dayname = "Tuesday ";
		}
		else if(daycount == 3){
			dayname = "Wednesday ";
		}
		else if(daycount == 4){
			dayname = "Thursday ";
		}
		else if(daycount == 5){
			dayname = "Friday ";
		}
		else if(daycount == 6){
			dayname = "Saturday ";
		}
		else if(daycount == 7){
			dayname = "Sunday ";
		}
		
		cout<<"Hottest Day Of The Week # "<<i+1<<" is "<<dayname<<" Having Temperature Of : "<<max<<endl<<endl;
		
		
	}
	
	
	
	return 0;
}