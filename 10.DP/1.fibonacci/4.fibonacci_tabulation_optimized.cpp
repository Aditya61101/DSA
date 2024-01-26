#include<iostream>
#include<vector>
using namespace std;

int printFibonacci(int n){
    int prev2=0,prev=1,curr;
    for (int i = 2; i < n+1; i++){
        curr=prev2+prev;
        prev=curr;
        prev2=prev;
    }
    return curr;
}
int main(){
    int n;
    cin>>n;
    int result=printFibonacci(n);
    cout<<result;
}