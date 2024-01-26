#include<iostream>
using namespace std;

int printSum(int n){
    if (n==1){
        return 1;
    }
    int sum=n+printSum(n-1);
    return sum;
}
int main(){
    int n=5;
    int result=printSum(n);
    cout<<result;
}