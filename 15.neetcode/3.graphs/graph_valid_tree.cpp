// using normal BFS
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjL(n);
        vector<bool>vis(n, false);
        for(auto &e:edges) {
            adjL[e[0]].push_back(e[1]);
            adjL[e[1]].push_back(e[0]);
        }
        queue<pair<int,int>>q;
        q.push({0,-1});
        vis[0]=true;
        // this loop checks for cycle
        while(!q.empty()) {
            auto [curr, p]=q.front();
            q.pop();
            for(int &ne:adjL[curr]) {
                // if the node is already visited and its not the parent of current node then it has been visited by some other path and if we reach it again then there is a cycle and trees don't have any cycle.
                if(vis[ne] && p!=ne) return false;
                if(!vis[ne]) {
                    q.push({ne, curr});
                    vis[ne]=true;
                }
            }
        }
        // this checks if the structure is disjoint or not, if all nodes can't be visited then it's disjoint and a tree is not a disjoint structure.
        for(auto v:vis) if(!v) return false;
        return true;
    }
};
