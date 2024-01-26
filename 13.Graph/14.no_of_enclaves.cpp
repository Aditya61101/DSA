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
#define print(arr,n) for(int i=0;i<n;i++)cout<<arr[i]<<
#define scan(arr,n) for(int i=0;i<n;i++)cin>>arr[i]

int BFS(vector<vector<int>>&a,vector<vector<int>>&v){
    queue<pair<int,int>>q;
    int n=a.size(),m=a[0].size();
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if(i==0||i==n-1||j==0||j==m-1){
                if(a[i][j]==1){
                    q.push({i,j});
                    v[i][j]=1;
                }
            }
        }
    }
    int xD[]={-1,0,1,0};
    int yD[]={0,-1,0,1};
    while(!q.empty()){
        pair<int,int>temp=q.front();
        int x=temp.first,y=temp.second;
        q.pop();
        for(int i=0; i<4; i++){
           int x1=x+xD[i],y1=y+yD[i];
           if (x1>=0&&x1<m&&y1>=0&&y1<n&&v[x1][y1]!=1&&a[x1][y1]==1){
                q.push({x1,y1});
                v[x1][y1]=1;
           }
        }
    }
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (a[i][j]==1&&v[i][j]==0){
                count++;
            }
        }
    }
    return count;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj;
    for(int i=0; i<n; i++){
        vector<int>temp;
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            temp.pb(x);
        }
        adj.pb(temp);
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
    cout<<BFS(adj,vis);
}