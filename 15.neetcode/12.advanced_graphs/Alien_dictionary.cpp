#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
        unordered_map<char,unordered_set<char>>adj;
        vector<int>exists(26);
        vector<int>inDegree(26);
        // collecting existing chars
        for(string word:words) for(char c:word) exists[c-'a']=1;
        // comparing adjacent words
        for(int i=0;i<n-1;i++){
            string &curr=words[i];
            string &next=words[i+1];
            int k=0;
            bool isEntered=false;
            while(k<min(next.size(),curr.size())){
                if(curr[k]!=next[k]){
                    adj[curr[k]].insert(next[k]);
                    inDegree[next[k]-'a']+=1;
                    isEntered=true;
                    break;
                }
                k+=1;
            }
            // if prefix are present in wrong order
            if(!isEntered && next.size()<curr.size()) return "";
        }
        queue<char>q;
        for(int i=0;i<26;i++) {
            if(exists[i]==1 && inDegree[i]==0) q.push('a'+i);
        }
        unordered_set<char>helper;
        string order="";
        while(q.size()){
            char c=q.front(); q.pop();
            helper.insert(c);
            order+=c;
            for(char v:adj[c]){
                if(--inDegree[v-'a']==0) q.push(v);
            }
        }
        // all chars were never used
        for(int it:inDegree) if(it!=0) return "";
        
        return order;
    }
};
