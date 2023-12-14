#include<iostream>
using namespace std ;

void swapping (int* x ,int *y){
	int temp = *x;  
	*x=*y;
	*y=temp;
	//pointer variable references address instead of value
}

void printing_arr(int arr[], int size){
	for (int k=0; k< size ; k++){
		cout<<arr[k]<<"  ";
	}
	cout<<"\n";
}

int partition(int array[], int start, int end){
	int pivot_element = array[start];
	int count = 0 ;
	for (int i = start +1 ; i <=end; i++){
		if (array[i] <= pivot_element){
			count++ ;
		}
	}
	// index of pivot will be start+count, as the loop above has selected the elements less than or equal to pivot
	int index_pivot = start+count;
	swapping(&array[index_pivot],&array[start]);
	//after getting pivot at its place now arranging left and right
	while (start<index_pivot && end > index_pivot){
		while (array[start]<=pivot_element){
			start++ ;
		}
		while (pivot_element<= array[end]){
			end-- ;
		}
		if (start<index_pivot && end>index_pivot){
			swapping(&array[start++],&array[end--]);
		}
	}
	return index_pivot ;
}

void quicksort(int arr[], int start, int end){
	if (start>=end){
		return;
	}
	int p = partition(arr, start, end);
	quicksort(arr,start,p-1);
	quicksort(arr,p+1,end);
}

int main(){
	int array[]={3,5,2,1};
	int size = sizeof(array)/sizeof(array[0]);
	
	cout<<"before sorting"<<"\n";
	printing_arr(array,size);
		
	quicksort(array,0,size-1);
	
	cout<<"After sorting"<<"\n";
	printing_arr(array,size);
	return 0;
}
