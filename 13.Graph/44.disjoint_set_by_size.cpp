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
    vii compSize, parent;
public:
    DisjointSet(int n) {
        compSize.resize(n+1, 0);
        parent.resize(n+1);
        FORIn(i,0,n){
            parent[i]=i;
        }
    }
    int findUltimateParent(int node) {
        if(node==parent[node]) return node;
        return parent[node]=findUltimateParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUltimateParent(u), pv=findUltimateParent(v);
        if(pu==pv) return;
        if(compSize[pu]>=compSize[pv]) {
            parent[pv]=pu;
            compSize[pu]+=compSize[pv];
        } else {
            parent[pu]=pv;
            compSize[pv]+=compSize[pu];
        }
    }
};
int main() {
    optimize;
    int n=7;
    DisjointSet dsu(n);
    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);
    dsu.unionBySize(4, 5);
    dsu.unionBySize(6, 7);
    dsu.unionBySize(5, 6);
    // if 3 and 7 belong to same component or not
    if(dsu.findUltimateParent(3)==dsu.findUltimateParent(7)) {
        cout<<"Connected"<<"\n";
    } else {
        cout<<"Not connected"<<"\n";
    }
    dsu.unionBySize(3, 7);
    return 0;
}