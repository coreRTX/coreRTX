# include <iostream>
using namespace std;

void Merge(int arr[] ,  int l , int mid , int r){
	
	int n1 = mid - l + 1; 
	int n2 = r - mid;
	
	int a[n1];
	int b[n2];
	
	for (int i = 0 ; i < n1 ; i++){
		a[i] = arr[l + i];
	}
	
	for (int j = 0 ; j < n2; j++){
		b[j] = arr[mid + 1 + j];
	}
	
	int i = 0;
	int j = 0;
	int k = l;
	
	while (i < n1 && j < n2){
		if (a[i] <  b[j]){
			arr[k] = a[i];
			k++;
			i++;
		}
		else{
			arr[k] = b[j];
			k++ ;
			j++;
		}
	}
	
	while (i < n1){
		arr[k] = a[i];
		k++ ; i++;
	}
	
	while (j < n2){
		arr[k] = b[j];
		k++ ; j++ ;
	}
	
}

void MergeSort(int arr[] , int l , int r){
	
	if (l < r){
		int mid = (l + r) / 2;
		
		MergeSort(arr , l , mid);
		MergeSort(arr , mid + 1 , r);
		
		Merge(arr , l , mid , r);
	}
}

int main(){
	int arr1[6] = {10 , 9 , 8 , 7 , 6 , 5};
	
	MergeSort(arr1 , 0 , 5);
	
	for (int i = 0 ; i < 6 ; i++){
		cout << arr1[i] << "\t";
	}
	return 0;
}
