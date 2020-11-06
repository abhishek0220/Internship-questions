/*
Solution for https://www.geeksforgeeks.org/segregate-even-and-odd-numbers-set-2/
*/
#include<iostream>
using namespace std;
#define N 1005

int lps(string &s, int a, int b, int arr[][N]){
    if(arr[a][b] != -1) return arr[a][b];
    int n = b-a+1;
    int ans;
    if(n <= 1) ans = n;
    else if(s[a] != s[b])
        ans = max(lps(s, a, b-1, arr), lps(s, a+1, b, arr));
    else ans = lps(s, a+1, b-1, arr)+2;
    arr[a][b] = ans;
    return ans;
}
int main(){
    int t;
    string s;
    int arr[N][N];
    cin>>t;
    while(t--){
        cin>>s;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                arr[i][j] = -1;
        cout<<lps(s, 0, s.length()-1, arr)<<"\n";
    }
    return 0;
}