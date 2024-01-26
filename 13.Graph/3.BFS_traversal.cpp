//level wise traversal, when its a connected component
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define fi first
#define se second
#define pb push_back
#define ll long long
#define pu push
#define po pop

//this will work for both directed and undirected
vector<int> BFSTraversal(vector<vector<int>>&v, int ini, int n){
    vector<int>vis(n+1,0);
    queue<int>q;
    q.pu(ini);
    vis[ini]=1;
    vector<int>ans;
    while(!q.empty()){
        int a=q.front();
        q.pop();
        ans.pb(a);
        int i=0;
        //below while loop will traverse each list
        while (i!=v[a].size()){
            if (vis[v[a][i]]!=1){
                q.pu(v[a][i]);
                vis[v[a][i]]=1;
            }
            i++;
        }
    }
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
    vector<int>v=BFSTraversal(adj,ini,n);
    for (auto &it : v){
        cout<<it<<" ";
    }
}
//SC:O(N)
//TC: O(N)+O(2E)