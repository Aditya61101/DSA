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

//spanning tree: tree which has 'n' nodes and 'n-1' edges and each node is reachable from any other node. Spanning tree with sum of weights as minimum is known as minimum spanning tree.
int main(){
    Ad22Hc15;
    ll n,e;
    cin>>n>>e;
    vector<ll>vis(n,0);
    vector<vector<pii>>adj(n);
    FOR(i,0,e){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].pb({v,wt});
        adj[v].pb({u,wt});
    }
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>pq;
    //{wt,{node,parent}}
    pq.push({0,{0,-1}});
    ll sum=0,chk=0;
    vector<pll>mst;
    while(!pq.empty()){
        auto pp = pq.top();
        ll node=pp.se.fi, parent=pp.se.se, weight=pp.fi;
        vis[node]=1;
        pq.pop();
        if(chk==1){
            mst.pb({parent,node});
        }
        sum+=weight;
        for(auto p:adj[node]){
            int curr=p.se, wt=p.fi;
            if(!vis[curr]){
                pq.push({wt,{curr,node}});
                chk=1;
            }
        }
    }
    cout<<sum<<"\n";
    for(auto p:mst){
        cout<<p.fi<<" "<<p.se<<"\n";
    }
}
//for only sum, we don't need parent in the priority queue. Priority queue is used to implement the BFS in greedy way.
//T.C:O(2*E*logE)