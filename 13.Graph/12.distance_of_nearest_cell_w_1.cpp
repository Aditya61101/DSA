/*Given a binary grid of N*M. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.*/
//same as rotten oranges
#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define ll  long long
#define fi first
#define se second
#define pb push_back
#define print(arr,n) for(int i=0;i<n;i++)cout<<arr[i]
#define scan(arr,n) for(int i=0;i<n;i++)cin>>arr[i]

vector<vector<int>> BFS(vector<vector<int>>&a,vector<vector<int>>&v){
    vector<vector<int>>ans=v;
    queue<pair<pair<int,int>,int>>q;
    for (int i=0; i<a.size(); i++){
        for (int j=0; j<a[0].size(); j++){
            if (a[i][j]==1){
                q.push({{i,j},0});
                v[i][j]=1;
            } 
        }
    }
    int xD[]={-1,0,1,0};
    int yD[]={0,-1,0,1};
    while(!q.empty()){
        int x=q.front().fi.fi, y=q.front().fi.se, dis=q.front().se;
        q.pop();
        ans[x][y]=dis;
        for(int i=0; i<4; i++){
            int x1=x+xD[i],y1=y+yD[i];
            if (x1>=0&&x1<a[0].size()&&y1>=0&&y1<a.size()&&v[x1][y1]!=1&&a[x1][y1]==0){
                q.push({{x1,y1},dis+1});
                v[x1][y1]=1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj;
    for (int i=0; i<n; i++){
        vector<int>temp;
        for (int j=0; j<m; j++){
            int x;
            cin>>x;
            temp.pb(x);
        }
        adj.pb(temp);
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>ans=BFS(adj,vis);
    for (auto &v : ans){
        for (auto &e : v){
            cout<<e<<" ";
        }
        cout<<"\n";
    }
}
//T.C:O(n*m)+O(n*m*4)
//S.C:O(n*m)+O(n*m)+O(n*m)