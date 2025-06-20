class Solution {
private:
    void bfs(pair<int,int>p, vector<vector<bool>>&v, vector<vector<int>>&g, vector<pair<int,int>>&co) {
        queue<pair<int,int>>q;
        q.push(p); v[p.first][p.second]=true;
        vector<int>dx={-1,1,0,0}, dy={0,0,-1,1};
        while(!q.empty()) {
            auto [y,x]=q.front(); q.pop();
            bool isBoundary=false;
            for(int i=0;i<4;i++) {
                int ny=y+dy[i], nx=x+dx[i];
                if(ny<0 || ny>=g.size() || nx<0 || nx>=g[0].size()) continue;
                if(g[ny][nx]==0) isBoundary=true;
                if(g[ny][nx]==1 && !v[ny][nx]) {
                    q.push({ny, nx}); v[ny][nx]=true;
                }
            }
            // storing all the boundary cells of 1st island.
            if(isBoundary) co.push_back({y,x});
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        vector<vector<bool>>vis(r, vector<bool>(c,false));
        vector<pair<int,int>>coords; // to store all the boundary cells
        for(int i=0;i<r;i++){
            bool flag=false;
            // bfs to only mark all land cells of 1st island as visited
            for(int j=0;j<c;j++){
                if(grid[i][j]==1) {
                    bfs({i,j}, vis, grid, coords);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        
        vector<int>dx={-1,1,0,0}, dy={0,0,-1,1};
        queue<pair<pair<int, int>, int>>q;
        for(auto &c:coords) q.push({c, 0});
        // bfs from all the boundary cells of 1st island
        while(!q.empty()) {
            auto [c, m]=q.front();
            auto [y, x]=c;
            q.pop();
            for(int i=0;i<4;i++) {
                int ny=y+dy[i], nx=x+dx[i];
                if(ny<0 || ny>=grid.size() || nx<0 || nx>=grid[0].size()) continue;
                // if we found a land cell which was unvisited from 1st BFS this means it's a land cell of 2nd island and hence we returned no. of moves took to reach it.
                if(grid[ny][nx]==1 && !vis[ny][nx]) return m;
                // if it's a unvisited water cell, we increased our move(m) by 1
                if(!vis[ny][nx]) {
                    q.push({{ny, nx}, m+1});
                    vis[ny][nx]=true;
                }
            }
        }
        return -1; // this will never reach for a valid grid
    }
};