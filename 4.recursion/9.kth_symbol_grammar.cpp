#include<iostream>
#include<math.h>
using namespace std;

int solve(int n,int k){
    int mid=pow(2,n-1)/2;
    if (n==1&&k==1){
        return 0;
    }
    if (k<=mid){
      return solve(n-1,k);
    }
    else{
        return !(solve(n-1,k-mid));
    }
}
int main(){
    int n=4,k=3;
    int result=solve(n,k);
    cout<<result;
}