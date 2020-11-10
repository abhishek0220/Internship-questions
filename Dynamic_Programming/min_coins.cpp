/*
Solution for https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
  public:
    vector<int> minPartition(int n)
    {
        int coins[] = {1,2,5,10,20,50,100,200,500,2000};
        int ind = sizeof(coins)/sizeof(coins[0]);
        vector<int> coins_req;
        ind--;
        while(n != 0){
            while(n != 0 && n >= coins[ind]){
                coins_req.push_back(coins[ind]);
                n -= coins[ind];
            }
            ind--;
        }
        return coins_req;
    }
};
int main(){
    int t,n;
    Solution ob;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> number = ob.minPartition(n);
        for(auto i : number)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}