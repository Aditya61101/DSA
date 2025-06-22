class Solution {
    int r,c;
    void bfs(pair<int,int>p, vector<vector<int>>&g){
        queue<pair<int,int>>q;
        q.push(p);
        g[p.first][p.second]=0;
        vector<int>dx={-1,1,0,0}, dy={0,0,-1,1};
        while(!q.empty()){
            auto[y,x]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int ny=dy[i]+y, nx=dx[i]+x;
                if(nx>=0 && ny>=0 && nx<c && ny<r && g[ny][nx]==1){
                    g[ny][nx]=0;
                    q.push({ny,nx});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        r=grid.size(), c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if((i==0||j==0||i==r-1||j==c-1) && grid[i][j]==1) bfs({i,j}, grid);
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1) ans+=1;
            }
        }
        return ans;
    }
};