#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define ll  long long
#define fi first
#define se second
#define pb push_back
#define print(arr,n) for(int i=0;i<n;i++)cout<<arr[i]<<
#define scan(arr,n) for(int i=0;i<n;i++)cin>>arr[i]

void BFS(pair<int,int>p,vector<vector<int>>&a, vector<vector<int>>&v,set<vector<pair<int,int>>>&s){
    vector<pair<int,int>>li;
    li.pb({0,0});
    int n=a.size(),m=a[0].size();
    queue<pair<int,int>>q;
    q.push(p);
    v[p.first][p.second]=1;
    int xD[]={-1,0,1,0};
    int yD[]={0,-1,0,1};
    while(!q.empty()){
        pair<int,int>t=q.front();
        int x=t.first,y=t.second;
        q.pop();
        for (int i=0; i<4; i++){
            int x1=x+xD[i],y1=y+yD[i];
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&a[x1][y1]==1&&v[x1][y1]!=1){
                q.push({x1,y1});
                v[x1][y1]=1;
                li.pb({abs(x1-p.first),abs(y1-p.second)});
            }
        }
    }
    s.insert(li);
}
void DFS(pair<int,int>p,vector<vector<int>>&a, vector<vector<int>>&v, vector<pair<int,int>>&li){
    int x=p.fi,y=p.se;
    v[x][y]=1;
    int xD[]={-1,0,1,0};
    int yD[]={0,-1,0,1};
    for(int i=0; i<4; i++){
        int x1=x+xD[i],y1=y+yD[i];
        if(x1>=0&&x1<a.size()&&y1>=0&&y1<a[0].size()&&a[x1][y1]==1&&v[x1][y1]!=1){
            DFS({x1,y1},a,v,li);
            v[x1][y1]=1;
            li.pb({abs(x1-p.first),abs(y1-p.second)});
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj;
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            temp.pb(x);
        }
        adj.pb(temp);
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>>s;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         if (adj[i][j]==1&&vis[i][j]==0){
    //             BFS({i,j},adj,vis,s);
    //         }
    //     }
    // }
    // DFS
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (adj[i][j]==1&&vis[i][j]==0){
                vector<pair<int,int>>li;
                DFS({i,j},adj,vis,li);
                s.insert(li);
            }
        }
    }
    // for(auto &&v : s){
    //    for(auto &&p : v){
    //           cout<<p.first<<" "<<p.second<<" "; 
    //    }
    //    cout<<"\n";
    // }
    cout<<s.size()<<"\n";
}