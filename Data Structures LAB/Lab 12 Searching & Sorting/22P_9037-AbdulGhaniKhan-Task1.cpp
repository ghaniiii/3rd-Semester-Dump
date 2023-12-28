#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void display(int size, int arr[]) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void bubbleSort(int size, int arr[]) {
    int comparisons = 0;
    int temp;
    int flag;
   // implement the bubble sort logic here
   	// display the array after each pass (inner loop)
   	
   	for(int i=0;i<size-1;i++){
   		
		if(flag == 0){
				break;
		}
			
		flag = 0;
		
		for(int j = 0 ; j < size-i-1 ; j++){
			
			comparisons++;
			
			if(arr[j] >  arr[j+1]){
				
				flag =1;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
					
			}
			
		}
		
		display(size , arr);
		cout<<endl;
		
	}
   	
    cout << "Bubble Sort Comparisons: " << comparisons << endl;
}

void selectionSort(int size, int arr[]) {
    int comparisons = 0;
    int temp;
    // implement the selection sort logic here
    // display the array after each pass (inner loop)
    
	for(int i=0 ;i<size-1;i++){
		
		int minimum = i;
		
		for(int j = i+1 ;j<size;j++){
			
			comparisons++;
			
			if(arr[j] < arr[minimum]){
				minimum = j;
			}
		}
		
		temp = arr[i];
		arr[i] = arr[minimum];
		arr[minimum] = temp;
		
		
		display(size , arr);
	}	
    
    cout << "Selection Sort Comparisons: " << comparisons << endl;
    
}

// Merge two subarrays L and M into arr
void merge(int arr[], int left, int mid, int right) {
	
	int leftSize = mid - left + 1;
	int rightSize = right - mid;
	
	int leftArr[leftSize];
	int rightArr[rightSize];
	
	for(int i=0;i<leftSize;i++){
		leftArr[i] = arr[left + i];
	}
	
	for(int i=0;i<rightSize;i++){
		rightArr[i] = arr[mid + 1 + i];
	}
	
	int l , m , n;
	
	l = 0;
	m = 0;
	n = left;
	
	while(l < leftSize && m < rightSize){
		if(leftArr[l] <= rightArr[m]){
			arr[n] = leftArr[l];
			l++;
		}
		else{
			arr[n] = rightArr[m];
			m++;
		}
		n++;
	}
	
	
	while(l < leftSize){
		arr[n] = leftArr[l];
		l++;
		n++;
	}
	
	while(m < rightSize){
		arr[n] = rightArr[m];
		m++;
		n++;
	}
}


void mergeSort(int arr[], int l, int r) {
	
	
	if(l < r){
		int mid = (l + (r-l)/2);
		
		mergeSort(arr , l , mid);
		mergeSort(arr , mid+1 , r );
		merge(arr , l , mid , r);
	}
	
}


int binarySearchRecursive(int arr[], int left, int right, int key, int &comparisons) {
    // implement the recursive binary search logic here
    
    int mid;
    
    mid = (left + (right-left)/2);
    
    comparisons++;
    
    if(left <= right){
    	if(arr[mid] == key){
    		return mid;
		}
		
		if(arr[mid] == key){
			return mid;
		}
		else{
			if(arr[mid] < key){
				return binarySearchRecursive(arr , mid+1 , right , key , comparisons);
			}
			else{
				return binarySearchRecursive(arr , left , mid-1 , key , comparisons);
			}
		}
	}
	
    
    return -1;
}

int binarySearchIterative(int arr[], int size, int key, int &comparisons) {
   // implement the iterative binary search logic here
   int mid;
   int left = 0;
   int right = size-1;
   
   while(left <= right){
   		comparisons++;
		mid = (left+(right-left)/2);
		
		if(arr[mid] == key){
			return mid;
		}
		else{
			if(arr[mid] < key){
				left = mid+1;
			}
			else{
				right = mid-1;
			}
		}
   }
   
   return -1;
   
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Display the menu
    cout << "\nMenu:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Merge Sort\n";
    cout << "4. Binary Search (Recursive)\n";
    cout << "5. Binary Search (Iterative)\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(size, arr);
            break;
        case 2:
            selectionSort(size, arr);
            break;
        case 3:
            mergeSort(arr, 0, size-1);
            display(size, arr);
            break;
        case 4: {
            int key;
            cout << "Enter the value to find: ";
            cin >> key;
            int comparisons = 0;
            int result = binarySearchRecursive(arr, 0, size - 1, key, comparisons);
            if (result != -1) {
                cout << "Element found at index " << result << endl;
            } else {
                cout << "Element not found\n";
            }
            cout << "Comparisons: " << comparisons << endl;
            break;
        }
        case 5: {
            int key;
            cout << "Enter the value to find: ";
            cin >> key;
            int comparisons = 0;
            int result = binarySearchIterative(arr, size, key, comparisons);
            if (result != -1) {
                cout << "Element found at index " << result << endl;
            } else {
                cout << "Element not found\n";
            }
            cout << "Comparisons: " << comparisons << endl;
            break;
        }
        default:
            cout << "Invalid choice\n";
    }

    return 0;
}
