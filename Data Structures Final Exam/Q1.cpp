#include <iostream>
using namespace std;

class Node{
public:
    string val;
    Node *next;
    Node(string val)
    {
        this->val = val;
        next = NULL;
    }
};

class Stack{
public:
    Node *top;
    Node *temp;

    Stack(){
        top = NULL;
        temp = NULL;
    }
    ~Stack(){
        while (!isEmpty())
        {
            pop();
        }
    }

    bool isEmpty(){
        return top == NULL;
    }

    void push(string val){
        temp = new Node(val);
        temp->next = top;
        top = temp;
    }

    string pop(){
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return "";
        }
        string tempVal = top->val;
        temp = top;
        top = top->next;
        delete temp;
        return tempVal;
    }
};

class Queue{
    int front;
    int rear;
    int size;
    string *arr;

public:
    Queue(int size){
        front = -1;
        rear = -1;
        this->size = size;
        arr = new string[size];
    }

    ~Queue(){
        delete[] arr;
    }

    bool isEmpty(){
        return front == -1 && rear == -1;
    }

    bool isFull(){
        return (rear + 1) % size == front;
    }

    void enqueue(string val){
        if (isFull()){
            cout << "Queue is full" << endl;
            return;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else{
            rear = (rear + 1) % size;
        }
        
        arr[rear] = val;
    }

    string dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return "";
        }
        
		
		string val = arr[front];
        
		
		if(front == rear){
            front = rear = -1;
        }
        else{
            
			front = (front + 1) % size;
        
		}
        return val;
        
    }

    void getFront(){
    	
        if (isEmpty()){
            cout << "Queue is empty" << endl;
        }
        else{
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main(){
	
    int choice;
    // Set up the stack for encounters
    Stack encounters;

    Queue mansionQueue(6);
    mansionQueue.enqueue("The Gateway to Darkness");
    mansionQueue.enqueue("The Creeping Corridor");
    mansionQueue.enqueue("The Abandoned Lounge");
    mansionQueue.enqueue("The Haunted Gallery");
    mansionQueue.enqueue("The Shadowed Library");
    mansionQueue.enqueue("The Broken Window");

    cout<<"Start exploring the mansion? "<<endl;
    cout<<"1. Yes"<<endl;
    cout<<"2. No"<<endl;
    cin>>choice;

    if(choice == 1){
    	
        while(!mansionQueue.isEmpty()){
            string currentPlace = mansionQueue.dequeue();
            cout << "Exploring: " << currentPlace << endl;
            
            bool encounteredGhost = (rand() % 2) == 1; 
            if(encounteredGhost){
                cout << "Encountered a ghost at "<<currentPlace<<endl;
                encounters.push(currentPlace);
            }
        }

        cout<<"You left safe and sound!"<<endl;
        cout<<"Recent ghost encounters: "<<endl;
        while(!encounters.isEmpty()){
            cout <<"Encountered a ghost at " << encounters.pop() << endl;
        }
    }
    else{
        cout<<"See you next time"<<endl;
        return 0;
    }

    return 0;
}
