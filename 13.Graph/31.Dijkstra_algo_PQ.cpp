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

//it won't work for negative weights as for every traversal we will have a dist+wt which will be smaller than curr distance as the distance goes on reducing due to the neg. weight, which means every time, we will be pushing something. So the queue will never be empty and it will run forever.

//Dijkstra's algo using priority queue
//PQ is better than queue because through PQ we can reach to a node in a greedy way i.e we can reach it through min. distance as PQ is sorted a/distance. But if all the weights are same then it doesn't matter whether we use PQ or queue.
void DJ(int s,vector<ll>&dist,vector<vector<pii>>&adj){
    priority_queue<pii,vector<pii>,greater<pii>>minHeap;
    dist[s]=0;
    minHeap.push({dist[s],0});
    while(!minHeap.empty()){
        pii p=minHeap.top();
        minHeap.pop();
        int node=p.se, dis=p.fi;
        for(auto &pi:adj[node]){
            int wt=pi.se,curr=pi.fi;
            //if we have a min. distance then only we will visit it
            if(dist[curr]>dis+wt){
                dist[curr]=dis+wt;
                minHeap.push({dist[curr],curr});
            }
        }
    }
}
int main(){
    Ad22Hc15;
    ll n,m;
    cin>>n>>m;
    vector<vector<pii>> adj(n);
    vector<ll>dist(n,INT_MAX);
    FOR(i,0,m){
        ll x,y,w;
        cin>>x>>y>>w;
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }
    int src=0;
    DJ(src,dist,adj);
    // FOR(i,0,n){
    //     if(dist[i]==INT_MAX){
    //         DJ(i,dist,adj);
    //     }
    // }
    FOR(i,0,n) cout<<dist[i]<<" ";
}
//T.C: O(M*logN)