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

//works for negative cycle, negative edge weight(usually for directed graphs)
int main(){
    Ad22Hc15;
    int n,e;
    cin>>n>>e;
    vector<vii>adj(n);
    FOR(i,0,e){
        int u,v,w;
        cin>>u>>v>>w;
        vector<int>temp;
        temp.pb(u);
        temp.pb(v);
        temp.pb(w);
        adj.pb(temp);
    }
    vector<int>dist(n,INT_MAX);
    int st=0;
    dist[st]=0;
    FOR(i,0,n-1){
        for(auto it:adj){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=INT_MAX&&dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    //nth relaxation to chk presence of neg cycle
    for(auto it:adj){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u]!=INT_MAX&&dist[u]+wt<dist[v]){
            cout<<"Negative cycle present"<<"\n";
            return 0;
        }
    }
}
//do N-1 iterations for dijkstra algo
//to detect where we have a negative cycle or not
//if even at Nth iteration there is a updation in distance array this means that this will go on forever i.e, there is a neg. cycle.
//T.C:O(n*e)