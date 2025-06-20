class Solution {
private:
    vector<int>parent, compSize;
    int findParent(int node) {
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    // Connects nodes u and v if they are in different components.
    // Returns true if a union (merge) happened, false if already connected.
    bool unionBySize(int u, int v) {
        int pu=findParent(u), pv=findParent(v);
        if(pu==pv) return false; // belongs to same component, so no new component is merged
        if(compSize[pu]>=compSize[pv]) {
            parent[pv]=pu;
            compSize[pu]+=compSize[pv];
        } else {
            parent[pu]=pv;
            compSize[pv]+=compSize[pu];
        }
        return true; // we connected a component hence we reduce the no. of components
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int comp=n;
        compSize.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n;i++) parent[i]=i;
        int u, v;
        for(auto e:edges) {
            if(unionBySize(e[0], e[1])) {
                comp--; // Successfully merged two components
            }
        }
        return comp;
    }
};
