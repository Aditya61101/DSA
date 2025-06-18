class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>dependents(numCourses);
        vector<vector<int>>adjL(numCourses);
        for(auto &p:prerequisites) {
            dependents[p[0]]++;
            adjL[p[1]].push_back(p[0]);
        }
        vector<int>order;
        queue<int>q;
        for(int i=0;i<numCourses;i++) if(dependents[i]==0) q.push(i);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            order.push_back(curr);
            for(int &next:adjL[curr]) {
                dependents[next]--;
                if(dependents[next]==0) {
                    q.push(next);
                }
            }
        }
        return order.size()==numCourses ? order : vector<int>();
    }
};