#include<iostream>
using namespace std;
int LCS(string a, string b, int n, int m){
    int arr[n+1][m+1];
    int length = 0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i == 0 || j == 0) arr[i][j] = 0;
            else if(a[i-1] == b[j-1]) arr[i][j] = arr[i-1][j-1] + 1;
            else arr[i][j] = 0;
            length = max(length, arr[i][j]);
        }
    }
    return length;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string a,b;
        cin>>n>>m;
        cin>>a;
        cin>>b;
        cout<<LCS(a,b,n,m)<<"\n";
    }
    return 0;
}