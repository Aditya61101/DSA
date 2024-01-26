#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define Ad22Hc15 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define ll  long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORIn(i,a,b) for(ll i=a;i<=b;i++)
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<ll> vll;
typedef vector<int> vii;

//multi source shortest path, helps to detect neg. cycle as well. Go via every node. Done using adjacency matrix. Can be implement using dijkstra algo. by applying it to individual nodes, but it should not contain any neg. cycle.
int main(){
    Ad22Hc15;
    ll n,e;
    cin>>n>>e;
    vector<vector<ll>>adj(n+1,vector<ll>(n+1,INT_MAX));
    FOR(i,0,e){
        ll u,v,wt;
        cin>>u>>v>>wt;
        adj[u][v]=wt;
        adj[u][u]=0;
        adj[v][v]=0;
    }
    FOR(k,0,n){
        FOR(i,0,n){
            FOR(j,0,n){
                if(adj[i][j]<0){
                    cout<<"Negative cycle present";
                    return 0;
                }
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    FOR(i,0,n){
        FOR(j,0,n){
            cout<<adj[i][j]<<" ";
        }
    }
}
//T.C:O(N^3)
//S.C:O(N*N)