#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define Ad22Hc15 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define INF 1000000000000000005
#define ll  long long
#define fi first
#define se second
#define pb push_back
#define for(i,a,b) for(i=a;i<b;i++)
#define forI(i,a,b) for(i=a;i<=b;i++)
typedef pair<ll, ll> pll;

ll inv(ll i) {if (i == 1) return 1; return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;}
ll modMul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
ll modAdd(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) {a %= MOD; ll res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}

//assuming a is before b in the vector v
bool compare(ll a, ll b){
    //if we want the v to be sorted in descending order, as a is greater than b and it comes before b(assumption) this means this pair of element is already sorted in descending order, so we return true.
    if(a>=b) return true;
    else return false;
}
int main(){
    Ad22Hc15;
    vector<ll>v={2,-1,3,4,0,10,8};
    sort(v.begin(), v.end(), compare);
}
/* bool compare(pair<ll,ll>p1,pair<ll,ll>p2){
    if(2*p1.fi+p1.se>=2*p2.fi+p2.se) return true;
    else return false;
}
bool sortAccSe(pair<ll,ll>p1,pair<ll,ll>p2){
    * sorts in ascending order acc. to the second element of the pair *
    if(p1.se<=p2.se) return true;
    else return false;
}
int main(){
    Ad22Hc15;
    vector<pair<ll,ll>>v={{2,1},{-1,2},{3,3},{4,4},{0,5},{10,6},{8,7}};
    sort(v.begin(), v.end(), compare);
    sort(v.begin(), v.end(), sortAccSe);
}
*/