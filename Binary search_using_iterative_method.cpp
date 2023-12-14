#include <iostream>
using namespace std;

int binary_search(int arr[] , int high , int low , int value){

	while (low <= high){
		int mid = low + (high - low)/2;	
		
		if (arr[mid] == value){
			return mid;
		}
		
		else if(arr[mid] < value){
			low = mid + 1;
		}
		
		else{
			high = mid - 1;
		}
	}
	
	return -1;
	
	
}

int main(){
	int size , value1 , result;
	cout << "Size of array : ";
	cin >> size;
	int arr1[size];
	
	for (int i = 0; i < size ; i++){
		cout << "Enter element " << i+1 << " : ";
		cin >> arr1[i];
	}
	
	cout << "Enter the value you want to search : ";
	cin >> value1;
	
	result = binary_search(arr1 , size -1 , 0 , value1);
	
	if (result == -1){
		cout << "Element not found ! ";
	}
	else{
		cout << "Element found at index " << result;
	}
	
	return 0;
}
