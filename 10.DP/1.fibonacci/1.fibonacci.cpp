#include<iostream>
using namespace std;

int solve(int n){
    if(n==0||n==1)
        return n;
    int num=solve(n-1)+solve(n-2);
    return num;
}
int main(){
    int n;
    cin>>n;
    int result = solve(n);
    cout<<result;
}