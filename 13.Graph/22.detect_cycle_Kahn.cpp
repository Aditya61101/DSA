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

int main(){
    Ad22Hc15;
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    vector<ll>inDegree(n+1,0);
    FOR(i,0,m){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        inDegree[y]++;
    }
    queue<ll>q;
    //for 1 based indexing nodes
    FOR(i,1,n){
        if (inDegree[i]==0){
            q.push(i);
        }
    }
    ll count=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        count++;
        for(auto &e:adj[x]){
            inDegree[e]--;
            if(inDegree[e]==0){
              q.push(e);  
            }
        }
    }
    if(count!=n) cout<<"Cycle present";
    else cout<<"No cycle";
}