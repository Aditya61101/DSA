#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define optimize ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define ll  long long
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORIn(i,a,b) for(ll i=a;i<=b;i++)
typedef vector<int> vii;

class DisjointSet {
    vii rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        FORIn(i,0,n){
            parent[i]=i;
        }
    }
    int findUltimateParent(int node) {
        if(node==parent[node]) return node;
        return parent[node]=findUltimateParent(parent[node]);
    }
    void unionByRank(int u, int v) {
        int pu = findUltimateParent(u), pv=findUltimateParent(v);
        if(pu==pv) return;
        if(rank[pu]==rank[pv]) {
            parent[pv]=pu;
            rank[pu]++;
        } else if(rank[pu]>rank[pv]) {
            parent[pv]=pu;
        } else {
            parent[pu]=pv;
        }
    }
};
int main() {
    optimize;
    int n=7;
    DisjointSet dsu(n);
    dsu.unionByRank(1, 2);
    dsu.unionByRank(2, 3);
    dsu.unionByRank(4, 5);
    dsu.unionByRank(6, 7);
    dsu.unionByRank(5, 6);
    // if 3 and 7 belong to same component or not
    if(dsu.findUltimateParent(3)==dsu.findUltimateParent(7)) {
        cout<<"Connected"<<"\n";
    } else {
        cout<<"Not connected"<<"\n";
    }
    dsu.unionByRank(3, 7);
    return 0;
}