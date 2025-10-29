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
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

void DS(ll s,vector<ll>&dist,vector<vector<pii>>&adj){
    set<pll>st;//queue<pll>q;
    dist[s]=0;
    st.insert({0,s});//q.push();
    while(!st.empty()){
        pll p=*(st.begin());
        st.erase(p);//queue/pq -> q.pop();
        ll node=p.se,dis=p.fi;
        for(auto &pi:adj[node]){
            ll curr=pi.fi,wt=pi.se;
            if(wt+dis<dist[curr]){
                // advantage of using set, we can't erase a mid between entry in priority_queue
                if(dist[curr]!=INT_MAX) st.erase({dist[curr],curr});
                dist[curr]=wt+dis;
                st.insert({dist[curr],curr});
            }
        }
    }
}
int main(){
    Ad22Hc15;
    ll n,m;
    cin>>n>>m;
    vector<vector<pii>> adj(n);
    FOR(i,0,m){
        ll x,y,w;
        cin>>x>>y>>w;
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }
    vector<ll>dist(n,INT_MAX);
    FOR(i,0,n){
        if(dist[i]==INT_MAX) DS(i,dist,adj);
    }
    FOR(i,0,n) cout<<dist[i]<<" ";
}