//for a cycle, on the same path node has to be visited.
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

bool DFS(int s,vector<int>&p,vector<int>&v,vector<vector<int>>&a){
    v[s]=1;
    p[s]=1;
    for(auto &e:a[s]){
        if(v[e]!=1)
            if(DFS(e,p,v,a)) return true;
        // if their is a node which is visited, for the graph to have a cycle that node should be path visited as well. This will tell us that the node is visited during this traversal itself.
        else if(p[e]==1)
            return true;
    }
    p[s]=0;
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    //adjacency list creation
    vector<vector<int>>adj(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    vector<int>pathVis(n+1,0);
    vector<int>vis=pathVis;
    for(int i=1; i<=n; i++){
       if(vis[i]!=1){
         if(DFS(i,pathVis,vis,adj)==true){
            cout<<"Cycle detected";
            return 0;
         }
       }
    }
    cout<<"No cycle present";
    return 0;
}