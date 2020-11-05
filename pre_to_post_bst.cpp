/*
https://practice.geeksforgeeks.org/problems/preorder-to-postorder/0
*/

#include<iostream>
#include<vector>
using namespace std;
void postorder(vector<int> arr){
    int n = arr.size();
    if(n == 0) return;
    int head = arr[0];
    vector<int> left, right;
    for(int i=1; i<n; i++ ){
        if(arr[i] < head)   left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }
    postorder(left);
    postorder(right);
    cout<<head<<"\t";
}
int main(){
    int arr[] = { 40, 30, 35, 80, 100 };
    vector<int> arrk;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        arrk.push_back(arr[i]);
    }
    postorder(arrk);
    cout<<"\n";
}