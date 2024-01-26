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
    ll n;
    cin>>n;
    vector<vii>edges={{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    vector<vector<pll>>adj(n);
    for(auto x:edges){
        adj[x[0]].pb({x[1],x[2]});
        adj[x[1]].pb({x[0],x[2]});
    }
    vii ways(n,0),dist(n,INT_MAX);
    int src=0,des=n-1;
    dist[src]=0;
    ways[src]=1;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,src});
    while(!pq.empty()){
        int dis=pq.top().first;
        int curr=pq.top().second;
        pq.pop();
        for(auto p:adj[curr]){
            int node=p.fi,wt=p.se;
            //this is the first time coming with a shorter distance
            if(dis+wt<dist[node]){
                dist[node]=dis+wt;
                ways[node]=ways[curr];
                pq.push({dist[node],node});
            }
            //again coming with a same distance
            else if(dis+wt==dist[node]){
                ways[node]=(ways[node]%MOD+ways[curr]%MOD)%MOD;
            }
        }
    }
    if(dist[n-1]==INT_MAX) cout<<"-1"<<"\n";
    else cout<<ways[n-1]%MOD<<"\n";
}
//T.C:same as Dijkstra