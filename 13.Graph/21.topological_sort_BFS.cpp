#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//Also known Kahn's Algo
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n);
    vector<ll>inDegrees(n);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegrees[y]+=1;
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(inDegrees[i]==0) q.push(i);
    }
    vector<ll>ans;
    while (q.size()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int ne:adj[node]){
            if(--inDegrees[ne]==0) q.push(ne);
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}