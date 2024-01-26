#include<iostream>
#include<vector>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define pb push_back

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adjM(n+1,vector<int>(n+1,0));
    vector<vector<int>>adjL(n+1);
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < n+1; j++){
            if (adjM[i][j]==1&&i!=j){
                adjL[i].pb(j);
                adjL[j].pb(i);
            }
        }
    }
}