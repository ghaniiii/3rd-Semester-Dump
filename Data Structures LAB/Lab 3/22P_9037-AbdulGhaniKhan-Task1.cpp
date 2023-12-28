#include <iostream>
#include <string.h>

using namespace std;

class ArrayList{
	
	int steps;
    int size;
    int length;
    char* array;
    char* current;
    char* temp;

	public:

    ArrayList(int size){
    	
    	steps = 0;
        this->size = size;
        array = new char[size];
        current = NULL;
        temp = NULL;
        array[0] = 'i';
        array[1] = 'g';
        array[2] = 'h';
        array[3] = 'a';
        array[4] = 'n';
        length = 5;
    }

    void moveFirst(){
    
	    current = array;
    
	}

    void moveEnd(){
    	
        current = array + length - 1;
    
	}

    void removeCharacter(){
        
		
		int position;
        cout << "Enter The Position That You Want To Delete : ";
        cin >> position;
        
        
        if(position < 1 || position > length){
        	
            cout << "Position Is Wrong" << endl;
        
		}
        else{
        	
            
			current = array + position - 1;
            
			for(int i = position; i < length; i++){
				
                *current = *(current + 1);
                
                current++;
            	
			
			}
            
			
			length--;
			steps++;
        
		}
    }

    void addCharacter(){
    	
    	
        if(size == length){
        
		    cout << "Array Is Full, Cannot Add More Characters" << endl;
            return;
        
		}

        int position;
        
        cout << "Enter At What Position You Want To Enter The Character : ";
        cin >> position;

        if(position < 1 || position > length + 1){
        	
            cout << "Wrong Position" << endl;
        
		}
        else{
        	
            current = array + length;
            
            for (int i = length ; i >= position ; i--){
            	
                *(current) = *(current - 1);
                
                current--;
            	
			}
			
            
			cout << "Enter The Character : ";
            cin >> *current;
            length++;
            steps++;
        
		}
    }

    void printArray(){
    	
        current = array;
        
        for(int i = 0; i < length; i++){
        	
        	
            cout << *current << " ";
            current++;
        
		
		}
    
	
	}

    int match(){
    	
        current = array;
        
		if(strcmp(current, "ghani") == 0) {
            return 5;
        }
        
		
		return 0;
    }
    
    int returnSteps(){
    	return steps;
	}
    
    ~ArrayList(){
    	delete array;
	}
};

int main() {
    ArrayList A(5);
    int option;

    do{
    	
        A.printArray();
        cout << endl << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Print" << endl;
        cout << "Enter Your Option : ";
        cin >> option;

        if(option == 1){
         
		    A.addCharacter();
        
		}
        else if (option == 2){
        	
            A.removeCharacter();
        
		}

        option = A.match();
        
        if(option == 5){
      	
      	A.printArray();
      	
      	cout<<endl<<endl;
      	
      	cout<<endl<<endl;
      	
	    cout<< "Yayyy, That's Correct" << endl;
    	cout<<  "Steps Used Are : "<<A.returnSteps()<<endl;
    	
		}

    }
	while(option != 5);

    

    return 0;
}
