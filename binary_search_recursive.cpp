#include<iostream>
using namespace std;

bool bs(int arr[],int s , int e,int k){
    int mid = (s+e)/2;
    if(s>e){
        return false;
    }
    if(arr[mid]==k){
        return true;
    }
    if(arr[mid]<k){
        return bs(arr,mid+1,e,k);
    }else{
        return bs(arr,s,mid-1,k);
    }

}





int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >>n;

    int arr[n];
    cout << "Enter elements : ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    
    int k;
    cout << "Enter the key to search: ";
    cin >>k;

    int result = bs(arr, 0, n - 1,k);
    if (result == false ) {
        cout << k << " found in the array.\n";
    } else {
        cout <<k << " not found in the array : "<<result<<endl;
    }

    return 0;
}
