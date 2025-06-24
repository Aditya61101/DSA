class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>mp;
        unordered_map<string,int>outdeg;
        unordered_set<string>rec_set, supp_set;
        for(auto &re:recipes) rec_set.insert(re);
        for(auto &su:supplies) supp_set.insert(su);

        int n=recipes.size();
        for(int i=0;i<n;i++){
            outdeg[recipes[i]]=0;
            bool is_buildable=true;
            for(int j=0;j<ingredients[i].size();j++){
                string ing = ingredients[i][j];
                if(rec_set.count(ing)){
                    mp[ing].push_back(recipes[i]); // reverse graph to include outdegree concept
                    outdeg[recipes[i]]++; // increase outdegree by one
                } else if(!supp_set.count(ing)) {
                    is_buildable=false;
                }
            }
            if(!is_buildable) outdeg[recipes[i]]=-1;
        }
        queue<string>q;
        for(auto &it:outdeg) {
            if(it.second==0) q.push(it.first);
        }
        vector<string>ans;
        while(!q.empty()) {
            string curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto dep:mp[curr]){
                outdeg[dep]--;
                if(outdeg[dep]==0) q.push(dep);
            }
        }
        return ans;
    }
};