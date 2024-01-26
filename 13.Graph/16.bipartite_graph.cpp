//bipartite graph: a graph whose nodes can be colored such that no 2 adjacent have same color. All acyclic graphs are bipartite and cyclic graphs with even cycle length is also bipartite.
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

bool BFS(int s,vector<int>&c,vector<vector<int>>&a){
    queue<int>q;
    q.push(s);
    c[s]=0;
    while(!q.empty()){
        int parent=q.front();
        q.pop();
        for (auto &curr : a[parent]){
            // the node is not colored
            if (c[curr]==-1){
                q.push(curr);
                //coloring it with the opposite color
                c[curr]=!c[parent];
            }
            //node is colored and has same color as of the parent(adj. node) 
            else if (c[curr]==c[parent]){
                return false;
            }
        }
    }
    return true;
}
bool DFS(int s, int col,vector<int>&c,vector<vector<int>>&a){
    c[s]=col;
    for(auto &curr : a[s]){
        if(c[curr]==-1){
            DFS(curr,!col,c,a);
        } else if (c[curr]==col){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0; i<m; i++){
       int x,y;
       cin>>x>>y;
       adj[x].pb(y);
       adj[y].pb(x);
    }
    int flag=0;
    vector<int>color(n+1,-1);
    for (int i=1; i<=n; i++){
        if (color[i]==-1){
            if(DFS(i,0,color,adj)==false){
                cout<<"Not Bipartite";
                flag=1;
                break;
            }
        }
    }
    if (flag==0){
        cout<<"Bipartite";
    }
    // if (BFS(1,color,adj)) cout<<"Bipartite";
    // else cout<<"Not Bipartite";
}