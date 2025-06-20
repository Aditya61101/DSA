class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<pair<int, int>, int>>q;
        q.push({{0,0}, 1});
        grid[0][0]=1;
        vector<int>d={-1,1,0};
        while(!q.empty()) {
            auto [c, l]=q.front();
            auto [y, x]=c;
            q.pop();
            // we reached the destination through BFS so it will give us shortest distance only
            if(y==n-1 && x==n-1) return l;
            for(int i=0;i<3;i++) {
                for(int j=0;j<3;j++) {
                    if(d[i]==0 && d[j]==0) continue;
                    int ny=y+d[j], nx=x+d[i];
                    if(ny>=0 && nx>=0 && ny<n && nx<n && grid[ny][nx]==0) {
                        q.push({{ny, nx}, l+1});
                        grid[ny][nx]=1;
                    }
                }
            }
        }
        return -1;
    }
};