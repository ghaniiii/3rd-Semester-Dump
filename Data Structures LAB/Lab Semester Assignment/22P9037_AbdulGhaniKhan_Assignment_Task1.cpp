#include<iostream>
#include<string.h>

using namespace std;

struct date{
	int day;
	int month;
	int year;
	
	date(){
		day = 0;
		month = 0;
		year = 0;
	}
};

struct Node{
	int ISBN;
	string author;
	string title;
	string genre;
	date publicationDate;
	
	Node *next;
	Node *prev;	
};


class DLL{
	private:
		Node *temp;
		Node *temp1;
		Node *head;
		int size;
		
	public:
		DLL(){
			temp = NULL;
			temp1 = NULL;
			head = NULL;
			size = 0;
		}
		
		void add(){
			
			int key;
			char choice;
			
			Node *temp2 = new Node;
			
				cout<<"Enter The Info Of The Book One By One :- "<<endl<<endl;
			 	cout<<"Enter The ISBN Number : ";
			 	cin>>temp2->ISBN;
			 	cout<<"Enter The Author : ";
			 	fflush(stdin);
			 	getline(cin , temp2->author);
			 	cout<<"Enter The Title : ";
			 	fflush(stdin);
			 	getline(cin , temp2->title);
			 	cout<<"Enter The Genre : ";
			 	fflush(stdin);
			 	getline(cin , temp2->genre);
			 	
			 	cout<<endl;
			 	cout<<"Now Enter The Date Of Publication :-"<<endl<<endl;
			 	cout<<"Enter The Day : ";
			 	cin>>temp2->publicationDate.day;
			 	cout<<"Enter The Month : ";
			 	cin>>temp2->publicationDate.month;
			 	cout<<"Enter The Year : ";
			 	cin>>temp2->publicationDate.year;
			 	
			 	cout<<endl;
			
			temp = head;
			 	
			 	while(temp != NULL){
			 		if(temp->ISBN == temp2->ISBN){
			 			cout<<"Cannot Add A Book With Same ISBN"<<endl;
			 			return;
					 }
					
					if(temp->title == temp2->title){
						cout<<"Cannot Add A Book With Exaclty One Title"<<endl;
						return;
					}
					
					temp = temp->next;
					
				}
				
				if(temp2->publicationDate.year < 2024 ){
					if(temp2->publicationDate.month < 13 && temp2->publicationDate.month > 0){
						if(temp2->publicationDate.month == 1 || temp2->publicationDate.month == 3 || temp2->publicationDate.month == 5 || temp2->publicationDate.month == 7 || temp2->publicationDate.month == 8 || temp2->publicationDate.month == 10 || temp2->publicationDate.month == 12){
							if(temp2->publicationDate.day < 32 && temp2->publicationDate.day > 0){
								
							}
							else{
								cout<<"Day Is Wrong The Month You Entered Only Has 31 Days"<<endl;
								delete temp2;
								return;
							}
						
						}
						
						if(temp2->publicationDate.month == 2 || temp2->publicationDate.month == 4 || temp2->publicationDate.month == 6 || temp2->publicationDate.month == 9 || temp2->publicationDate.month == 11){
							if(temp2->publicationDate.day < 31 && temp2->publicationDate.day > 0){
								
							}
							else{
								cout<<"Day Is Wrong The Month You Entered Only Has 30 Days"<<endl;
								delete temp2;
								return;
							}
						}
					}
					else{
						cout<<"Month Must Be Less Then 13 Greater Then 0"<<endl;
						delete temp2;
						return;
					}
				}
				else{
					cout<<"Year Must Be Less Then 2024"<<endl;
					delete temp2;
					return;
				}
				
				
			
			if(head == NULL){
				cout<<"This Is The First Book Of The List "<<endl<<endl;

				head = temp2;
				
			 	head->prev = NULL;
			 	
			 	head->next = NULL;
			 	
			 	size++;
			 	
			 	return;
			}
			
			temp = head;
					
					while(temp->next != NULL){
						temp = temp->next;
					}
						
						temp->next = temp2;
						temp2->prev = temp;
						temp2->next = NULL;
						size++;
					
				rearrange();
			
		}
		
