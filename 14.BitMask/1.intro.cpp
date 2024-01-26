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

int main(){
    Ad22Hc15;
    ll a=5,b=10;
    cout<<(a&b)<<"\n";//AND
    cout<<(a|b)<<"\n";//OR
    cout<<(a^b)<<"\n";//XOR
    cout<<(~a)<<"\n";//NOT
    cout<<(a<<1)<<"\n";//Left Shift
    cout<<(a>>1)<<"\n";//Right Shift
}
//T.C:O(1), for every bit wise operator
//LEFT SHIFT OPERATOR(<<)
//Shifts the bits towards left by 1 (multiplies the no. by 2).
//If the number is positive, then 0 is added at the end.
//If the number is negative, then 1 is added at the end.
//a<<2 -> left shifts the bit by 2 bits.
// in general for a<<b, this multiplies 'a' with 2^b
// 1<<n=2^n 
//ex: 000001110 -> 000011100

//RIGHT SHIFT OPERATOR(>>)
//Shifts the bits towards right by 1 (divides the no. by 2).
//If the number is positive, then 0 is added at the start.
//If the number is negative, then 1 is added at the start.
// in general for a>>b, this divides 'a' with 2^b
//ex: 000001110 -> 000000111

//5=0000101
//5<<1 = 0001010 = 10