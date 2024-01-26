#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        // for unweighted graph
        adj[a][b]=1;
        adj[b][a]=1;
        //for weighted w,
        //adj[a][b]=w;
        //adj[b][a]=w;
    }
}