/*Given a grid of dimension nXm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. */

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define fi first
#define se second

void BFS(vector<vector<int>>&adj,vector<vector<int>>&vis){
    int time=0;
    int r=adj.size(),c=adj[0].size();
    //queue to store visited coordinate with time taken to visit the rotten orange
    queue<pair<pair<int,int>,int>>q;
    //to store already rotten oranges in the queue, as they all will start rotting fresh oranges simultaneously.
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if(adj[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
            }
        }
    }
    // to travel in all the 4 directions
    int xVary[]={-1,0,1,0};
    int yVary[]={0,-1,0,1};
    while(!q.empty()){
        pair<pair<int,int>,int>temp=q.front();
        int x=temp.fi.fi,y=temp.fi.se,t=temp.se;
        time=max(time,t);
        q.pop();
        for (int i=0; i<4; i++){
            int x1=x+xVary[i],y1=y+yVary[i];
            //adj[x1][y1]==1 means there is a fresh orange and vis[x1][y1]==0 means it hasn't been visited
            if (x1>=0&&x1<c&&y1>=0&&y1<r&&adj[x1][y1]==1&&vis[x1][y1]==0){
                vis[x1][y1]=2; // rot that orange in vis array
                q.push({{x1,y1},t+1});
            }
        }
    }
    // to see all the fresh oranges have been rotten
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (adj[i][j]==1&&vis[i][j]!=2){
                cout<<-1<<"\n";
                return;
            }
        }
    }
    cout<<time<<"\n";
}
int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>>adj(r,vector<int>(c,0));
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin>>adj[i][j];
        }
    }
    vector<vector<int>>vis(r,vector<int>(c,0));
    BFS(adj,vis);
}
//S.C:n*m
//t.c:n*m+4*n*m