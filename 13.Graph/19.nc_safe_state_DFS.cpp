//In a directed graph, safe nodes are nodes which either are terminal nodes or from which if we start, we always come across a terminal node. Array of these safe nodes is the safe state.
//anyone who is the part of the cycle or who leads to a cycle will never be a safe node.
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

bool BFS(int s,vector<vector<int>>&a,vector<int>&v, vector<int>&safe){
    vector<int>p(a.size(),0);
    queue<int>q;
    q.push(s);
    v[s]=1;
    p[s]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto &e : a[x]){
           if(v[e]!=1){
             q.push(e);
             v[e]=1;
             p[e]=1;   
            } else if (p[e]==1){
                return false;
            } 
        }
        if(q.empty()){
          safe.pb(x);  
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
       int x,y;
       cin>>x>>y;
       adj[x].pb(y);        
    }
    vector<int>vis(n,0);
    vector<int>safe;
    for(int i=0; i<n; i++){
       if(vis[i]!=1){
            if(BFS(i,adj,vis,safe))
                safe.pb(i);
       }
    }
    for(auto &e:safe){
        cout<<e<<" ";
    }
}