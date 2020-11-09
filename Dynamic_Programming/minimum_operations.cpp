#include<iostream>
using namespace std;
class Solution
{
  public:
    int minOperation(int n)
    {
        if(n==0) return 0;
        if(n%2==0) return minOperation(n/2)+1;
        return minOperation(n-1)+1;
    }
};
int main(){
    int t,n;
    Solution ob;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<ob.minOperation(n)<<"\n";
    }
    return 0;
}