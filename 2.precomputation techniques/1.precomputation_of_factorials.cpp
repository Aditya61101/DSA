#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
const int N =1e5+10;

ll fact[N];
int main(){
    fact[0]=fact[1]=1;
    //pre computation of factorials
    for(int i=2; i<N; i++){
        fact[i]=(fact[i-1]%MOD*i%MOD)%MOD;
    }
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<fact[n]<<endl;
    }
}
//time complexity: O(N)+O(t)~=O(N)