		void rearrange(){
			
			//Bubble Sort
			
			if(head == NULL){
				return;
			}
			
			Node *tempForTransfer = new Node;
			
			temp = head;
			
			Node *tempHere;
			
			tempHere = temp->next;
			int i = 1;
			
			while(i == 1){
				
				i = 0;
				temp = head;
				tempHere = temp->next;
				
				while(tempHere != NULL){
					if(tempHere->publicationDate.year < temp->publicationDate.year){
						if(tempHere->publicationDate.month < temp->publicationDate.month){
							if(tempHere->publicationDate.day < temp->publicationDate.day){
								
							}
							else{
								
								tempForTransfer->ISBN = temp->ISBN;
								tempForTransfer->author = temp->author;
								tempForTransfer->title = temp->title;
								tempForTransfer->publicationDate = temp->publicationDate;
								tempForTransfer->genre = temp->genre;
								
								temp->ISBN = tempHere->ISBN;
								temp->author = tempHere->author;
								temp->title = tempHere->title;
								temp->publicationDate = tempHere->publicationDate;
								temp->genre = tempHere->genre;
								
								tempHere->ISBN = tempForTransfer->ISBN;
								tempHere->author = tempForTransfer->author;
								tempHere->title = tempForTransfer->title;
								tempHere->publicationDate = tempForTransfer->publicationDate;
								tempHere->genre = tempForTransfer->genre;
								i = 1;
								
							}
						}
						else{
								tempForTransfer->ISBN = temp->ISBN;
								tempForTransfer->author = temp->author;
								tempForTransfer->title = temp->title;
								tempForTransfer->publicationDate = temp->publicationDate;
								tempForTransfer->genre = temp->genre;
								
								temp->ISBN = tempHere->ISBN;
								temp->author = tempHere->author;
								temp->title = tempHere->title;
								temp->publicationDate = tempHere->publicationDate;
								temp->genre = tempHere->genre;
								
								tempHere->ISBN = tempForTransfer->ISBN;
								tempHere->author = tempForTransfer->author;
								tempHere->title = tempForTransfer->title;
								tempHere->publicationDate = tempForTransfer->publicationDate;
								tempHere->genre = tempForTransfer->genre;
								i = 1;
								
						}
					}
					else{
								tempForTransfer->ISBN = temp->ISBN;
								tempForTransfer->author = temp->author;
								tempForTransfer->title = temp->title;
								tempForTransfer->publicationDate = temp->publicationDate;
								tempForTransfer->genre = temp->genre;
								
								temp->ISBN = tempHere->ISBN;
								temp->author = tempHere->author;
								temp->title = tempHere->title;
								temp->publicationDate = tempHere->publicationDate;
								temp->genre = tempHere->genre;
								
								tempHere->ISBN = tempForTransfer->ISBN;
								tempHere->author = tempForTransfer->author;
								tempHere->title = tempForTransfer->title;
								tempHere->publicationDate = tempForTransfer->publicationDate;
								tempHere->genre = tempForTransfer->genre;
								i = 1;
								
					}
					
					temp = temp->next;
					tempHere = tempHere->next;
				}
			}
			
		}
		
		void recommendRelatedBooks(){
			string name;
			temp = head;
			
			if(head == NULL){
				cout<<"No Nodes Added Yet "<<endl<<endl;
				return;
			}
			
			cout<<"Enter The Book Name : ";
			fflush(stdin);
			getline(cin , name);
			
			string name2;
			string name3;
			
			while(temp != NULL){
				if(temp->title == name){
					name2 = temp->genre;
					name3 = temp->title;
					
					break;
				}
				
				temp = temp->next;
			}
			
			temp = head;
			
			cout<<endl<<endl;
			
			int i = 1;
			
			while(temp != NULL){
				
				if(i <= 3){
					
					if(temp->genre == name2 && temp->title != name3){
						cout<<i<<". "<<temp->title<<endl;
						i++;
					}
					
				}
				
				temp = temp->next;
			}
			
			cout<<endl<<endl;
		}
		
