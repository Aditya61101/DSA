#include<iostream>
using namespace std;
#define int long long int

int solve(int n){
    //if n==0, then we have reached our destination so this path was a correct path hence returned as 1.
    if(n==0)
        return 1;
    int climb1=solve(n-1);
    int climb2=0;
    if(n>=2)
        climb2=solve(n-2);
    //in case of counting, we return sum of all possible ways
    return climb1+climb2;
}
signed main(){
    int n;
    cin>>n;
    int result=solve(n);
    cout<<result;
}