class Solution {
private:
    vector<int>parent, compSize;
    int findParent(int node) {
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu=findParent(u), pv=findParent(v);
        if(pu==pv) return;
        if(compSize[pu]>=compSize[pv]) {
            parent[pv]=pu;
            compSize[pu]+=compSize[pv];
        } else {
            parent[pu]=pv;
            compSize[pv]+=compSize[pu];
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        compSize.resize(n, 1);

        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        
        unordered_map<string, int>emailToAccIndex;
        for(int i=0;i<n;i++) {
            for(int j=1;j<accounts[i].size();j++) {
                string email = accounts[i][j];
                // if its a new email we map it to its account index
                if(!emailToAccIndex.count(email)) {
                    emailToAccIndex[email]=i;
                } else {
                    unionBySize(i, emailToAccIndex[email]); // else, we join the account indexes
                }
            }
        }
        vector<vector<string>>emails(n);
        for(auto &it:emailToAccIndex) {
            string email = it.first;
            int up = findParent(it.second); // finding the ultimate parent
            emails[up].push_back(email);
        }
        vector<vector<string>>mergedAccs;
        for(int i=0;i<n;i++) {
            if(emails[i].size()==0) continue;
            string name = accounts[i][0]; // extracting name
            sort(emails[i].begin(), emails[i].end()); // sorting the emails merged
            vector<string>temp;
            temp.push_back(name); // inserting name at the beginning
            temp.insert(temp.end(), emails[i].begin(), emails[i].end()); // inserting sorted mails
            mergedAccs.push_back(temp);
        }
        return mergedAccs;
    }
};