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
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<ll> vll;
typedef vector<int> vii;

int main(){
    Ad22Hc15;
    ll n,e,threshold;
    cin>>n>>e>>threshold;
    vector<vector<ll>>adj(n+1,vector<ll>(n+1,INT_MAX));
    FOR(i,0,e){
        ll u,v,wt;
        cin>>u>>v>>wt;
        adj[u][v]=wt;
        adj[v][u]=wt;
        adj[u][u]=0;
        adj[v][v]=0;
    }
    ll countMax=n+1,city=-1;
    FOR(i,0,n){
        ll count=0;
        FOR(j,0,e){
            if(adj[i][j]<=threshold)
                count++;
        }
        if(count<=countMax){
            countMax=count;
            city=i;
        }
    }
    cout<<city<<"\n";
}