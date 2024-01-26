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
    ll n,k;
    cin>>n>>k;
    vector<string>v;
    FOR(i,0,n){
        string s;
        cin>>s;
        v.pb(s);
    }
    vector<vector<int>>adj(k);
    vector<int>inDegree(k,0);
    FOR(i,0,n-1){
        string fir=v[i],sec=v[i+1];
        int l=min(fir.size(),sec.size());
        FOR(j,0,l){
            if(fir[j]!=sec[j]){
                int x=fir[j]-'a',y=sec[j]-'a';
                adj[x].pb(y);
                inDegree[y]++;
                break;
            }
            if (fir.size()>sec.size()){
                cout<<"Not possible"<<"\n";
                return 0;
            }
        }
    }
    queue<int>q;
    FOR(i,0,k){
        if(inDegree[i]==0) q.push(i);
    }
    string ans="";
    int count=0;
    //topological sort code
    while(!q.empty()){
        int x=q.front();
        q.pop();
        int t=x+97;
        char ch=char(t);
        ans+=ch;
        count++;
        for(auto &e:adj[x]){
            inDegree[e]--;
            if(inDegree[e]==0) q.push(e);
        }
    }
    if (count!=n) cout<<"Not possible"<<"\n";
    else cout<<ans;
}
//not possible when:-
//1. the larger string appears before shorter string and every char matches till the size of the shorter string.
//2. if there is a cyclic dependency like abc,bat,ade.