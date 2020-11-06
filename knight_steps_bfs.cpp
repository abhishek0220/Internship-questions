/*
Solution for https://practice.geeksforgeeks.org/problems/steps-by-knight
*/
#include<iostream>
#include<queue>
using namespace std;
struct cell{
    int x,y,dis;
    cell() {}
    cell(int x, int y, int dis) : x(x), y(y), dis(dis) {} 
};

bool inBoard(cell c, int n){
    int x = c.x;
    int y = c.y;
    if( x>= 1 && x<=n && y>=1 && y<=n ) return true;
    return false;
}

int main(){
    int t, n, x, y, ex, ey;
    cin>>t;
    int mov[][2] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,-1},{-2,1}};
    while(t--){
        cin>>n;
        bool visited[n + 1][n + 1]; 
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                visited[i][j] = false; 
        cin>>x>>y;
        cell start = cell(x,y,0);
        cin>>ex>>ey;
        queue<cell> q;
        q.push(start);
        visited[x][y] = true;
        while(!q.empty()){
            cell ele = q.front();
            if(ele.x == ex && ele.y == ey){
                cout<<ele.dis<<"\n";
                break;
            }
            q.pop();
            for(auto i : mov){
                x = ele.x+i[0];
                y = ele.y+i[1];
                cell new_cell = cell(x, y, ele.dis + 1);
                if(inBoard(new_cell, n) && !visited[x][y]){
                    visited[x][y] = true;
                    q.push(new_cell);
                }
            }
        }
    }
    return 0;
}