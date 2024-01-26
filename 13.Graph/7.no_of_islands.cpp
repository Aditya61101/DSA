#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vll vector<int>

void BFS(pair<int,int>p,vector<vll>&a,vector<vll>&v){
    queue<pair<int,int>>q;
    q.push(p);
    v[p.first][p.second]=1;
    while(!q.empty()){
        pair<int,int>temp=q.front();
        int x=temp.first,y=temp.second;
        q.pop();
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                if (x+i>=0&&x+i<a.size()&&y+j>=0&&y+j<a[0].size()&&a[x+i][y+j]==1&&v[x+i][y+j]!=1){
                    q.push({x+i,y+j});
                    v[x+i][y+j]=1;
                }
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vll> adj(n,vll(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>adj[i][j];
    }
    vector<vll> vis(n,vll(m,0));
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (adj[i][j]==1&&vis[i][j]!=1){
                pair<int,int>ini={i,j};
                BFS(ini,adj,vis);
                count++;
            }
        }
    }
    cout<<count;
}
//S.C:O(n*n)+O(n*n)
//T.C:(n*n)+8*(n*n)