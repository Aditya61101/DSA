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
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        // since each cell can be divided into 4 subcells cz of slashes
        int sn=4*n*n;
        //DSU initialization
        size.resize(sn,1);
        parent.resize(sn);
        for(int i=0;i<sn;i++) parent[i]=i;
        // grid traversal
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // {cell->node}=(i,j)->(i*cols+j), so for 4 subcells we do 4*(i*cols+j)
                int base = 4*(i*n+j);
                char c=grid[i][j];
                // in clockwise direction
                int top=base+0, right=base+1, bottom=base+2, left=base+3;
                if (c == '/') {
                    unionBySize(top, left);
                    unionBySize(right, bottom);
                } else if (c == '\\') {
                    unionBySize(top, right);
                    unionBySize(bottom, left);
                } else {
                    unionBySize(top, right);
                    unionBySize(right, bottom);
                    unionBySize(bottom, left);
                }
                // connecting neighboring cells, only if current cell is not last row or column cell
                if(i<n-1) {
                    int neighborTop = 4*((i+1)*n+j)+0;
                    unionBySize(bottom, neighborTop);
                }
                if(j<n-1){
                    int neighborLeft=4*(i*n+(j+1))+3;
                    unionBySize(right, neighborLeft);
                }
            }
        }
        unordered_set<int>regions;
        for(int i=0;i<sn;i++){
            regions.insert(findParent(i));
        }
        return regions.size();
    }
};