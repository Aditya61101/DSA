class Solution {
    double bfs(string src, string dest, unordered_map<string,vector<pair<string,double>>>&m) {
        queue<tuple<string,double>>q;
        unordered_set<string> visited;
        q.push({src,1});
        visited.insert(src);
        while(!q.empty()){
            auto [curr,res]=q.front();
            q.pop();
            if(curr==dest) return res;
            for(auto [ne,val]:m[curr]){
                if(visited.count(ne)) continue;
                q.push({ne,res*val});
                visited.insert(ne);
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>mp;
        for(int i=0;i<equations.size();i++){
            double val=values[i];
            string u=equations[i][0], v=equations[i][1];
            mp[u].push_back({v, val});
            mp[v].push_back({u, 1/val});
        }
        vector<double>ans;
        for(auto &q:queries){
            if(!mp.count(q[0]) || !mp.count(q[1])){
                ans.push_back(-1.0);
                continue; 
            }
            double res = bfs(q[0], q[1], mp);
            ans.push_back(res);
        }
        return ans;
    }
};