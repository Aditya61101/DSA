//it won't work for negative weights as for every traversal we will have a dist+wt which will be smaller than curr distance as the distance goes on reducing due to the neg. weight, which means every time, we will be pushing something. So the queue will never be empty and it will run forever.

//Dijkstra's algo using priority queue
//PQ is better than queue because through PQ we can reach to a node in a greedy way i.e we can reach it through min. distance as PQ is sorted a/distance. But if all the weights are same then it doesn't matter whether we use PQ or queue.
#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<pii>>adj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
    }
    vector<int>dist(n,1e9);
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    int src=0;
    dist[src]=0;
    pq.emplace(0,src);
    while(pq.size()){
        auto[d,u]=pq.top();
        pq.pop();
        for(auto [v,w]:adj[u]){
            if(dist[v]>d+w) {
                dist[v]=d+w;
                pq.emplace(dist[v],v);
            }
        }
    }
    for(int d:dist) cout<<d<<" ";
}
//T.C: O(M*logN)