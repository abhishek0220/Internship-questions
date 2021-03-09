#include<bits/stdc++.h>
using namespace std;
int getMaxProfit(int savings, int cvalue[], int fvalue[], int n){
    int dp[n+1][savings+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=savings; j++){
            if(i == 0 || j==0) dp[i][j] = 0;
            else if(j < cvalue[i-1]) dp[i][j] = dp[i-1][j];
            else{
                int tem = dp[i-1][j-cvalue[i-1]] + (fvalue[i-1] - cvalue[i-1]);
                dp[i][j] = max(tem, dp[i-1][j]);
            }
        }
    }
    return dp[n][savings];
}
int main(){
    int cvalue[] = {175, 133, 109, 201, 97};
    int fvalue[] = {200, 125, 128, 228, 133};
    int savings = 250;
    int n = sizeof(cvalue)/sizeof(cvalue[0]);
    cout<<getMaxProfit(savings, cvalue, fvalue, n)<<"\n";
}