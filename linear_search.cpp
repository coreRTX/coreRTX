# include <iostream>
using namespace std;

int linear_search(int arr[] , int size , int value){
	for (int i = 0; i < size ; i++){
		if (arr[i] == value){
			return i;
		}
		else{
			continue;
		}
	}
	return -1;
}	
		
	
int main(){
	int size1;
	cout << "Enter the size of the array : ";
	cin >> size1;
	
	int arr1[size1] , value1 , result;
	
	for (int i = 0; i < size1 ; i++){
		cout << "Enter the element " << i+1 << " : ";
		cin >> arr1[i];
	}
	
	cout << "Enter the number whose index you want to find : ";
	cin >> value1;
	
	result = linear_search(arr1 , size1 , value1);
	
	if (result == -1){
		cout << " \n Number not found !";
	}
	
	else{
		cout << " \n The required index is : " << result;
	}
	
	return 0;
}
