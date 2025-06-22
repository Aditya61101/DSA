class Solution {
    int r,c;
    bool bfs(pair<int,int>p, vector<vector<int>>& g) {
        bool onBoundary=false;
        if(p.first==0 || p.second==0 || p.first==r-1 || p.second==c-1) onBoundary=true;
        queue<pair<int,int>>q;
        q.push({p.first,p.second});
        g[p.first][p.second]=1;
        vector<int>dx={-1,1,0,0}, dy={0,0,-1,1};
        while(!q.empty()) {
            auto [y,x]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int ny=y+dy[i], nx=dx[i]+x;
                if(ny>=0 && nx>=0 && ny<r && nx<c && g[ny][nx]!=1){
                    if(ny==0||nx==0||ny==r-1||nx==c-1) onBoundary=true;
                    q.push({ny, nx});
                    g[ny][nx]=1;
                }
            }
        }
        return !onBoundary;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        r=grid.size(), c=grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) if(grid[i][j]==0 && bfs({i,j}, grid)) ans+=1;
        }
        return ans;
    }
};