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

vector<vector<string>>solve(string b,string e,vector<string>&w){
    unordered_set<string>words(w.begin(),w.end());
    int lvl=0;
    vector<string>used_lvl;
    vector<vector<string>>ans;
    vector<string>v;
    queue<vector<string>>q;
    words.erase(b);
    v.pb({b});
    used_lvl.pb({b});
    q.push(v);
    while(!q.empty()){
        vector<string>v=q.front();
        string word=v.back();
        if(v.size()>lvl){
            lvl++;
            for(auto w:used_lvl) words.erase(w);
        }
        if(word==e){
            if(ans.size()==0) ans.pb(v);
            else if(ans[0].size()==v.size()) ans.pb(v);
        }
        FOR(i,0,word.size()){
            char ch=word[i];
            FOR(j,0,26){
                word[i]='a'+j;
                if(words.count(word)>0){
                    v.pb(word);
                    q.push(v);
                    used_lvl.pb(word);
                    v.pop_back();
                }
            }
            word[i]=ch;
        }
    }
    return ans;
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
    vector<vector<string>>ans=solve(begin,end,wordList);
    for(auto words:ans){
        for(auto word:words) cout<<word<<" ";
        cout<<"\n";
    }
}