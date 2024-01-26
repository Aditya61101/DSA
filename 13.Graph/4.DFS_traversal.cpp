//recursive call and go to the depth of the node which is not visited.
#include<iostream>
#include<vector>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define ll  long long
#define MOD 1000000007
#define fi first
#define se second
#define pb push_back
#define pu push
#define po pop

void dfs(int node, vector<vector<int>>&v,vector<int>&vis,vector<int>&ans){
    vis[node]=1;
    ans.pb(node);
    //traverse its neighbour
    for (auto &it :v[node]){
        if (vis[it]!=1){
            dfs(it,v,vis,ans);
        }
    }
    
}
vector<int>DFSTraversal(vector<vector<int>>&v,int ini,int n){
    vector<int>vis(n+1,0);
    vector<int>ans;
    dfs(ini,v,vis,ans);
    return ans;
}
vector<vector<int>>creation(int n, int m){
    vector<vector<int>> adj(n+1);
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
    int n,m, ini=1;
    cin>>n>>m;
    vector<vector<int>>adj=creation(n,m);
    vector<int>v=DFSTraversal(adj,ini,n);
    for (auto &it : v)
        cout<<it<<" ";
}
//S.C:O(N)+O(N)+O(N)~O(N)
//sum(degrees)=2*E
//T.C:O(N)+2*E