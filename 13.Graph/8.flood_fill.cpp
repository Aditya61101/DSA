/* Given a 2D screen adj[][] where each adj[i][j] is an integer representing the color of that pixel, also given the location of a pixel (x,y) and a color C, the task is to replace the color of the given pixel and all the adjacent same-colored pixels with the given color.*/

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define fi first
#define se second
#define vll vector<int>

void BFS(pair<int,int>s,int sC,int C,vector<vll>&v){
    queue<pair<int,int>>q;
    q.push(s);
    while(!q.empty()){
        pair<int,int>t=q.front();
        int x=t.fi,y=t.se;
        q.pop();
        v[x][y]=C;
        int dr[] = {0,-1,1,0};
        int dc[] = {-1,0,0,1};
        for(int i=0;i<4;i++){
            int ri=x+dr[i],ci=y+dc[i];
            if(ri>=0&&ri<(int)v.size()&&ci>=0&&ci<(int)v[0].size()&&v[ri][ci]==sC){
                q.push({ri,ci});
            }
        }
    }
}
void DFS(pair<int,int>s,int sC,int nC,vector<vll>&v){
    v[s.fi][s.se]=nC;
    int x=s.fi,y=s.se;
    int dr[] = {0,-1,1,0};
    int dc[] = {-1,0,0,1};
    for(int i=0;i<4;i++){
        int ri=x+dr[i],ci=y+dc[i];
        if(ri>=0&&ri<(int)v.size()&&ci>=0&&ci<(int)v[0].size()&&v[ri][ci]==sC){
            DFS({ri,ci},sC,nC,v);
        }
    }
}
int main(){
    int n,m,x,y,C;
    cin>>n>>m>>x>>y>>C;
    vector<vll>adj(n,vll(m,0));
    
    for(int i=0; i<n; i++){
        for(int j=0;j<m;j++)
            cin>>adj[i][j];
    }
    int sColor=adj[x][y];
    vector<vll>vis=adj;
    BFS({x,y},sColor,C,vis);
    // DFS({sr,sc},sColor,nc,vis);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vis[i][j]<<" ";
        }
        cout<<"\n";
    }
}
//T.C:(n*m)+4*(n*m)
//S.C:(n*m)+(n*m)