		void displayBooksByAuthor(){
			
			
			string name;
			temp = head;
			
			if(head == NULL){
				cout<<"No Nodes Added Yet "<<endl<<endl;
				return;
			}
			
			cout<<"Enter The Author Name : ";
			fflush(stdin);
			getline(cin , name);
			
			
			cout<<endl<<endl;
			
			int i = 1;
			
			while(temp != NULL){
				
				if(temp->author == name){
					cout<<i<<". "<<temp->title<<endl;
				}
				
				i++;
				temp = temp->next;
			}
			
			cout<<endl<<endl;
		}
		
		
		void displayAllBooks(){
			
			temp = head;
			
			if(head == NULL){
				cout<<"No Nodes Added Yet "<<endl<<endl;
				return;
			}
			
			
			cout<<endl<<endl;
			int i = 1;
			while(temp != NULL){
				cout<<"*Book "<<i<<"* :-"<<endl;
				displayBookInfo(temp);
				
				temp = temp->next;
				i++;
			}
			
			cout<<endl<<endl;
		}
		
		void displayBookInfo(Node *tempHere){
			cout<<"ISBN Number : "<<tempHere->ISBN<<endl;
			cout<<"Author : "<<tempHere->author<<endl;
			cout<<"Title : "<<tempHere->title<<endl;
			cout<<"Genre : "<<tempHere->genre<<endl;
			cout<<"Publication Date : "<<tempHere->publicationDate.day<<" / "<<tempHere->publicationDate.month<<" / "<<tempHere->publicationDate.year<<endl;
			
			cout<<endl;
		}
		
		void searchABook(){
			
			if(head == NULL){
				cout<<"No Nodes Added Yet "<<endl<<endl;
				return;
			}
			
			int number;
			
			cout<<"Enter The ISBN Number Of The Book : ";
			cin>>number;
			
			temp = head;
			
			while(temp != NULL){
				
				if(temp->ISBN == number){
					displayBookInfo(temp);
					break;
				}
				
				temp = temp->next;
			
			}
		}
		
		
		void del(){
			
			int todelete;
			
			if(head == NULL){
				cout<<"No Node To Delete "<<endl<<endl;
				return;
			}
			
			
			cout<<"Enter The ISBN Number Of The Book To Delete : ";
			cin>>todelete;
			
			
			while(head != NULL && head->ISBN == todelete){
				
				temp = head;
				head = head->next;
				
				delete temp;
				size--;
				
				if(head != NULL){
					
					head->prev = NULL;
					
				}
				
				return;
				
			
			}
			
			
			temp = head;
			
			
			
			while(temp != NULL){
				
				if(temp->ISBN == todelete){
					
					temp1 = temp;
					
					temp->prev->next = temp->next;
					
					if(temp->next != NULL){
						
						temp->next->prev = temp->prev;
						
					}
					
					
					
					temp = temp1->prev;
					
					delete temp1;
					size--;
					return;
				}

				
				temp = temp->next;
			}
			
			cout<<"Book With to ISBN Number "<<todelete<<" Not Found"<<endl<<endl;
		}
};



int main(){
	
	DLL A;
	int input;
	
	do{
		cout<<"1. Add A New Book"<<endl;
		cout<<"2. Search For A Book"<<endl;
		cout<<"3. Display All Books"<<endl;
		cout<<"4. Display Books By Author Name"<<endl;
		cout<<"5. Display Related Books"<<endl;
		cout<<"6. Delete A Book"<<endl;
		cout<<"7. Exit"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>input;
		
		
		if(input == 1){
			A.add();
		}
		else if(input == 2){
			A.searchABook();
		}
		else if(input == 3){
			A.displayAllBooks();
		}
		else if(input == 4){
			A.displayBooksByAuthor();
		}
		else if(input == 5){
			A.recommendRelatedBooks();
		}
		else if(input == 6){
			A.del();
		}
		else if(input == 7){
			break;
		}
		else{
			cout<<"Wrong Option"<<endl;
		}
		
		cout<<endl<<endl;
		
	}
	while(input != 7);
	
}