class Solution {
    vector<int>parent, size;
    int findParent(int node) {
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int pu=findParent(u), pv=findParent(v);
        if(pu==pv) return;
        if(size[pu]>=size[pv]) {
            parent[pv]=pu;
            size[pu]+=size[pv];
        } else {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
        
        int score=INT_MAX;
        for(auto &ro:roads) unionBySize(ro[0], ro[1]);
        for(auto &ro:roads) {
            // if any node(ro[0] or ro[1]) is in same component as 1(i.e it has same parent as 1) then we can traverse this edge, hence we calc min. of already calc edge and this edge
            if(findParent(ro[0])==findParent(1)) score=min(score,ro[2]);
        }
        return score;
    }
};