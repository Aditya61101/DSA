// using BFS
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target=="0000") return 0;
        
        unordered_set<string>vs, dd;
        for(auto &s:deadends) dd.insert(s);        
        
        if(dd.count("0000")) return -1;
        
        queue<pair<string, int>>q;
        q.push({"0000", 0});
        vs.insert("0000");
        while(!q.empty()) {
            auto [st, mo]=q.front();
            q.pop();
            if(st==target) return mo;
            for(int i=0;i<4;i++){
                string next=st;
                for(int d=-1;d<=1;d+=2) {
                    next[i]=(st[i]-'0'+d+10)%10+'0';
                    if(!vs.count(next) && !dd.count(next)) {
                        q.push({next, mo+1}); 
                        vs.insert(next);
                    }
                }
            }
        }
        return -1;
    }
};