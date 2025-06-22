class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dis(n, vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        while(!q.empty()) {
            auto [y,x]=q.front(); q.pop();
            for(int i=0;i<4;i++){
                int ny=dy[i]+y, nx=dx[i]+x;
                if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                if(grid[ny][nx]==0 && dis[ny][nx]==INT_MAX) {
                    dis[ny][nx]=dis[y][x]+1;
                    q.push({ny, nx});
                }
            }
        }
        int d=-1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                d=max(dis[i][j], d);
            }
        }
        return d==INT_MAX ? -1:d;
    }
};