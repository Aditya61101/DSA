class Solution {
    int r,c;
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
    int closedIsland(vector<vector<int>>& grid) {
        r=grid.size(), c=grid[0].size();
        int n=r*c;
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        vector<int>dx={-1,1,0,0}, dy={0,0,-1,1};
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    int u=i*c+j;
                    for(int k=0;k<4;k++){
                        int nx=j+dx[k], ny=i+dy[k];
                        if(nx>=0 && ny>=0 && nx<c && ny<r && grid[ny][nx]==0){
                            int v=ny*c+nx;
                            unionBySize(u,v);
                        }
                    }
                }
            }
        }
        unordered_set<int>boundaryRoots;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++) {
                if((i==0 || j==0 || i==r-1 || j==c-1) && grid[i][j]==0){
                    int node = i*c+j;
                    boundaryRoots.insert(findParent(node));
                }
            }
        }
        unordered_set<int> closedRoots;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 0) {
                    int root = findParent(i * c + j);
                    if(!boundaryRoots.count(root)) {
                        closedRoots.insert(root);
                    }
                }
            }
        }
        return closedRoots.size();
    }
};