#include <iostream>
#include <string>

using namespace std;

class Node {
	public:
	
		int movieID;
		string title;
		string genre;
		int ratings;
		Node *left;
		Node *right;
		
		Node(int ID , string title , string genre , int ratings ){
			left = NULL;
			right = NULL;
			
			this->movieID = ID;
			this->title = title;
			this->genre = genre;
			this->ratings = ratings;
		}

		// define the constructor
};

class MovieRecommendationSystem {
	public:
		Node* root;
		Node* temp;

	
		// define the constructor
		MovieRecommendationSystem(){
			root = NULL;
			temp = NULL;
		}

		// Insert a movie into the BST
		
		void insertMovie(Node *head , int movieID , string title , string genre , int ratings){
			
			if(head == NULL && head == root){
				root = new Node(movieID, title, genre, ratings);
			}
			else{
				if(movieID < head->movieID && head->left != NULL){
					insertMovie(head->left , movieID , title , genre , ratings);
				}
				else if(movieID > head->movieID && head->right != NULL){
					
					insertMovie(head->right , movieID , title , genre , ratings);
				}
				else{
					if(movieID < head->movieID){
						head->left = new Node(movieID, title, genre, ratings);
					}
					else{
						head->right = new Node(movieID, title, genre, ratings);
					}
				}
			}
		}

		// Recommend movies of a given genre
		void recommendMoviesByGenre(Node*head ,string genre) {
			
			if(head == NULL && head == root){
				cout<<"Nothing To Print"<<endl<<endl;
			}
			else{
				if(head->left != NULL){
					recommendMoviesByGenre(head->left , genre);
				}
				
				if(head->genre == genre){
					cout<<head->title<<endl;
				}
				
				
				if(head->right != NULL){
					recommendMoviesByGenre(head->left , genre);
				}
			}
		}
		
		Node* returnSuccessor(Node* head){
			
			while(head->left != NULL){
				head = head->left;
			}
			
			return head;
		}

		void displayMovies(Node *head){
			
			if(head == NULL && head == root){
				cout<<"Nothing To Print"<<endl<<endl;
			}
			else{
				if(head->left != NULL){
					displayMovies(head->left);
				}
				
				cout<<"Ratings : "<<head.ratings<<"  Title :"<<head->title<<endl;;
				
				if(head->right != NULL){
					displayMovies(head->right);
				}
			}
		}

		// Delete a movie by ID
		Node* deleteMovieByID(Node *head, int movieID) {
			if(head == NULL){
				return head;
			}
			else if(movieID < head->movieID){
				head->left = deleteMovieByID(head->left , movieID);
			}
			else if(movieID > head->movieID){
				head->right = deleteMovieByID(head->right , movieID);
			}
			else{
				if(head->right == NULL && head->left == NULL){
					delete head;
					head = NULL;
				}
				else if(head->left == NULL){
					temp = head;
					head = head->right;
					delete temp;
					temp = NULL;
				}
				else if(head->right == NULL){
					temp = head;
					head = head->left;
					delete temp;
					temp = NULL;
				}
				else{
					temp = returnSuccessor(head->right);
					head->movieID = temp->movieID;
					movieID = temp->movieID;
					head->right = deleteMovieByID(head->right , movieID);
				}
			}
			return head;
		}
		
		void printNamesByRating(Node *head) {
			
			if(head == NULL && head == root){
				cout<<"Nothing To Print"<<endl<<endl;
			}
			else{
				if(head->left != NULL){
					printNamesByRating(head->left);
				}
	
				cout<<head->title<<endl;
			
				if(head->right != NULL){
					printNamesByRating(head->left);
				}
			}
		}

};

int array[5];


int size = 0;

void insertSort(int number){
	
	if(size == 5){
		cout<<"Array FULL"<<endl;
		return;
	}
	
	if(size == 0){
		array[0] = number;
		size++;
		return;
	}
	
	for(int i=0;i<size;i++){
		if(number < array[i] && array[i] != -1){
			for(int j=size;j>=i;j--){
				array[j] = array[j-1];
			}
			
			array[i] = number;
			size++;
			
			return;
		}

	}
	
	array[size] = number;
	size++;
	
}

void delete1(){
	
	int todelete;
	
	if(size == 0){
		cout<<"Nothing To Delete "<<endl<<endl;
		return;
	}
	
	cout<<"Deleting "<<array[0]<<endl;
	
	for(int i=0;i<size-1;i++){
		
		array[i] = array[i + 1];
		
	}
	
	array[size-1] = -1;
	size--; 
}


void print(MovieRecommendationSystem temp){
	
	for(int i=0;i<5;i++){
		cout<<array[i]<<" ";
	}
	
	cout<<endl;
}



int main() {
	MovieRecommendationSystem engine;
	int choice;
	
	while (true) {
		cout << "Menu:\n";
		cout << "1. Add a Movie\n";
		cout << "2. Delete a Movie by ID\n";
		cout << "3. Recommend Movies by Genre\n";
		cout << "4. Display Movies Sorted by Ratings\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1: {
				int movieID;
				string title, genre;
				double ratings;
				cout << "Enter Movie ID: ";
				cin >> movieID;
				cin.ignore(); // Clear newline character from the buffer
				cout << "Enter Movie Title: ";
				getline(cin, title);
				cout << "Enter Movie Genre: ";
				getline(cin, genre);
				cout << "Enter Ratings: ";
				cin >> ratings;

				engine.insertMovie(engine.root, movieID, title, genre, ratings);
				insertSort(ratings);
				
				
				cout << "Movie added successfully!" << endl;
				cout<<"Movie Also Added Into The Array Successfully"<<endl<<endl;
				
				break;
			}
			case 2: {
				int deleteID;
				cout << "Enter Movie ID to delete: ";
				cin >> deleteID;
				engine.root = engine.deleteMovieByID(engine.root, deleteID);
				cout << "Movie with ID " << deleteID << " deleted successfully!" << endl;
				break;
			}
			case 3: {
				string genre;
				cout << "Enter your favorite genre: ";
				cin.ignore(); // Clear newline character from the buffer
				getline(cin, genre);
				engine.recommendMoviesByGenre(engine.root , genre);
				break;
			}
			case 4:
				
				engine.displayMovies(engine.root);
				break;
			case 5:
				cout << "Exiting the program." << endl;
				return 0;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
	}
	return 0;
}
