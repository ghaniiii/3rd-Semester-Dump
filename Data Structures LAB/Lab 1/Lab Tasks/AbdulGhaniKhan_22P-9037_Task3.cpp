#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
	int weeks = 4;
	int days = 7;
	
	int Temperature[weeks][days];
	
	int *pointer = &Temperature[0][0];
	
	for(int i=0;i<weeks;i++){
		for(int j=0;j<days;j++){
			*pointer = rand() % 20 + 10;
			pointer++;
		}
	}
	
	pointer = &Temperature[0][0];
	
	cout<<"Temperature Of Each Week :-"<<endl<<endl;
	
	for(int i=0;i<weeks;i++){
		
		cout<<"Week "<<i+1<<" : ";
		
		for(int j=0;j<days;j++){
			cout<<*pointer<<" ";
			pointer++;
		}
		cout<<endl;
	}
	
	pointer = &Temperature[0][0];
	
	int max = 0;
	
	int day = 0;
	
    cout<<endl<<endl<<endl;

	for(int i=0;i<weeks;i++){
		
		max = *pointer;
		day = 0;
		string name;
		
		for(int j=0;j<days;j++){
			
			if(max <= *pointer){
				max = *pointer;
				day = j+1;
			}
			
			if(day == 1){
				name = "Monday";
			}
			else if(day == 2){
				name = "Tuesday";
			}
			else if(day == 3){
				name = "Wednesday";
			}
			else if(day == 4){
				name = "Thursday";
			}
			else if(day == 5){
				name = "Friday";
			}
			else if(day == 6){
				name = "Saturday";
			}
			else if(day == 7){
				name = "Sunday";
			}
			
			
			pointer++;
		}
		
		cout<<"Hottest Day Of Week "<<i+1<<" "<<name<<"  Having A Temperature : "<<max<<endl;
	}

//	
//	for(int i=0;i<weeks*days;i++){
//		
//			if(i+1 <= 7){
//				if(max1 <= *pointer){
//					max1 = *pointer;
//					day1 = i+1;
//				}
//			}
//			else if(i+1 <= 14){
//				if(max2 <= *pointer){
//					max2 = *pointer;
//					day2 = i+1;
//				}
//				
//			}
//			else if(i+1 <= 21){
//				if(max3 <= *pointer){
//					max3 = *pointer;
//					day3 = i+1;
//				}
//			}
//			else if(i+1 <= 28){
//				if(max4 <= *pointer){
//					max4 = *pointer;
//					day4 = i+1;
//				}
//			}
//			
//			pointer++;
//		
//	}
//	
//	
//	
//	for(int i=0;i<4;i++){
//		cout<<"Hottest Day Of Week : "<<i+1<<" is : ";
//		
//		if(day1 == 1){
//			cout<<"Monday ";
//		}
//		else if(day1 == 2){
//			cout<<"Tuesday ";
//		}
//		else if(day1 == 3){
//			cout<<"Wednesday ";
//		}
//		else if(day1 == 4){
//			cout<<"Thursday ";
//		}
//		else if(day1 == 5){
//			cout<<"Friday ";
//		}
//		else if(day1 == 6){
//			cout<<"Saturday ";
//		}
//		else if(day1 == 7){
//			cout<<"Sunday ";
//		}
//	}
//	
    
	
}