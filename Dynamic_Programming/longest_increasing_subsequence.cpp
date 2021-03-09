#include<iostream>
#include<map>
using namespace std;
map<pair<int, int>, int> dir;


int longestSubsequence(int n, int arr[])
{
    int lis[n];
    lis[0] = 1; 
    for(int i=1; i<n; i++){
        lis[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]) lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    int max_ele = 0;
    for(int i=0; i<n; i++)
        max_ele = max(max_ele, lis[i]);
    return max_ele;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout<<longestSubsequence(n, arr)<<"\n";
    }
    return 0;
}