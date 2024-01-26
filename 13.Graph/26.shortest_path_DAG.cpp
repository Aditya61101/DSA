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
typedef pair<int,int> pii;

ll inv(ll i) {if (i == 1) return 1; return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;}
ll modMul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
ll modAdd(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) {a %= MOD; ll res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}

//following code gives the shortest path of each node from the starting node.
void DFS(int node,vector<vector<pii>>adj,vector<ll>&vis,stack<ll>&st){
    vis[node]=1;
    for(auto &e:adj[node]){
        if(vis[e.fi]!=1){
            DFS(e.fi,adj,vis,st);
        }
    }
    st.push(node);
}

int main(){
    Ad22Hc15;
    ll n,m;
    cin>>n>>m;
    vector<vector<pii>>adj(n);
    FOR(i,0,m){
        int x,y,wt;
        cin>>x>>y>>wt;
        adj[x].pb({y,wt});
    }
    vector<ll>vis(n,0);
    stack<ll>st;
    vector<ll>dist(n,INF);
    //topological sort
    FOR(i,0,n){
        if(vis[i]!=1){
            DFS(i,adj,vis,st);
        }
    }
    //shortest path
    int s=0;
    dist[s]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        for(auto &e:adj[node]){
            ll v=e.first,wt=e.second;
            dist[v]=min(dist[v],dist[node]+wt);
        }
    }
    for(auto &d:dist){
        //i.e if the distance doesn't exists
        if(d==INF){
            cout<<"-1";
            continue;
        }
        cout<<d<<" ";
    }
}
//s-1. do the topological sort(nodes which are reachable first, go them, this minimize no. of steps)
//s-2. initialize dist array with INF
//s-3. dist[s]=0
//s-4. for each node in topological sort
//s-5. for each edge from node
//s-6. dist[i]=min(dist[i],dist[node]+wt)
//s-7. return dist
//s-8. Time complexity: O(N+M)
//s-9. Space complexity: O(V)
//s-10. https://www.youtube.com/watch?v=2kREIkF9UAs