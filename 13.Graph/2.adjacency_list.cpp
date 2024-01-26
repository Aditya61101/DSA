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
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);//vector<int>adj[n+1];
    // for weighted graph
    //vector<vector<pair<int,int>>>adj(n+1);
    for (int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        //for undirected graph
        adj[a].pb(b);
        adj[b].pb(a);
        //for directed graph if a->b
        //adj[a].pb(b);
        //for weighted graph
        //adj[a].pb({b,w});
    }
    for (int i = 1; i < n+1; i++){
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
}