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
    vector<vector<int>>maze(n,vector<int>(m));
    FOR(i,0,n){
        FOR(j,0,m){
            cin>>maze[i][j];
        }
    }
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    pii src={0,0},des={n-1,m-1};
    dist[0][0]=0;
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>pq;
    pq.push({0,src});
    int xD[]={0,-1,0,1};
    int yD[]={-1,0,1,0};
    while(!pq.empty()){
        pair<int,pii>pp=pq.top();
        int dis=pp.fi,row=pp.se.fi,col=pp.se.se;
        if(pp.se==des) break;
        pq.pop();
        FOR(i,0,4){
            int x1=row+xD[i],y1=col+yD[i];
            if(x1>=0&&x1<n&&y1>=0&&y1<m){            
                int effort=max(abs(maze[x1][y1]-maze[row][col]),dis);
                if(effort<dist[x1][y1]){
                    dist[x1][y1]=effort;
                    pq.push({effort,{x1,y1}});
                }  
            }
        }
    }
    cout<<dist[n-1][m-1]<<"\n";
}
//T.C:O(N*M*4*log(N*M))