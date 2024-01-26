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

//it won't work for negative weights as for every traversal we will have a dist+wt which will be smaller than curr distance as the distance goes on reducing due to the neg. weight, which means every time, we will be pushing something. So the queue will never be empty.
void BFS(int s,vector<vector<int>>&adj,vector<int>&dist){
    dist[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto &e:adj[node]){
            //this means we can reach the node with a shorter distance, show will visit the node(push that into the queue)
            if(dist[node]+1<dist[e]){
                dist[e]=dist[node]+1;
                q.push(e);
            }
        }
    }
}
int main(){
    Ad22Hc15;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    FOR(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<int>dist(n,INT_MAX);
    FOR(i,0,n){
        //if dist[i]==INT_MAX then the node is not visited
        if(dist[i]==INT_MAX){
            BFS(i,adj,dist);
        }
    }
    for(auto &e:dist) cout<<e<<" ";
}
//T.C:O(N+2M)