#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define Ad22Hc15 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define ll  long long
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORIn(i,a,b) for(ll i=a;i<=b;i++)
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<ll> vll;
typedef vector<int> vii;

int main(){
    Ad22Hc15;
    ll st,end,newMod=1e5;
    cin>>st>>end;
    vector<int>arr;
    FOR(i,0,arr.size()){
        int num;
        cin>>num;
        arr.pb(num);
    }
    vector<int>stepsArr(99999,INT_MAX);
    stepsArr[st]=0;
    queue<pii>q;
    q.push({0,st});
    while(!q.empty()){
        int steps=q.front().fi;
        int num=q.front().se;
        if(num==end){
            cout<<steps<<"\n";
            break;
        }
        q.pop();
        for(auto n:arr){
            num=(num%newMod*n%newMod)%newMod;
            if(stepsArr[num]>steps+1){
                stepsArr[num]=steps+1;
                q.push({steps+1,num});
            }
        }
    }
    if(stepsArr[end]==INT_MAX) cout<<"-1"<<"\n";
    else cout<<stepsArr[end];
}
//T.C:O(99999*N)