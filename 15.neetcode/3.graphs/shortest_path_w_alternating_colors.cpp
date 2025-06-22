class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>dist(n,-1);
        
        vector<vector<int>>adjR(n), adjB(n);
        for(auto &re:redEdges) adjR[re[0]].push_back(re[1]);
        for(auto &be:blueEdges) adjB[be[0]].push_back(be[1]);
        
        //{node,{curr_length, edge_color}}
        queue<pair<int, pair<int,char>>>q;
        unordered_set<string>edges; // store visited edges, to avoid cycle
        for(auto node:adjR[0]) {
            q.push({node,{'R',1}});
            string edge = string("0R")+to_string(node);
            edges.insert(edge);
            dist[node]=1;
        }
        for(auto node:adjB[0]) {
            q.push({node,{'B',1}});
            string edge = string("0B")+to_string(node);
            edges.insert(edge);
            dist[node]=1;
        }
        dist[0]=0;
        while(!q.empty()){
            auto [curr,mt]=q.front();
            auto [ed,d]=mt;
            q.pop();
            if(ed=='R'){
                for(auto no:adjB[curr]) {
                    if(dist[no]==-1) dist[no]=d+1;
                    string edge = to_string(curr)+"B"+to_string(no);
                    if(!edges.count(edge)) {
                        q.push({no,{'B',d+1}});
                        edges.insert(edge);
                    }
                }
            } else {
                for(auto no:adjR[curr]) {
                    if(dist[no]==-1) dist[no]=d+1;
                    string edge = to_string(curr)+"R"+to_string(no);
                    if(!edges.count(edge)){
                        q.push({no,{'R',d+1}});
                        edges.insert(edge);
                    }
                }
            }
        }
        return dist;
    }
};