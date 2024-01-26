//visit all O's which are connected to a boundary O and mark them visited, to chk O's which should be converted to X just chk whether at their pos. in visited matrix whether there is O or not if yes then these O has to be converted to X.
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
#define print(arr,n) for(int i=0;i<n;i++)cout<<arr[i]
#define scan(arr,n) for(int i=0;i<n;i++)cin>>arr[i]

//only for BFS implementation
void BFS(vector<vector<char>>&a,vector<vector<int>>&v){
    queue<pair<int,int>>q;
    int n=a.size(),m=a[0].size();
    //pushing all the boundary O into the queue
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (i==0||j==0||i==n-1||j==m-1){
                if(a[i][j]=='O'){
                    q.push({i,j});
                    v[i][j]=1;
                }
            }   
        }
    }
    int xD[]={-1,0,1,0};
    int yD[]={0,1,0,-1};

    //this loop marks all the O's connected to boundary O as visited.
    while(!q.empty()){
        pair<int,int>t=q.front();
        q.pop();
        int x=t.first,y=t.second;
        for(int i=0; i<4; i++){
            int x1=x+xD[i];
            int y1=y+yD[i];
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&a[x1][y1]=='O'&&v[x1][y1]!=1){
                q.push({x1,y1});
                v[x1][y1]=1;
            }
        }
    }
    // this loop marks all the O's as X which r not connected to the boundary zero.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (a[i][j]=='O'&&v[i][j]!=1){
                a[i][j]='X';
            }
        }
    }
}

//only for DFS implementation
void DFS(pair<int,int>p,vector<vector<int>>&v,vector<vector<char>>&a){
    int xD[]={-1,0,1,0};
    int yD[]={0,1,0,-1};
    int x=p.first,y=p.second;
    v[x][y]=1;
    for(int i=0; i<4; i++){
        int x1=x+xD[i];
        int y1=y+yD[i];
        if(x1>=0&&x1<a.size()&&y1>=0&&y1<a[0].size()&&a[x1][y1]=='O'&&v[x1][y1]!=1){
            DFS({x1,y1},v,a);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<char>>ans;
    for(int i=0; i<n; i++){
        vector<char>temp;
        for(int j=0; j<m; j++){
            char x;
            cin>>x;
            temp.pb(x);
        }
        ans.pb(temp);
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
   // BFS(ans,vis);

   //*** DFS ***
   for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (i==0||j==0||i==n-1||j==m-1){
                if(ans[i][j]=='O'){
                    DFS({i,j},vis,ans);
                }
            }
        }
    }
    // this loop marks all the O's as X which r not connected to the boundary zero.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (ans[i][j]=='O'&&vis[i][j]!=1){
                ans[i][j]='X';
            }
        }
    }
    //*** end of DFS part ***
    cout<<"\n";

    //printing the modified grid
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}