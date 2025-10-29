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
        if (inDegree[i]==0) q.push(i);
    }
    ll count=0;
    while(q.size()){
        int x=q.front();
        q.pop();
        count++;
        for(auto &e:adj[x]){
            if(--inDegree[e]==0) q.push(e);  
        }
    }
    if(count!=n) cout<<"Cycle present";
    else cout<<"No cycle";
}