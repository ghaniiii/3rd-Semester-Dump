#include<iostream>
#include<string.h>

using namespace std;

struct Node{
	string songname;
	Node *next;
};


class PlayList{
	Node *head;
	Node *current;
	Node *temp;	
	Node *temp1;
	
	public:
		PlayList(){
			head = NULL;
			current = NULL;
			temp = NULL;
			temp1 = NULL;
		}
		
		void addSong(){
			
			string name;
			
			int option;
			
			if(head == NULL){
				
				head = new Node;
				
				cout<<"Enter The First Song : ";
				fflush(stdin);
				getline(cin , name);
					
				head->songname = name;
				
				head->next = NULL;
				
				return;
				
			}
			
			cout<<"1. Top Favourite"<<endl;
			cout<<"2. Somewhere In Between"<<endl;
			cout<<"3. Least Favourite"<<endl<<endl;
			
			cout<<"Enter Your Option : ";
			cin>>option;
			
			cout<<endl;
			
			temp = head;
			
			if(option == 1){
				temp = new Node;
				
				cout<<"Enter The Song Name : ";
				fflush(stdin);
				getline(cin , name);
					
				temp->songname = name;
				
				temp->next = head;
				
				head = temp;
				
				
				return;
			}
			else if(option == 2){
				
				temp = new Node;
				
				cout<<"Enter The Song Name : ";
				fflush(stdin);
				getline(cin , name);
					
				temp->songname = name;
				
				temp->next = head->next;
				
				head->next = temp;
				
				return ;
				
				
			}
			else if(option == 3){
				
				temp = head;
				
				while(temp != NULL){
					
					if(temp->next == NULL){
						temp1 = new Node;
						
						temp->next = temp1;
						
						cout<<"Enter The Song Name : ";
						fflush(stdin);
						getline(cin , name);
						
						temp1->songname = name;
						
						temp1->next = NULL;
						
						return;
					}
					
					temp = temp->next;
				}
				
			}
			
			
			
			
			
		}
		
		
		void deleteSong(){
			if(head == NULL){
				cout<<"No Song Added In The Playlist "<<endl;
				
				return;
			}
			
			string name;
			
			cout<<"Enter The Song Name : ";
			fflush(stdin);
			getline(cin , name);
					
		
			
			temp = head;
			
			if(head->songname == name && head->next == NULL){
				delete head;
				
				head = NULL;
				
				cout<<"Song Deleted Successfully"<<endl<<endl;
				
				return;
			}
			else{
				
				temp = head;
				
				while(head->songname == name && head->next != NULL){
					
					head = head->next;
					
					delete temp;
					
					temp = head;
					
					cout<<"Song Deleted Successfully"<<endl<<endl;
					
					return;
				
				}
				
				temp = head;
				
				while(temp != NULL && temp->next != NULL){
					
					if(temp->next->songname == name){
						
						temp1 = temp->next;
						
						temp->next = temp->next->next;
						
						delete temp1;
						
						cout<<"Song Deleted Successfully"<<endl<<endl;
						
						return;
						
						
					}
					
					temp = temp->next;
					
				}
				
			}
			
			cout<<"Song Not Found"<<endl<<endl;
			
		}
		
		
		void searchSong(){
			
			if(head == NULL){
				cout<<"No Song Added Till Now To Search From "<<endl;
				return;
			}
			
			string name;
			bool didntfind = true;
			
			cout<<"Enter The Song Name That Your Want To Search : ";
			fflush(stdin);
			getline(cin , name);
					
			
			
			temp = head;
			
			while(temp!=NULL){
				
				if(temp->songname == name){
					cout<<"The Song Name Is : "<<temp->songname<<" And Its Your ";
					
					if(temp == head){
						cout<<"Most Favourite"<<endl;
					}
					else if(temp->next == NULL){
						cout<<"Least Favourite"<<endl;
					}
					else {
						cout<<"Its Not Your Favourite  Nor Your Favourite ,  Comes In Middle"<<endl;
					}
					
					didntfind = false;
					
					return;
				}
				
				temp = temp->next;
			}
			
			if(didntfind == true){
				
				cout<<endl;
				cout<<"Song Was Not Found In The PlayList Please Enter A Song That Is In The Play List"<<endl<<endl;
				
			}
		}
		
		
		void UpdateSong(){
			
			string songname;
			
			if(head == NULL){
				cout<<"There Is No Song In The PlayList"<<endl;
				return;
			}
			
			cout<<"Enter The Song Name That You Want To Update : ";
			cin>>songname;
			
			
			temp = head;
			string name;
			
			while(temp != NULL){
				if(temp->songname == songname){
					
					cout<<"Enter The New Song Name At Place Of The Current One : ";
					fflush(stdin);
					getline(cin , name);
					
					temp->songname = name;
					
					cout<<endl<<endl;
					
					cout<<"Song Name Updated"<<endl;
					
					return ;
					
				}
				
				temp = temp->next;
			}
		}
		
		void printPlaylist(){
			if(head == NULL){
				cout<<"No Song Added To Print Till Now "<<endl;
				return;
			}
			
			temp = head;
			int counter = 1;
			
			cout<<"The Playlist Is :-"<<endl<<endl;
			
			while(temp != NULL){
				
				cout<<counter<<". "<<temp->songname<<endl;
				counter++;
				
				temp = temp->next;
			}
			
			
		}
		
		void printPlaylist1(){
			if(head == NULL){
				return;
			}
			
			temp = head;
			int counter = 1;
			
			cout<<"The Playlist Is :-"<<endl<<endl;
			
			while(temp != NULL){
				
				cout<<counter<<". "<<temp->songname<<endl;
				counter++;
				
				temp = temp->next;
			}
			
			
		}
		
		void playPlaylist(){
			if(head == NULL){
				cout<<"No Song Added To Play Till Now "<<endl;
				return;
			}
			
			temp = head;
			
			int counter = 1;
			int option;
			
			while(temp != NULL){
				
				cout<<endl;
				
				cout<<"Playing Now : "<<temp->songname<<endl<<endl;
				
				cout<<"Do You Want To Play The Next Song ? "<<endl;
				cout<<"1. Yes"<<endl;
				cout<<"2. No"<<endl<<endl;
				cout<<"Enter Your Option : ";
				cin>>option;
				
				cout<<endl<<endl;
				if(option == 2){
					
					cout<<endl<<"Playlist Stopped"<<endl<<endl;
					
					
					return;
					
					
				}
				
				temp = temp->next;
				counter++;
				
			}
			
			cout<<"The PlayList Has Ended"<<endl<<endl;
			
		}
		
		
		~PlayList(){
			delete head , current , temp , temp1;
		}
		
};


int main(){
	PlayList P;
	int option;
	
	
	do{
		
		P.printPlaylist1();
		cout<<endl;
		
		cout<<"Select An Option :-"<<endl<<endl;
		cout<<"1. Add A Song"<<endl;
		cout<<"2. Delete A Song"<<endl;
		cout<<"3. Print Playlist"<<endl;
		cout<<"4. Search A Song"<<endl;
		cout<<"5. Start Playlist"<<endl;
		cout<<"6. To Exit"<<endl<<endl;
		
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			P.addSong();
		}
		else if(option == 2){
			P.deleteSong();
		}
		else if(option == 3){
			P.printPlaylist();
		}
		else if(option == 4){
			P.searchSong();
		}
		else if(option == 5){
			P.playPlaylist();
		}
		
		
		cout<<endl<<endl;
		
		
	}
	while(option <= 5);
}