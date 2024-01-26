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


int main(){
    Ad22Hc15;
    ll n,src,dest,k;
    cin>>n;
    vector<vector<ll>>flights={{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}};
    cin>>src>>dest>>k;
    vector<ll>dist(n,INT_MAX);
    vector<vector<pll>>adj(n);
    //creating adjacency list
    for(auto &x:flights){
        adj[x[0]].pb({x[1],x[2]});
    }
    dist[src]=0;
    queue<pair<ll,pll>>q;
    q.push({0,{src,0}});
    while(!q.empty()){
        pair<ll,pll>pp=q.front();
        q.pop();
        ll stops=pp.fi,node=pp.se.fi,cost=pp.se.se;
        if(stops>k) continue;
        for(auto it:adj[node]){
            ll adjNode=it.first;
            ll wt=it.second;
            if(dist[adjNode]>cost+wt&&stops<=k){
                dist[adjNode]=cost+wt;
                q.push({stops+1,{adjNode,cost+wt}});
            }
        }
    }
    if(dist[dest]==INT_MAX) cout<<"-1"<<"\n";
    else cout<<dist[dest]<<"\n";
}