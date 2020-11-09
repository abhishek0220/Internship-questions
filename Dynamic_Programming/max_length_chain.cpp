/*
https://practice.geeksforgeeks.org/problems/max-length-chain/1
*/
#include<iostream>
#include<map>
using namespace std;

map<pair<int, int>, int> mem_table; 
struct val{
    int first, second;
};
int maxChainLenRecur(struct val arr[], int n, int prev, int curr){
    if(curr >= n) return 0;
    if(mem_table.find({curr, prev}) != mem_table.end()) return mem_table[{curr, prev}];
    if(arr[curr].first <= prev) return maxChainLenRecur(arr, n, prev, curr+1);
    mem_table[{curr, prev}] =  max(maxChainLenRecur(arr, n, arr[curr].second, 0 )+1, maxChainLenRecur(arr, n, prev, curr+1));
    return mem_table[{curr, prev}];
}
int maxChainLen(struct val arr[], int n){
    mem_table.clear();
    return maxChainLenRecur(arr, n, -1, 0);
}
int main(){
    #ifndef ONLINE_JUDGE
        //freopen("max_length_chain_input.txt", "r", stdin);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        val arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i].first>>arr[i].second;
        cout<<maxChainLen(arr, n)<<"\n";
    }
    return 0;
}