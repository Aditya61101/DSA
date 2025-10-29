#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define Ad22Hc15 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define INF 1000000000000000005
#define ll  long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORIn(i,a,b) for(ll i=a;i<=b;i++)
typedef pair<ll, ll> pll;

//only for Directed Acyclic Graph
void dfs(int s, vector<ll>&v,vector<vector<ll>>&a,stack<ll>&st){
    v[s]=1;
    for(auto &e:a[s]){
        if (v[e]!=1) dfs(e,v,a,st);
    }
    st.push(s);
}
int main(){
    Ad22Hc15;
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n);
    vector<ll>vis(n,0);
    stack<ll>st;
    FOR(i,0,m){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }
    FOR(i,0,m){
        if (vis[i]!=1) dfs(i,vis,adj,st);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
//Topological Sort: Linear ordering of vertices such that if there is a edge like u->v, u appears before v in this ordering.
//Why stack is used to store the elements?
// Node whose recursion will be completed first should be present after the one whose recursion will end after it, to maintain the linear ordering. To do this we need a stack as stack stores nodes in LIFO manner.