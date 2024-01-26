//we will start in 2 different direction but at any pt. of time if we meet at same position, then this will be only due to presence of a cycle in the undirected graph.
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define fi first
#define se second

void BFS(vector<vector<int>>&a,vector<int>&v,int s){
    queue<pair<int,int>>q;
    q.push({s,0});
    v[s]=1;
    while(!q.empty()){
        pair<int,int>t=q.front();
        q.pop();
        int curr=t.fi,parent=t.se,i=0;
        while(i!=a[curr].size()){
            if (v[a[curr][i]]!=1){
                q.push({a[curr][i],curr});
                v[a[curr][i]]=1;
            }
            // if someone is visited and the current node didn't come from that visited node this means that visited node is already visited from a diff. node. This will only happen when there is a cycle, since from a node, we always move in diff. directions. 
            else if (a[curr][i]!=parent){
                cout<<"Cycle is present";
                return;
            }
            i++;
        }
    }
    cout<<"No cycle is present!!";
}
int main(){
    //n->nodes, m->edges
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x); 
    }
    vector<int>vis(n+1,0);
    BFS(adj,vis,1);
}
//T.C:O(N+2*E)+O(N)
//S.C:O(N)+O(N)