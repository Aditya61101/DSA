#include<bits/stdc++.h>
#include<unordered_set>
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
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORIn(i,a,b) for(ll i=a;i<=b;i++)
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

ll inv(ll i) {if (i == 1) return 1; return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;}
ll modMul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
ll modAdd(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) {a %= MOD; ll res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}

int solve(string s,string e, vector<string>w){
    queue<pair<string,int>>q;
    q.push({s,1});
    unordered_set<string>vis(w.begin(),w.end());
    vis.erase(s);
    while(!q.empty()){
        pair<string,int>p=q.front();
        string word=p.fi;
        int steps=p.se;
        q.pop();
        FOR(i,0,word.size()){
            //taking one char at a time
            char ch=word[i];
            FOR(j,0,26){
                //replacing it with a-z
                word[i]='a'+j;
                //if the modified word is equal to the end word then we return the currentSteps+1
                if(word==e) return steps+1;
                //searching the new word in the set
                if(vis.find(word)!=vis.end()){
                    vis.erase(word);
                    q.push({word,steps+1});
                }
            }
            //retrieving the original word by replacing the replaced letter with ch
            word[i]=ch;
        }
    }
    return 0;
}
int main(){
    Ad22Hc15;
    string begin,end;
    cin>>begin>>end;
    vector<string>wordList;
    FOR(i,0,wordList.size()){
        string s;
        cin>>s;
        wordList.pb(s);
    }
    cout<<solve(begin,end,wordList);
}
//T.C: N*word.length*26*logN