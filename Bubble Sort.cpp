#include<iostream>
using namespace std ;

void swapping (int* x ,int *y){
	int temp = *x;  
	*x=*y;
	*y=temp;
	//pointer variable references address instead of value
}	

void bubble_sort(int arr[], int n){
	for (int i=0 ; i < n-1 ; i++){
		for (int j = 0; j< n- i-1; j++){
			if (arr[j] > arr[j+1]){
				swapping(&arr[j],&arr[j+1]);
			}
		}
	}
}

void printing_arr(int arr[], int size){
	for (int k=0; k< size ; k++){
		cout<<arr[k]<<"  ";
	}
	cout<<"\n";
}

int main(){
	int array[5]={6,4,2,1,5};
	int size = sizeof(array)/sizeof(array[0]);
	
	cout<<"before bubble sorting"<<"\n";
	printing_arr(array,size);
		
	bubble_sort(array,size);
	
	cout<<"After bubble sorting"<<"\n";
	printing_arr(array,size);
	return 0;
}
