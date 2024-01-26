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

//1.reverse the edges
//2. Do the topological sorting
int main(){
    Ad22Hc15;
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n);
    vector<ll>inDegree(n,0);
    FOR(i,0,m){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }
    //reverse the edges
    vector<vector<ll>>revAdj(n);
    FOR(i,0,n){
        for(auto &e:adj[i]){
            revAdj[e].pb(i);
            inDegree[i]++;
        }
    }
    queue<ll>q;
    for(ll i=0;i<n;i++){
        if(inDegree[i]==0) q.push(i);
    }
    vector<ll>ans;
    while(!q.empty()){
        int x=q.front();
        ans.pb(x);
        q.pop();
        for(auto &e:revAdj[x]){
            inDegree[e]--;
            if(inDegree[e]==0){
              q.push(e);  
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(auto &e:ans){
        cout<<e<<" ";
    }
}