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
typedef pair<int, int> pii;

ll inv(ll i) {if (i == 1) return 1; return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;}
ll modMul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
ll modAdd(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) {a %= MOD; ll res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}

int main(){
    Ad22Hc15;
    ll n,m;
    cin>>n>>m;
    vector<vector<pii>> adj(n+1);
    FOR(i,0,m){
        int x,y,wt;
        cin>>x>>y>>wt;
        adj[x].pb({y,wt});
        adj[y].pb({x,wt});
    }
    int src=1,des=n;
    vector<int>parent(n+1);
    vector<int>dist(n+1,INT_MAX);
    dist[src]=0;
    FOR(i,1,n+1){
        parent[i]=i;
    }
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,src});
    while(!pq.empty()){
        pii p=pq.top();
        pq.pop();
        int dis=p.fi,node=p.se;
        for(auto &pi:adj[node]){
            int curr=pi.fi,wt=pi.se;
            if(wt+dis<dist[curr]){
                dist[curr]=wt+dis;
                pq.push({dist[curr],curr});
                parent[curr]=node;
            }
        }
    }
    //storing the paths
    vector<int>ans;
    ans.pb(n);
    int curr=parent[n];
    ans.pb(curr);
    //loop going till curr doesn't become source
    while(curr!=src){
        curr=parent[curr];
        ans.pb(curr);
    }
    //reversing because we first pushed destination
    reverse(ans.begin(),ans.end());
    for(auto &e:ans) cout<<e<<" ";
}
//T.C: O(M*logN)+O(N)