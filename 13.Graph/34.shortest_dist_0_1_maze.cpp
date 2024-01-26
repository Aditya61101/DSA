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

//in this we don't need PQ since everyone is at a unit distance.
int main(){
    Ad22Hc15;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>maze(n,vector<int>(m));
    FOR(i,0,n){
        FOR(j,0,m){
            cin>>maze[i][j];
        }
    }
    pii src={0,1},des={2,2};
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    dist[src.fi][src.se]=0;
    queue<pair<int,pii>>q;
    q.push({0,src});
    int xD[]={-1,0,1,0};
    int yD[]={0,1,0,-1};
    while(!q.empty()){
        pair<int,pii>pp=q.front();
        q.pop();
        int dis=pp.first;
        pii coord=pp.second;
        int x=coord.fi,y=coord.se;
        FOR(i,0,4){
            int x1=x+xD[i],y1=y+yD[i];
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&maze[x1][y1]!=0){
                int newDis=dis+1;
                if(newDis<dist[x1][y1]){
                    dist[x1][y1]=newDis;
                    pii co={x1,y1};
                    //if we have reached the destination then we can safely break as we are traversing level wise(BFS) so for first time we will reach our destination with the shortest distance.
                    if(co==des) break;
                    q.push({newDis,{x1,y1}});
                }
            }
        }
    }
    if(dist[des.fi][des.se]==INT_MAX) cout<<-1<<"\n";
    else cout<<dist[des.fi][des.se]<<"\n";
}