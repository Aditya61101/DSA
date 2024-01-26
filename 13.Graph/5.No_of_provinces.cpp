//BFS/DFS when components are not connected
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define ll  long long
#define fi first
#define se second
#define pb push_back
#define vll vector<int>

void BFS(int s,vll &vis,vector<vll>&v){
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int a=q.front();
        q.pop();
        int i=0;
        while (i!=v[a].size()){
            if (vis[v[a][i]]!=1){
                vis[v[a][i]]=1;
                q.push(v[a][i]);
            }
            i++;
        }
    }
}
int solve(vector<vll>v,int n){
    vector<int>vis(n+1,0);
    int count=0;
    for (int i=1; i<=n; i++){
        if (vis[i]!=1){
            BFS(i,vis,v);
            count++;
        }
    }
    return count;
}
vector<vll>creation(int n, int m){
    vector<vll> adj(n+1);
    for (int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    return adj;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vll>adj=creation(n,m);
    cout<<solve(adj,n);
}
//S.C: O(N)
//T.C: O(N)+O(N+2E)