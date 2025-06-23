class Solution {
    vector<int>parent, size;
    int findParent(int node){
        if(node==parent[node]) return parent[node];
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu=findParent(u), pv=findParent(v);
        if(pu==pv) return;
        if(size[pu]>=size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        } else {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        // edgeCount[i] will store number of edges in the component whose root is i
        vector<int>edgeCount(n,0);
        int ans=0;
        for(auto &e:edges){
            unionBySize(e[0], e[1]);
        }
        // Count the number of edges in each component by assigning each edge to its root (component representative)
        for(auto &e:edges){
            int root = findParent(e[0]);
            edgeCount[root]++;
        }
        for(int i=0;i<n;i++){
            // for ultimate parents only
            if(i==findParent(i)){
                int nodes = size[i]; //size of component
                int requiredEdges=nodes*(nodes-1)/2;
                if(requiredEdges==edgeCount[i]) ans+=1;
            }
        }
        return ans;
    }
};