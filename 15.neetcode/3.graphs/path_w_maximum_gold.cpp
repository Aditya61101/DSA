class Solution {
    int rows,cols;
    vector<int>dr={-1,1,0,0}, dc={0,0,-1,1};
    void dfs(int r, int c, vector<vector<int>>&g, int sum, int &ans){
        int temp=g[r][c];
        g[r][c]=0;
        ans=max(ans, sum);
        for(int i=0;i<4;i++){
            int nr=dr[i]+r, nc=dc[i]+c;
            if(nr>=0 && nc>=0 && nc<cols && nr<rows && g[nr][nc]!=0) {
                dfs(nr, nc, g, sum+g[nr][nc], ans);
            }
        }
        g[r][c]=temp;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        rows=grid.size(), cols=grid[0].size();
        int ans=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]!=0){
                    dfs(i,j,grid,grid[i][j],ans);
                }
            }
        }
        return ans;
    }
};