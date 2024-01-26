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

bool DFS(vector<vector<int>>&a, vector<int>&v,pair<int,int>s){   
    v[s.fi]=1;
    for (auto &node:a[s.fi]){
        if (v[node]!=1){
            if(DFS(a,v,{node,s.first})){
                return true;
            }
        } else if (node!=s.second){
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //n->nodes, m->edges
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0; i<m; i++){
       int x,y;
       cin>>x>>y;
       adj[x].pb(y);
       adj[y].pb(x); 
    }
    vector<int>vis(n+1,0);
    for (int i=1; i<=n; i++){
        if (vis[i]!=1){
            if(DFS(adj,vis,{i,0})){
                cout<<"Cycle detected";
                break;
            }
        }
    }
}
//S.C:O(N)+O(N)
//T.C:O(N+2*E)+O(N)