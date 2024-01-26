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

ll inv(ll i) {if (i == 1) return 1; return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;}
ll modMul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
ll modAdd(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) {a %= MOD; ll res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}

//only for Directed Acyclic Graph
void DFS(int s, vector<ll>&v,vector<vector<ll>>&a,stack<ll>&st){
    v[s]=1;
    for(auto &e:a[s]){
        if (v[e]!=1){
            DFS(e,v,a,st);
        }
    }
    st.push(s);
}
int main(){
    Ad22Hc15;
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n);
    vector<ll>vis(n,0);
    stack<ll>st;
    FOR(i,0,m){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }
    FOR(i,0,m){
        if (vis[i]!=1){
            DFS(i,vis,adj,st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
//Topological Sort: Linear ordering of vertices such that if there is a edge like u->v, u appears before v in this ordering.
//Why stack is used to store the elements?
// Node whose recursion will be completed first should be present after the one whose recursion will end after it, to maintain the linear ordering. To do this we need a stack as stack stores nodes in LIFO manner.