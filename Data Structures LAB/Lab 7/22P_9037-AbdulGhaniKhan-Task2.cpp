#include <iostream>
#include <string>


using namespace std;

struct Visitor{
	
    string name;
    Visitor* next;

    Visitor(string name){
    	
		next = NULL;
    	this->name = name;
	
	}
	
	
};

class Queue {
private:
    Visitor* head;
    Visitor* tail;
    int count;

public:
    Queue(){
    	head = NULL;
    	tail = NULL;
    	count = 0;
	}

    void enQueue(string name){
    	
        Visitor* newVisitor = new Visitor(name);
        
		if(!head){
			
            head = newVisitor;
            
        }
		else{
			
            tail->next = newVisitor;
        
		}
		
		
        tail = newVisitor;
        count++;
    }

    void deQueue(){
    	
        if(head){
        	
            Visitor* temp = head;
            head = head->next;
            delete temp;
            count--;
        
		}
    
	}

    int getCount(){
    	
        return count;
    
	}

    string getCurrentVisitor(){
    	
        return head ? head->name : "";
    
	}

    void process(const string& attractionName){
    	
        Visitor* current = head;
        
        while(current){
        	
            cout << "Visitor " << current->name << " is enjoying the "<<attractionName<<endl;
            current = current->next;
        }
        
    }

    ~Queue(){
    	
        while(head){
        	
            deQueue();
            
        }
        
    }
};

int main(){
	
    Queue ticketQueue;
    Queue rollerCoasterQueue;
    Queue motionRideQueue;
    Queue roundWheelQueue;
    

    int option;
    do{
    	
        cout << "1. Enter Visitor in Ticket Purchase Queue" << endl;
        cout << "2. Sell a Ticket" << endl;
        cout << "3. Process All Queues" << endl;
        cout << "0. Exit" << endl;
        cout << "Your Option: ";
        cin >> option;

        switch(option){
            case 1:{
                string name;
                cout << "Enter Visitor's Name: ";
                cin.ignore();
                getline(cin, name);
                ticketQueue.enQueue(name);
                cout << endl;
                break;
            }
            case 2:{
            	
                if(ticketQueue.getCount() > 0){
                    string visitorName = ticketQueue.getCurrentVisitor();
                    ticketQueue.deQueue();

                    cout << "Selling Ticket to: " << visitorName << endl;
                    cout << "Select Attraction (1 - Roller Coaster, 2 - Motion Ride, 3 - Round Wheel): ";
                    int attractionChoice;
                    cin >> attractionChoice;

                    switch (attractionChoice) {
                        case 1:
                            rollerCoasterQueue.enQueue(visitorName);
                            break;
                        case 2:
                            motionRideQueue.enQueue(visitorName);
                            break;
                        case 3:
                            roundWheelQueue.enQueue(visitorName);
                            break;
                        default:
                            cout << "Invalid attraction choice." << endl;
                            break;
                    }
                } 
				else{
                    cout << "No visitors in the ticket purchase queue." << endl;
                }
                
                break;
            }
            
            case 3:{
            	
                cout << "Processing Queues:" << endl;
                rollerCoasterQueue.process("Roller Coaster");
                motionRideQueue.process("Motion Ride");
                roundWheelQueue.process("Round Wheel");
                cout << endl;
                break;
                
            }
            case 0:
                cout << "Exiting the program." << endl;
                break;
                
            default:
                cout << "Invalid option. Try again." << endl;
                break;
                
		}
		
		
    }
	while (option != 0);

    return 0;
}
