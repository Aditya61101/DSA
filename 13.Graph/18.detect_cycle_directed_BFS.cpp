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

bool BFS(int s, vector<int>&v,vector<vector<int>>&a){
    vector<int>p(a.size()+1, 0);
    queue<int>q;
    q.push(s);
    v[s]=1;
    p[s]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for (auto &e : a[x]){
            if(v[e]!=1){
              q.push(e);
              v[e]=1;
              p[e]=1;
            } else if(p[e]==1){
                return true;
            }
        }
    }
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
    vector<int>vis(n+1,0);
    for(int i=1; i<=n; i++){
       if(vis[i]!=1){
         if (BFS(i,vis,adj)==true){
            cout<<"Cycle detected";
            return 0;
         }
       }
    }
    cout<<"No cycle present";
    return 0;
}