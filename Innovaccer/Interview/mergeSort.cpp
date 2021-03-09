#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    int l = start;
    int r = mid+1;
    int temarr[end-start+1];
    int i=0;
    while(l <= mid && r <= end){
        if(arr[l] <= arr[r]){
            temarr[i] = arr[l];
            l++;
        }
        else{
            temarr[i] = arr[r];
            r++;
        }
        i++;
    }
    while(l <= mid){
        temarr[i] = arr[l];
        l++;
        i++;
    }
    while(r <= end){
        temarr[i] = arr[r];
        r++;
        i++;
    }
    i = 0;
    for(int k=start; k<=end; k++){
        arr[k] = temarr[i];
        i++;
    }
}

void mergeSort(int arr[0], int start, int end){
    if(start == end) return;
    int mid = (end+start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

void print(int arr[], int n){
    cout<<"Printing Array\n";
    for(int i=0; i<n; i++) cout<<arr[i]<<"\t";
    cout<<"\n";
}
int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    print(arr,n);
}