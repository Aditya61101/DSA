#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define optimize ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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

//spanning tree: tree which has 'n' nodes and 'n-1' edges and each node is reachable from any other node. Spanning tree with sum of weights as minimum is known as minimum spanning tree.
class DisjointSet {
    vii parent, compSize;
public:
    DisjointSet(int n) {
        compSize.resize(n+1, 1);
        parent.resize(n+1);
        FORIn(i, 0, n){
            parent[i]=i;
        }
    }
    // path compression
    int findParent(int node) {
        if(parent[node]==node) return parent[node];
        return parent[node]=findParent(parent[node]);
    }
    bool unionBySize(int u, int v) {
        int pu=findParent(u), pv=findParent(v);
        if(pu==pv) return false;
        if(compSize[pu]>=compSize[pv]) {
            parent[pv]=pu;
            compSize[pu]+=compSize[pv];
        } else {
            parent[pu]=pv;
            compSize[pv]+=compSize[pu];
        }
        return true;
    }
};
int main() {
    optimize;
    // take input n
    int n, m;
    cin>>n>>m;
    DisjointSet dsu(n);
    // {wt, {u,v}}
    vector<pair<int, pair<int,int>>>edges;
    for(int i=0;i<m;i++) {
        int wt, u, v;
        cin>>wt>>u>>v;
        edges.push_back({wt, {u,v}});
    }
    sort(edges.begin(), edges.end());
    int minWt=0;
    for(int i=0;i<m;i++) {
        if(dsu.unionBySize(edges[i].second.first, edges[i].second.second)) {
            minWt+=edges[i].first;
        }
    }
    cout<<minWt<<"\n";
}